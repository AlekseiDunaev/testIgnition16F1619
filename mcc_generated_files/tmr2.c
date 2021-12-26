/**
  TMR2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr2.c

  @Summary
    This is the generated driver implementation file for the TMR2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR2.
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
#include "tmr2.h"
#include "mcc.h"

/**
  Section: Global Variables Definitions
*/

void (*TMR2_InterruptHandler)(void);

/**
  Section: TMR2 APIs
*/

void TMR2_Initialize(void)
{
    // Set TMR2 to the options selected in the User Interface

    // T2CS FOSC/4; 
    T2CLKCON = 0x00;

    // T2PSYNC Not Synchronized; T2MODE Software control; T2CKPOL Rising Edge; T2CKSYNC Not Synchronized; 
    T2HLT = 0x00;

    // T2RSEL T2IN; 
    T2RST = 0x00;

    // T2PR 119; 
    T2PR = 0x77;

    // TMR2 0; 
    T2TMR = 0x00;

    // Clearing IF flag before enabling the interrupt.
    PIR1bits.TMR2IF = 0;

    // Enabling TMR2 interrupt.
    PIE1bits.TMR2IE = 1;

    // Set Default Interrupt Handler
    TMR2_SetInterruptHandler(TMR2_DefaultInterruptHandler);

    // T2CKPS 1:2; T2OUTPS 1:1; TMR2ON on; 
    T2CON = 0x90;
}

/*
void TMR2_ModeSet(TMR2_HLT_MODE mode)
{
   // Configure different types HLT mode
    T2HLTbits.MODE = mode;
}
*/

/*
void TMR2_ExtResetSourceSet(TMR2_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T2RSTbits.RSEL = reset;
}
*/

/*
void TMR2_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}
*/

/*
void TMR2_StartTimer(void)
{
    TMR2_Start();
}
*/

/*
void TMR2_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}
*/

/*
void TMR2_StopTimer(void)
{
    TMR2_Stop();
}
*/

/*
uint8_t TMR2_Counter8BitGet(void)
{
    uint8_t readVal;

    readVal = TMR2;

    return readVal;
}
*/

/*
uint8_t TMR2_ReadTimer(void)
{
    return TMR2_Counter8BitGet();
}
*/

/*
void TMR2_Counter8BitSet(uint8_t timerVal)
{
    // Write to the Timer2 register
    TMR2 = timerVal;
}
*/

/*
void TMR2_WriteTimer(uint8_t timerVal)
{
    TMR2_Counter8BitSet(timerVal);
}
*/

/*
void TMR2_Period8BitSet(uint8_t periodVal)
{
   PR2 = periodVal;
}
*/

/*
void TMR2_LoadPeriodRegister(uint8_t periodVal)
{
   TMR2_Period8BitSet(periodVal);
}
*/

void TMR2_ISR(void)
{

    // clear the TMR2 interrupt flag
    PIR1bits.TMR2IF = 0;

    if(TMR2_InterruptHandler)
    {
        TMR2_InterruptHandler();
    }
}


void TMR2_SetInterruptHandler(void (* InterruptHandler)(void)){
    TMR2_InterruptHandler = InterruptHandler;
}

void TMR2_DefaultInterruptHandler(void){
    // add your TMR2 interrupt custom code
    // or set custom function using TMR2_SetInterruptHandler()
    //DEBUG_INT_TIM2_Toggle();

    if (HALL_INPUT_GetValue() != Port.SENS) {
        if ((++countHALL) == COUNT_HALL_ENOUGHT) {
            Port.SENS = !Port.SENS;
            countHALL = 0;
        }
    } else {
        countHALL = 0;
    }
          
    if (Port.SENS) {
        //Если шторка в датчике 
        if (!Flag.lastState) {
        
            //Если перед этим шторка была не в датчике
            //Шторка вошла в датчик
            if (!Flag.engineStop && !Flag.overrun1 && Flag.overrun2) {
                //Если двигатель не остановлен
                //Если нет ограничения оборотов по функции 1
                //Если нет ограничения оборотов по функции 2
                //Включаем катушку зажигания
                IGN_BLOCK_OUT_SetHigh();
            }
            //Сохраняем счетчик оборотов
            //lastSectionCount = sectorCount;
            sectorCountContinued = 0;
            sectorCount = 0;
            //Обновляем сотояние нахождения шторки
            Flag.lastState = true;
            //Сбрасываем флаг переполнения
            Flag.overflowCount = false;
            //Обнуляем счетчик отключения катушки
            //Нигде не используется
            //coilOffCount &= 0x0F;
            //Снимаем флаг отключения катушки. Двигатель работает.
            Flag.coilOff = false;
            return;

        } else {
            
            //Шторка находится по прежнему в датчике
            LED_SHADOW_SetLow(); //Включаем светодиод
            //Если счетчик переполнен, не проверяем его на момент искрообразования
            
            if (Flag.overflowCount) {
                sectorCountContinued++;
                return;
            } else {
                sectorCount++; //Увеличиваем значение счетчика срабатывания таймера
                sectorCountContinued++;

                if (sectorCount >= 239) { //Проверяем счетчик на перполнение
                    Flag.overflowCount = true;
                }

                if (!sparkTime) { //Проверяем счетчик на момент искрообразования, если он равен нулю (т.е. при запуске))
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
        Flag.lastState = false;
        coilCount = 0;

        if (sparkTime == 0) {
            coilCount = sectorCount + 239;
        }
        else {
            coilCount = sectorCount + sparkTime;
        }
        sparkTime = shiftIgnMassive[(uint8_t)sectorCount];
        currentSectorCount = sectorCountContinued;
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