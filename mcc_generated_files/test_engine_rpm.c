/*
 * File:   test_engine_rpm.c
 * Author: dunaevaleksey
 *
 * Created on April 9, 2020, 11:08 PM
 */


#include <xc.h>
#include "test_engine_rpm.h"

void TABLE_Test_Engine_RPM()
{
    for (i = 1; i <= 16; i++)
    {
        countTim1 = 1 / (i * 5 * msPerSecondTim1);
        countUntilTim1 = (0xFFFF - countTim1);
        countCCP1 = countUntilTim1 + countTim1 / 6;
        testTable[i] = [countTim1][countCPP1];
    }
}
