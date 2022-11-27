/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F1619
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
 Global variable 
*/
uint16_t color;
//char RPMtoStr[] = {'0', '0', '0', '0', '\0'};

 // TODO Insert declarations
/*
    Main application
 */

void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    
    //Это может быть опасным?
    //Если по каким то причинам катушка была по каким то причинам под напряжением перед этим, то проскочит искра. И если в цилиндре будет смесь, то произойдет рабочий ход.
    //Нужно проверить в каком состоянии находится катушка при запуске системы.
    IGN_BLOCK_OUT_SetLow();
    LED_SHADOW_SetLow();
    Flag.lastState = false;
    
    Port.SELECT1 = SELECT1_IN_GetValue();
    Port.SELECT2 = SELECT2_IN_GetValue();
    Port.FUNC1 = FUNC1_IN_GetValue();
    //Port.FUNC2 = FUNC2_IN_GetValue();
         
    if (Port.FUNC1) Flag.engineStop = true;
    
    if (HALL_INPUT_GetValue()) {
       LED_SHADOW_SetHigh();
       Flag.lastState = true;
       if (!Flag.engineStop) {
        IGN_BLOCK_OUT_SetHigh();
       }
    }

#ifndef SOFT
    SCREEN_Fill(0x0000);
#endif
    
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    while (1) {

        if (SELECT1_IN_GetValue() != Port.SELECT1) {
            if ((++countSELECT1) == COUNT_BUTTON_ENOUGHT) {
                Port.SELECT1 = !Port.SELECT1;
                countSELECT1 = 0;
            }
        } else {
            countSELECT1 = 0;
        }

        if (SELECT2_IN_GetValue() != Port.SELECT2) {
            if ((++countSELECT2) == COUNT_BUTTON_ENOUGHT) {
                Port.SELECT2 = !Port.SELECT2;
                countSELECT2 = 0;
            }
        } else {
            countSELECT2 = 0;
        }

        if (FUNC1_IN_GetValue() != Port.FUNC1) {
            if ((++countFUNC1) == COUNT_BUTTON_ENOUGHT) {
                Port.FUNC1 = !Port.FUNC1;
                countFUNC1 = 0;
            }
        } else {
            countFUNC1 = 0;
        }

        if (FUNC2_IN_GetValue() != Port.FUNC2) {
            if ((++countFUNC2) == COUNT_BUTTON_ENOUGHT) {
                Port.FUNC2 = !Port.FUNC2;
                countFUNC2 = 0;
            }
        } else {
            countFUNC2 = 0;
        }
        
        if (paint) {
            RPM_BCD = toPackedBcd(RPM = (RPM_COEFFICIENT / currentSectorCount) * 10);
            //atoi_project(RPM = 10 * (RPM_COEFFICIENT / currentSectorCount), RPMtoStr);
        }
        else {
            RPM_BCD = 0;
            //atoi_project(RPM = 0, RPMtoStr);
        }
        
        paint = false;
        
        barsPaint = coefficientLenghtBar * (RPM / 100);
        if (barsPaint > RPMDangerosLenghtBar) {
            color = 0xF800;
        } else {
            color = 0xFFFF;
        }

  #ifndef SOFT      

        SCREEN_Putchar(90, 80, (uint8_t)(RPM_BCD>>12) + '0', color, 0x0000);
        SCREEN_Putchar(104, 80, (uint8_t)((RPM_BCD & 0x0F00)>>8) + '0', color, 0x0000);
        SCREEN_Putchar(118, 80, (uint8_t)((RPM_BCD & 0x00F0)>>4) + '0', color, 0x0000);
        SCREEN_Putchar(132, 80, (uint8_t)(RPM_BCD & 0x000F) + '0', color, 0x0000);
        
        int16_t diffBars = barsPaint - lastBarsPaint;
        
        direction = 1;
        
        if (diffBars < 0) {
            color = 0x0000;
            diffBars *= -1;
            direction = -1;
        }
        
        for (int16_t i = 0; i < diffBars; i++) {
            uint16_t next = (uint16_t)(lastBarsPaint +(direction * i));
            SCREEN_DrawBox(next, UPPER_BAR_CORNER, next + 1 , LOWER_BAR_CORNER, color);    
        }

        lastBarsPaint = barsPaint;

#endif
    }       
}
/**
 End of File
*/