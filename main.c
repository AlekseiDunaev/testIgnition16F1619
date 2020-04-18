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


 // TODO Insert declarations
/*
    Main application
 */

void main(void) {
    // initialize the device
    SYSTEM_Initialize();
        
    //countSELECT1 = countSELECT2 = countFUNC1 = countFUNC2 = countHALL = 0;
    
    Port.SELECT1 = SELECT1_IN_GetValue();
    Port.SELECT2 = SELECT2_IN_GetValue();
    Port.FUNC1 = FUNC1_IN_GetValue();
    //Port.FUNC2 = FUNC2_IN_GetValue();
         
    if (Port.FUNC1) {
        Flag.engineStop = 1;    
    } else {
        Flag.engineStop = 0;
    }
    
    if (HALL_INPUT_GetValue()) {
       LED_SHADOW_SetHigh();
       Flag.lastState = 1;
       if (!Flag.engineStop) {
        IGN_BLOCK_OUT_SetHigh();
       }
    } else {
        LED_SHADOW_SetLow();
        Flag.lastState = 0;
        IGN_BLOCK_OUT_SetLow();
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
        
#ifndef SOFT
#ifdef TEST
        temp = current * SEC_PER_MIN;
        tempDiv10 = temp / 10;
        tempDiv100 = temp / 100;
        tempDiv1000 = temp / 1000;
        SCREEN_Putchar(90, 10, tempDiv1000);
        SCREEN_Putchar(105, 10, tempDiv100 - 10*(tempDiv1000));
        SCREEN_Putchar(120, 10, tempDiv10 - 10*(tempDiv100));
        SCREEN_Putchar(135, 10, temp - 10*(tempDiv10));
        //sprintf(buff, "%4d", current * SEC_PER_MIN);
        //SCREEN_DrawString(90, 10, buff);
#else
        temp = current * RPM_COEFFICIENT;
        tempDiv10 = temp / 10;
        tempDiv100 = temp / 100;
        tempDiv1000 = temp / 1000;
        SCREEN_Putchar(90, 10, tempDiv1000);
        SCREEN_Putchar(105, 10, tempDiv100 - 10*(tempDiv1000));
        SCREEN_Putchar(120, 10, tempDiv10 - 10*(tempDiv100));
        SCREEN_Putchar(135, 10, temp - 10*(tempDiv10));
        //sprintf(buff, "%4d", current * RPM_COEFFICIENT);
        //SCREEN_DrawString(90, 10, buff);
#endif
#endif
    }       
}
/**
 End of File
*/