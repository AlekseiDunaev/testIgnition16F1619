/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set TEST_HALL_OUTPUT aliases
#define TEST_HALL_OUTPUT_TRIS                 TRISAbits.TRISA2
#define TEST_HALL_OUTPUT_LAT                  LATAbits.LATA2
#define TEST_HALL_OUTPUT_PORT                 PORTAbits.RA2
#define TEST_HALL_OUTPUT_WPU                  WPUAbits.WPUA2
#define TEST_HALL_OUTPUT_OD                   ODCONAbits.ODA2
#define TEST_HALL_OUTPUT_ANS                  ANSELAbits.ANSA2
#define TEST_HALL_OUTPUT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define TEST_HALL_OUTPUT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define TEST_HALL_OUTPUT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define TEST_HALL_OUTPUT_GetValue()           PORTAbits.RA2
#define TEST_HALL_OUTPUT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define TEST_HALL_OUTPUT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define TEST_HALL_OUTPUT_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define TEST_HALL_OUTPUT_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define TEST_HALL_OUTPUT_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define TEST_HALL_OUTPUT_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define TEST_HALL_OUTPUT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define TEST_HALL_OUTPUT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SELECT2_IN aliases
#define SELECT2_IN_TRIS                 TRISBbits.TRISB4
#define SELECT2_IN_LAT                  LATBbits.LATB4
#define SELECT2_IN_PORT                 PORTBbits.RB4
#define SELECT2_IN_WPU                  WPUBbits.WPUB4
#define SELECT2_IN_OD                   ODCONBbits.ODB4
#define SELECT2_IN_ANS                  ANSELBbits.ANSB4
#define SELECT2_IN_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SELECT2_IN_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SELECT2_IN_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SELECT2_IN_GetValue()           PORTBbits.RB4
#define SELECT2_IN_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SELECT2_IN_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SELECT2_IN_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SELECT2_IN_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SELECT2_IN_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define SELECT2_IN_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define SELECT2_IN_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SELECT2_IN_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set FUNC1_IN aliases
#define FUNC1_IN_TRIS                 TRISBbits.TRISB5
#define FUNC1_IN_LAT                  LATBbits.LATB5
#define FUNC1_IN_PORT                 PORTBbits.RB5
#define FUNC1_IN_WPU                  WPUBbits.WPUB5
#define FUNC1_IN_OD                   ODCONBbits.ODB5
#define FUNC1_IN_ANS                  ANSELBbits.ANSB5
#define FUNC1_IN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define FUNC1_IN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define FUNC1_IN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define FUNC1_IN_GetValue()           PORTBbits.RB5
#define FUNC1_IN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define FUNC1_IN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define FUNC1_IN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define FUNC1_IN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define FUNC1_IN_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define FUNC1_IN_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define FUNC1_IN_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define FUNC1_IN_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set FUNC2_IN aliases
#define FUNC2_IN_TRIS                 TRISBbits.TRISB6
#define FUNC2_IN_LAT                  LATBbits.LATB6
#define FUNC2_IN_PORT                 PORTBbits.RB6
#define FUNC2_IN_WPU                  WPUBbits.WPUB6
#define FUNC2_IN_OD                   ODCONBbits.ODB6
#define FUNC2_IN_ANS                  ANSELBbits.ANSB6
#define FUNC2_IN_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define FUNC2_IN_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define FUNC2_IN_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define FUNC2_IN_GetValue()           PORTBbits.RB6
#define FUNC2_IN_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define FUNC2_IN_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define FUNC2_IN_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define FUNC2_IN_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define FUNC2_IN_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define FUNC2_IN_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)
#define FUNC2_IN_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define FUNC2_IN_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set DEBUG_INT_TIM2 aliases
#define DEBUG_INT_TIM2_TRIS                 TRISBbits.TRISB7
#define DEBUG_INT_TIM2_LAT                  LATBbits.LATB7
#define DEBUG_INT_TIM2_PORT                 PORTBbits.RB7
#define DEBUG_INT_TIM2_WPU                  WPUBbits.WPUB7
#define DEBUG_INT_TIM2_OD                   ODCONBbits.ODB7
#define DEBUG_INT_TIM2_ANS                  ANSELBbits.ANSB7
#define DEBUG_INT_TIM2_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define DEBUG_INT_TIM2_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define DEBUG_INT_TIM2_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define DEBUG_INT_TIM2_GetValue()           PORTBbits.RB7
#define DEBUG_INT_TIM2_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define DEBUG_INT_TIM2_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define DEBUG_INT_TIM2_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define DEBUG_INT_TIM2_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define DEBUG_INT_TIM2_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define DEBUG_INT_TIM2_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)
#define DEBUG_INT_TIM2_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define DEBUG_INT_TIM2_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set SPI_DS aliases
#define SPI_DS_TRIS                 TRISCbits.TRISC0
#define SPI_DS_LAT                  LATCbits.LATC0
#define SPI_DS_PORT                 PORTCbits.RC0
#define SPI_DS_WPU                  WPUCbits.WPUC0
#define SPI_DS_OD                   ODCONCbits.ODC0
#define SPI_DS_ANS                  ANSELCbits.ANSC0
#define SPI_DS_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SPI_DS_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SPI_DS_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SPI_DS_GetValue()           PORTCbits.RC0
#define SPI_DS_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SPI_DS_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SPI_DS_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SPI_DS_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SPI_DS_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define SPI_DS_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define SPI_DS_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SPI_DS_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SPI_CS aliases
#define SPI_CS_TRIS                 TRISCbits.TRISC1
#define SPI_CS_LAT                  LATCbits.LATC1
#define SPI_CS_PORT                 PORTCbits.RC1
#define SPI_CS_WPU                  WPUCbits.WPUC1
#define SPI_CS_OD                   ODCONCbits.ODC1
#define SPI_CS_ANS                  ANSELCbits.ANSC1
#define SPI_CS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SPI_CS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SPI_CS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SPI_CS_GetValue()           PORTCbits.RC1
#define SPI_CS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SPI_CS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SPI_CS_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SPI_CS_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SPI_CS_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define SPI_CS_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define SPI_CS_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SPI_CS_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SELECT1_IN aliases
#define SELECT1_IN_TRIS                 TRISCbits.TRISC2
#define SELECT1_IN_LAT                  LATCbits.LATC2
#define SELECT1_IN_PORT                 PORTCbits.RC2
#define SELECT1_IN_WPU                  WPUCbits.WPUC2
#define SELECT1_IN_OD                   ODCONCbits.ODC2
#define SELECT1_IN_ANS                  ANSELCbits.ANSC2
#define SELECT1_IN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SELECT1_IN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SELECT1_IN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SELECT1_IN_GetValue()           PORTCbits.RC2
#define SELECT1_IN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SELECT1_IN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SELECT1_IN_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SELECT1_IN_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SELECT1_IN_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define SELECT1_IN_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define SELECT1_IN_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SELECT1_IN_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IGN_BLOCK_OUT aliases
#define IGN_BLOCK_OUT_TRIS                 TRISCbits.TRISC4
#define IGN_BLOCK_OUT_LAT                  LATCbits.LATC4
#define IGN_BLOCK_OUT_PORT                 PORTCbits.RC4
#define IGN_BLOCK_OUT_WPU                  WPUCbits.WPUC4
#define IGN_BLOCK_OUT_OD                   ODCONCbits.ODC4
#define IGN_BLOCK_OUT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IGN_BLOCK_OUT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IGN_BLOCK_OUT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IGN_BLOCK_OUT_GetValue()           PORTCbits.RC4
#define IGN_BLOCK_OUT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IGN_BLOCK_OUT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IGN_BLOCK_OUT_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IGN_BLOCK_OUT_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IGN_BLOCK_OUT_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define IGN_BLOCK_OUT_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set LED_SHADOW aliases
#define LED_SHADOW_TRIS                 TRISCbits.TRISC6
#define LED_SHADOW_LAT                  LATCbits.LATC6
#define LED_SHADOW_PORT                 PORTCbits.RC6
#define LED_SHADOW_WPU                  WPUCbits.WPUC6
#define LED_SHADOW_OD                   ODCONCbits.ODC6
#define LED_SHADOW_ANS                  ANSELCbits.ANSC6
#define LED_SHADOW_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LED_SHADOW_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LED_SHADOW_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LED_SHADOW_GetValue()           PORTCbits.RC6
#define LED_SHADOW_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LED_SHADOW_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LED_SHADOW_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LED_SHADOW_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LED_SHADOW_SetPushPull()        do { ODCONCbits.ODC6 = 0; } while(0)
#define LED_SHADOW_SetOpenDrain()       do { ODCONCbits.ODC6 = 1; } while(0)
#define LED_SHADOW_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define LED_SHADOW_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set HALL_INPUT aliases
#define HALL_INPUT_TRIS                 TRISCbits.TRISC7
#define HALL_INPUT_LAT                  LATCbits.LATC7
#define HALL_INPUT_PORT                 PORTCbits.RC7
#define HALL_INPUT_WPU                  WPUCbits.WPUC7
#define HALL_INPUT_OD                   ODCONCbits.ODC7
#define HALL_INPUT_ANS                  ANSELCbits.ANSC7
#define HALL_INPUT_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define HALL_INPUT_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define HALL_INPUT_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define HALL_INPUT_GetValue()           PORTCbits.RC7
#define HALL_INPUT_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define HALL_INPUT_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define HALL_INPUT_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define HALL_INPUT_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define HALL_INPUT_SetPushPull()        do { ODCONCbits.ODC7 = 0; } while(0)
#define HALL_INPUT_SetOpenDrain()       do { ODCONCbits.ODC7 = 1; } while(0)
#define HALL_INPUT_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define HALL_INPUT_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/