/**
  CCP1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    ccp1.c

  @Summary
    This is the generated driver implementation file for the CCP1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for CCP1.
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
#include "ccp1.h"
#include "mcc.h"

/**
  Section: Compare Module APIs:
*/

void CCP1_Initialize(void)
{
    // Set the CCP1 to the options selected in the User Interface
	
	// MODE Toggle; EN enabled; FMT right_aligned; 
	CCP1CON = 0x82;    
	
	// RH 24; 
	CCPR1H = 0x18;    
	
	// RL 56; 
	CCPR1L = 0x38;    

    
    // Clear the CCP1 interrupt flag
    PIR1bits.CCP1IF = 0;

    // Enable the CCP1 interrupt
    PIE1bits.CCP1IE = 1;
}

void CCP1_SetCompareCount(uint16_t compareCount)
{
    CCP1_PERIOD_REG_T module;
    
    // Write the 16-bit compare value
    module.ccpr1_16Bit = compareCount;
    
    CCPR1L = module.ccpr1l;
    CCPR1H = module.ccpr1h;
}

bool CCP1_OutputStatusGet(void)
{
    // Returns the output status
    return(CCP1CONbits.OUT);
}

void CCP1_CompareISR(void)
{
    // Clear the CCP1 interrupt flag
    PIR1bits.CCP1IF = 0;
    
    // Add user code here
	
    // Toggle CCP between 200 ms and 400 ms
    
    if (CCPR1H == 0x18) {
        CCP1_SetCompareCount(0x3070);
    } else {
        CCP1_SetCompareCount(0x1838);
    }
    LED_DEBUG_Toggle();

}
/**
 End of File
*/