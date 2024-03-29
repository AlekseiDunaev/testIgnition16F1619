/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MAIN_H
#define	MAIN_H

#define SEC_PER_MIN 60 // Seconds per minutes
// coefficient count * coefficient = RPM ms. 60 (SEC+PER_MIN)/0.00006(Tim2 time interrupt) * 6 (full shaft rotate) .
#define RPM_COEFFICIENT 16667 //But multiple to 10 in main programm
#define COUNT_BUTTON_ENOUGHT 255
#define COUNT_HALL_ENOUGHT 4

#define LENGHT_BAR 4 //Lenght bar on screen
#define UPPER_BAR_CORNER 150
#define LOWER_BAR_CORNER 250

#include <stdio.h>
//#include <stdlib.h>
#include <stdbool.h>

#ifdef TEST
#include "mcc_generated_files/test_engine_rpm.h"
#endif

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
// Store state of toggle
typedef union {
    unsigned char all;
    struct {
        bool SENS           :1; //Hall sense state
        bool NOTDEF1        :1; //Nodef1
        bool NOTDEF2        :1; //Nodef2
        bool NOTDEF3        :1; //Nodef3
        bool SELECT1        :1; //Select table ignition #1
        bool SELECT2        :1; //Select table ignition #2
        bool FUNC1          :1; //Engine stop
        bool FUNC2          :1; //Warm spark
    };
} STATE_TOGGLE_t;

STATE_TOGGLE_t Port = {0x00};

// Store flags
typedef union {
    unsigned char all;
    struct {
        bool lastState      :1; //Last state Hall sensor
        bool overflowCount  :1; //Overflow count
        bool coilOff        :1; //Coil disable when engine not work
        bool engineStop     :1; //Disable engine
        bool overrun1       :1; //Enable limit overrun FUNC1
        bool overrun2       :1; //Enable limit overrun FUNC2
        bool NOTDEF1        :1; //Nodef1
        bool NOTDEF2        :1; //Nodef2
    };
} FLAG_t;

FLAG_t Flag = {0x00};

uint8_t countSELECT1 = 0;
uint8_t countSELECT2 = 0;
uint8_t countFUNC1 = 0;
uint8_t countFUNC2 = 0;
uint8_t countHALL = 0; //счетчик фильтра датчика Холла
uint8_t sectorCount = 0; //Счетчик отсчетов прерываний по таймеру при проходе шторки через датчик Холла
uint8_t lastSectionCount = 0; //Последнее значение счетчик отсчетов прерываний по таймер при проходе шторки через датчик Холла
uint16_t sectorCountContinued = 0; //Значение фактического числа отсчетов таймера при проходе шторки через датчик Холла
uint8_t sparkTime = 0; //Кол-во отсчетов после которого происходит включение катушки при нахождении шторки в датчике Холла
uint16_t coilCount = 0; //Счетчик включения катушки
//Нигде не используется
//uint16_t coilOffCount = 0; //Счетчик простоя катушки

// Table shift ignition
uint8_t shiftIgnMassive[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            7, 8, 9 ,9 ,10 ,10, 11, 12, 12, 13, 14, 15, 15, 16, 17, 18,
                            19, 19, 20, 21, 22, 22, 23, 24, 25, 25, 26, 27, 28, 29, 30, 31,
                            31, 32, 33, 34, 35, 36, 37, 37, 38, 39, 40, 41, 42, 43, 44, 45,
                            46, 46, 47, 48, 49, 50, 51, 52, 53, 54, 54, 55, 56, 57, 58, 59,
                            60, 61, 62, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
                            75, 76, 77, 78, 79, 80, 81, 82, 82, 83, 84, 85, 86, 87, 88, 89,
                            90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 102, 103, 104,
                            105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
                            119, 120, 121, 122, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131,
                            132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 141, 143, 144, 146,
                            147, 148, 150, 151, 152, 154, 155, 156, 158, 159, 160, 162, 163, 164,
                            166, 167, 168, 170, 171, 172, 174, 175, 177, 178, 179, 181, 182, 183,
                            185, 186, 187, 189, 190, 191, 193, 194, 195, 197, 198, 199, 201, 202,
                            203, 205, 206, 208, 209, 210, 212, 213, 214, 216, 217, 218, 220, 221,
                            222, 224, 225, 226, 228, 229, 230, 232, 233, 234, 236, 237, 238, 000};

uint16_t currentSectorCount; //current sectorCount
//int16_t  bars = 0; // bars counts
//int16_t  lastBars = 0; // last bars count
int16_t  barsPaint; // count bars paint
int16_t lastBarsPaint; // count last bars paint
const int16_t coefficientLenghtBar = 4; // length pixel bar
const int16_t RPMDangeros = 30; // RPM/100 when RPM upper will be dangeros
const int16_t RPMDangerosLenghtBar = coefficientLenghtBar * RPMDangeros;
uint16_t RPM; //store current sectorCountContinued if interrupt Tim2 occur for screen RPM
uint16_t tempSectorCountContinued; //store current sectorCountContinued if interrupt Tim2 occur for screen sectorCountContinued
//uint16_t RPMDiv10, RPMDiv100, RPMDiv1000; //Store digit of number
//int16_t stepTo; //numbers of bars paint
//uint16_t lenghtLastBar; //position of last bar;
int8_t direction = 1; //direction growing bars

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

