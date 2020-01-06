/**
  TMR1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated driver implementation file for the TMR1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F1619
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "tmr1.h"
#include "mcc.h"

/**
  Section: Global Variables Definitions
*/
volatile uint16_t timer1ReloadVal;
void (*TMR1_InterruptHandler)(void);
//uint16_t shift;//Индекс в массиве значений отсчетов до зажигания

/**
  Section: TMR1 APIs
*/

void TMR1_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T1GSS T1G_pin; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO_nDONE done; T1GSPM disabled; 
    T1GCON = 0x00;

    //TMR1H 21; 
    TMR1H = 0x15;

    //TMR1L 240; 
    TMR1L = 0xF0;

    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR1IF = 0;

    // Enabling TMR1 interrupt.
    PIE1bits.TMR1IE = 1;

    // Set Default Interrupt Handler
    TMR1_SetInterruptHandler(TMR1_DefaultInterruptHandler);

    // T1CKPS 1:4; nT1SYNC synchronize; TMR1CS FOSC/4; TMR1ON enabled; 
    T1CON = 0x21;
}

void TMR1_StartTimer(void)
{
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR1_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}

uint16_t TMR1_ReadTimer(void)
{
    uint16_t readVal;
    uint8_t readValHigh;
    uint8_t readValLow;
    
	
    readValLow = TMR1L;
    readValHigh = TMR1H;
    
    readVal = ((uint16_t)readValHigh << 8) | readValLow;

    return readVal;
}

void TMR1_WriteTimer(uint16_t timerVal)
{
    if (T1CONbits.nT1SYNC == 1)
    {
        // Stop the Timer by writing to TMRxON bit
        T1CONbits.TMR1ON = 0;

        // Write to the Timer1 register
        TMR1H = (timerVal >> 8);
        TMR1L = timerVal;

        // Start the Timer after writing to the register
        T1CONbits.TMR1ON =1;
    }
    else
    {
        // Write to the Timer1 register
        TMR1H = (timerVal >> 8);
        TMR1L = timerVal;
    }
}

void TMR1_Reload(void)
{
    TMR1_WriteTimer(timer1ReloadVal);
}

void TMR1_StartSinglePulseAcquisition(void)
{
    T1GCONbits.T1GGO_nDONE = 1;
}

uint8_t TMR1_CheckGateValueStatus(void)
{
    return (T1GCONbits.T1GVAL);
}

void TMR1_ISR(void)
{

    // Clear the TMR1 interrupt flag
    PIR1bits.TMR1IF = 0;
    TMR1_WriteTimer(timer1ReloadVal);

    if(TMR1_InterruptHandler)
    {
        TMR1_InterruptHandler();
    }
}


void TMR1_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR1_InterruptHandler = InterruptHandler;
}

void TMR1_DefaultInterruptHandler(void){
    // add your TMR1 interrupt custom code
    // or set custom function using TMR1_SetInterruptHandler()
    DEBUG_INT_TIM1_Toggle();
    
    if (HALL_INPUT_GetValue() == Port.SENS) {
        countHALL = 0;
    } else {
        countHALL++;        
        if (countHALL == countHallEnought) {
            Port.SENS = !Port.SENS;
            countHALL = 0;
        }
    }
    
    if (Port.SENS) {
        //Если шторка в датчике 
        if (!Flag.lastState) { 
            //Если перед этим шторка была не в датчике
            //Шторка вошла в датчик
            if (!Flag.engineStop && !Flag.overrun1 && Flag.overrun2) {
                //Если двигатель не остановлен
                //Если нет ограничения оборотов по функции 1
                //Если нет отграниченияоборотов по функции 2
                //Включаем катушку зажигания
                IGN_BLOCK_OUT_SetHigh();
            } 
            //Сохраняем счетчик оборотов
            lastSectionCount = sectorCount;
            sectorCount = 0;
            //Обновляем сотояние нахождения шторки
            Flag.lastState = 1;
            //Сбрасываем флаг переполнения
            Flag.overflowCount = 0;
            //Обнуляем счетчик отключения катушки
            coilOffCount &= 0x0F;
            //Снимаем флаг отключения катушки. Двигатель работает.
            Flag.coilOff = 0;
            return;
            
        } else {
            //Шторка находится по прежнему в датчике
            LED_SHADOW_SetLow();//Включаем светодиод
            //Если счетчик переполнен, не проверяем его на момент искрообразования
            if (Flag.overflowCount) {
                return;
            } else {
                sectorCount++; //Увеличиваем значение счетчика срабатывания таймера
                
                if (sectorCount >= 239) { //Проверяем счетчик на перполнение
                    Flag.overflowCount = 1;
                }
                
                if (!sparkTime) { //Проверяем счетчик на момент искрообразования, если он не равен нулю (т.е. при запуске))
                    return; //Происходит запуск, искра будет образована при выходе шторки из датчика
                }
                
                if (sectorCount == sparkTime) {//Если кол-во отсчетов с начала захода шторки в датчик совпадает с расчетным, то инициализируем искру
                    IGN_BLOCK_OUT_SetLow();
                }
                
                return;
            }
        }
        
    } else if (Flag.lastState) {
        //Шторка вышла из сенсора
        IGN_BLOCK_OUT_SetLow(); //Инициализируем искру, если этого еще не произошло (запуск).
        Flag.lastState = 0;
        coilCount = 0;
        
        if (sparkTime == 0) {
            coilCount = sectorCount + 239;
            //shift = sectorCount + 239;
            //coilCount = shift;
        } else {
            coilCount = sectorCount + sparkTime;
            //shift = sectorCount + sparkTime;
            //coilCount = shift;
        }
        
        sparkTime = shiftIgnMassive[(uint8_t)coilCount];
        return;
        
    } else {
        //Шторка по прежнему вне сенсора
        LED_SHADOW_SetHigh();
        if (!(--coilCount)) {
            if (Flag.engineStop || Flag.coilOff || Flag.overrun1 || Flag.overrun2) {
                return;
            }
            IGN_BLOCK_OUT_SetHigh();
        }
    }
}

/**
  End of File
*/
