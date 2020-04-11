/*
 * File:   test_engine_rps.c
 * Author: dunaevaleksey
 *
 * Created on April 10, 2020, 6:38 AM
 */

#ifdef TEST

#include "test_engine_rps.h"

const float msPerSecondTim1 = 0.000002; //ms per one tick Tim1
const uint16_t maxTickTim1 = 0xFFFF;

void TEST_Engine_Initialize(uint16_t minRPS, uint16_t maxRPS)
{
    uint16_t step = (maxRPS - minRPS) / 16;
    
    for (uint8_t i = 0; i <= 16; i++)
    {
        uint16_t countUntilTim1 = 1 / ((minRPS + i * step) * msPerSecondTim1);
        uint16_t countTim1 = (0xFFFF - countUntilTim1);
        testEngineTable.ter[i].tim1Count = countTim1;
        testEngineTable.ter[i].ccp1Count = countTim1 + (countUntilTim1 / 6);
        testEngineTable.ter[i].RPS = minRPS + i * step; 
    }
}

#endif