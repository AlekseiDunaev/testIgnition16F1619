/*
 * File:   test_engine_rps.c
 * Author: dunaevaleksey
 *
 * Created on April 10, 2020, 6:38 AM
 */

#ifdef TEST

#include "test_engine_rpm.h"

void TEST_Engine_Initialize(uint16_t minRPS, uint16_t maxRPS)
{
    uint16_t step = (maxRPS - minRPS) / STEPS;
    
    for (uint8_t i = 0; i <= STEPS; i++)
    {
        /*
        uint16_t countUntilTim1 = 1 / ((minRPS + i * step) * msPerTickTim1);
        uint16_t countTim1 = (0xFFFF - countUntilTim1);
        testEngineTable.ter[i].tim1Count = countTim1;
        testEngineTable.ter[i].ccp1Count = countTim1 + (countUntilTim1 / fillTestEngineCycle);
        testEngineTable.ter[i].cycles = TIME_OBSERVATION * (minRPS + i * step);
        */
        uint16_t countUntilTim1 = 1 / ((minRPS + i * step) * msPerTickTim1);
        testEngineTable.ter[i].tim1Count = countUntilTim1;
        testEngineTable.ter[i].ccp1Count = countUntilTim1 - (countUntilTim1 / fillTestEngineCycle);
        testEngineTable.ter[i].cycles = TIME_OBSERVATION * (minRPS + i * step);
    }
}

#endif