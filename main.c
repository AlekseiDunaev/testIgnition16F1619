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

/**
 Auxiary function
 Table jumps
 */

/**
ORG	0x0300

TableDefault;

    addwf   PCL,F               ; Вычисляемый переход

    retlw   .000                ; 0
    retlw   .000                ; 1
    retlw   .000                ; 2
    retlw   .000                ; 3
    retlw   .000                ; 4
    retlw   .000                ; 5
    retlw   .000                ; 6
    retlw   .000                ; 7
    retlw   .000                ; 8
    retlw   .000                ; 9
    retlw   .000                ; 10
    retlw   .000                ; 11
    retlw   .000                ; 12
    retlw   .000                ; 13
    retlw   .000                ; 14
    retlw   .000                ; 15
    retlw   .007                ; 16
    retlw   .008                ; 17
    retlw   .009                ; 18
    retlw   .009                ; 19
    retlw   .010                ; 20
    retlw   .010                ; 21
    retlw   .011                ; 22
    retlw   .012                ; 23
    retlw   .012                ; 24
    retlw   .013                ; 25
    retlw   .014                ; 26
    retlw   .015                ; 27
    retlw   .015                ; 28
    retlw   .016                ; 29
    retlw   .017                ; 30
    retlw   .018                ; 31
    retlw   .019                ; 32
    retlw   .019                ; 33
    retlw   .020                ; 34
    retlw   .021                ; 35
    retlw   .022                ; 36
    retlw   .022                ; 37
    retlw   .023                ; 38
    retlw   .024                ; 39
    retlw   .025                ; 40
    retlw   .025                ; 41
    retlw   .026                ; 42
    retlw   .027                ; 43
    retlw   .028                ; 44
    retlw   .029                ; 45
    retlw   .030                ; 46
    retlw   .031                ; 47
    retlw   .031                ; 48
    retlw   .032                ; 49
    retlw   .033                ; 50
    retlw   .034                ; 51
    retlw   .035                ; 52
    retlw   .036                ; 53
    retlw   .037                ; 54
    retlw   .037                ; 55
    retlw   .038                ; 56
    retlw   .039                ; 57
    retlw   .040                ; 58
    retlw   .041                ; 59
    retlw   .042                ; 60
    retlw   .043                ; 61
    retlw   .044                ; 62
    retlw   .045                ; 63
    retlw   .046                ; 64
    retlw   .046                ; 65
    retlw   .047                ; 66
    retlw   .048                ; 67
    retlw   .049                ; 68
    retlw   .050                ; 69
    retlw   .051                ; 70
    retlw   .052                ; 71
    retlw   .053                ; 72
    retlw   .054                ; 73
    retlw   .054                ; 74
    retlw   .055                ; 75
    retlw   .056                ; 76
    retlw   .057                ; 77
    retlw   .058                ; 78
    retlw   .059                ; 79
    retlw   .060                ; 80
    retlw   .061                ; 81
    retlw   .062                ; 82
    retlw   .062                ; 83
    retlw   .063                ; 84
    retlw   .064                ; 85
    retlw   .065                ; 86
    retlw   .066                ; 87
    retlw   .067                ; 88
    retlw   .068                ; 89
    retlw   .069                ; 90
    retlw   .070                ; 91
    retlw   .071                ; 92
    retlw   .072                ; 93
    retlw   .073                ; 94
    retlw   .074                ; 95
    retlw   .075                ; 96
    retlw   .076                ; 97
    retlw   .077                ; 98
    retlw   .078                ; 99
    retlw   .079                ; 100
    retlw   .080                ; 101
    retlw   .081                ; 102
    retlw   .082                ; 103
    retlw   .082                ; 104
    retlw   .083                ; 105
    retlw   .084                ; 106
    retlw   .085                ; 107
    retlw   .086                ; 108
    retlw   .087                ; 109
    retlw   .088                ; 110
    retlw   .089                ; 111
    retlw   .090                ; 112
    retlw   .091                ; 113
    retlw   .092                ; 114
    retlw   .093                ; 115
    retlw   .094                ; 116
    retlw   .095                ; 117
    retlw   .096                ; 118
    retlw   .097                ; 119
    retlw   .098                ; 120
    retlw   .099                ; 121
    retlw   .100                ; 122
    retlw   .101                ; 123
    retlw   .102                ; 124
    retlw   .102                ; 125
    retlw   .103                ; 126
    retlw   .104                ; 127
    retlw   .105                ; 128
    retlw   .106                ; 129
    retlw   .107                ; 130
    retlw   .108                ; 131
    retlw   .109                ; 132
    retlw   .110                ; 133
    retlw   .111                ; 134
    retlw   .112                ; 135
    retlw   .113                ; 136
    retlw   .114                ; 137
    retlw   .115                ; 138
    retlw   .116                ; 139
    retlw   .117                ; 140
    retlw   .118                ; 141
    retlw   .119                ; 142
    retlw   .120                ; 143
    retlw   .121                ; 144
    retlw   .122                ; 145
    retlw   .122                ; 146
    retlw   .123                ; 147
    retlw   .124                ; 148
    retlw   .125                ; 149
    retlw   .126                ; 150
    retlw   .127                ; 151
    retlw   .128                ; 152
    retlw   .129                ; 153
    retlw   .130                ; 154
    retlw   .131                ; 155
    retlw   .132                ; 156
    retlw   .133                ; 157
    retlw   .134                ; 158
    retlw   .135                ; 159
    retlw   .136                ; 160
    retlw   .137                ; 161
    retlw   .138                ; 162
    retlw   .139                ; 163
    retlw   .140                ; 164
    retlw   .141                ; 165
    retlw   .141                ; 166
    retlw   .143                ; 167
    retlw   .144                ; 168
    retlw   .146                ; 169
    retlw   .147                ; 170
    retlw   .148                ; 171
    retlw   .150                ; 172
    retlw   .151                ; 173
    retlw   .152                ; 174
    retlw   .154                ; 175
    retlw   .155                ; 176
    retlw   .156                ; 177
    retlw   .158                ; 178
    retlw   .159                ; 179
    retlw   .160                ; 180
    retlw   .162                ; 181
    retlw   .163                ; 182
    retlw   .164                ; 183
    retlw   .166                ; 184
    retlw   .167                ; 185
    retlw   .168                ; 186
    retlw   .170                ; 187
    retlw   .171                ; 188
    retlw   .172                ; 189
    retlw   .174                ; 190
    retlw   .175                ; 191
    retlw   .177                ; 192
    retlw   .178                ; 193
    retlw   .179                ; 194
    retlw   .181                ; 195
    retlw   .182                ; 196
    retlw   .183                ; 197
    retlw   .185                ; 198
    retlw   .186                ; 199
    retlw   .187                ; 200
    retlw   .189                ; 201
    retlw   .190                ; 202
    retlw   .191                ; 203
    retlw   .193                ; 204
    retlw   .194                ; 205
    retlw   .195                ; 206
    retlw   .197                ; 207
    retlw   .198                ; 208
    retlw   .199                ; 209
    retlw   .201                ; 210
    retlw   .202                ; 211
    retlw   .203                ; 212
    retlw   .205                ; 213
    retlw   .206                ; 214
    retlw   .208                ; 215
    retlw   .209                ; 216
    retlw   .210                ; 217
    retlw   .212                ; 218
    retlw   .213                ; 219
    retlw   .214                ; 220
    retlw   .216                ; 221
    retlw   .217                ; 222
    retlw   .218                ; 223
    retlw   .220                ; 224
    retlw   .221                ; 225
    retlw   .222                ; 226
    retlw   .224                ; 227
    retlw   .225                ; 228
    retlw   .226                ; 229
    retlw   .228                ; 230
    retlw   .229                ; 231
    retlw   .230                ; 232
    retlw   .232                ; 233
    retlw   .233                ; 234
    retlw   .234                ; 235
    retlw   .236                ; 236
    retlw   .237                ; 237
    retlw   .238                ; 238
    retlw   .000                ; 239
*/

/*
uint8_t shiftIgnition(uint8_t count) {
    
    switch (count) {
        case 0:     // 0
        case 1:     // 1
        case 2:     // 2
        case 3:     // 3
        case 4:     // 4
        case 5:     // 5
        case 6:     // 6
        case 7:     // 7
        case 8:     // 8
        case 9:     // 9
        case 10:     // 10
        case 11:     // 11
        case 12:     // 12
        case 13:     // 13
        case 14:     // 14
        case 15:     // 15
            return 0;
            break;
        case 16:
            return 7;
            break;
        case 17:
            return 8;
            break;
        case 18:
            return 9;
            break;
        case 19:
            return 9;
            break;
        case 20:
            return 10;
            break;
        case 21:
            return 10;
            break;
        case 22:
            return 11;
            break;
        case 23:
            return 12;
            break;
        case 24:
            return 12;
            break;
         case 25:
            return 13;
            break;
        case 26:
            return 14;
            break;
        case 27:
            return 15;
            break;
        case 28:
            return 15;
            break;
        case 29:
            return 16;
            break;
        case 30:
            return 17;
            break;
        case 31:
            return 18;
            break;
        case 32:
            return 19;
            break;            
        case 33:
            return 19;
            break;
        case 34:
            return 20;
            break;
        case 35:
            return 21;
            break;
        case 36:
            return 22;
            break;            
        case 37:
            return 22;
            break;
        case 38:
            return 23;
            break;
        case 39:
            return 24;
            break;
        case 40:
            return 25;
            break;
        case 41:
            return 25;
            break;
        case 42:
            return 26;
            break;    
        case 43:
            return 27;
            break;
        case 44:
            return 28;
            break;
        case 45:
            return 29;
            break;
        case 46:
            return 30;
            break;
        case 47:
            return 31;
            break;
        case 48:
            return 31;
            break;
        case 49:
            return 32;
            break;
        case 50:
            return 33;
            break;


        case 51:
            return 34;
            break;
        case 52:
            return 35;
            break;    
        case 53:
            return 36;
            break;
        case 54:
            return 37;
            break;
        case 55:
            return 37;
            break;
        case 56:
            return 38;
            break;
        case 57:
            return 39;
            break;
        case 58:
            return 40;
            break;
        case 59:
            return 41;
            break;
        case 60:
            return 42;
            break;


        case 61:
            return 43;
            break;
        case 62:
            return 44;
            break;    
        case 63:
            return 45;
            break;
        case 64:
            return 46;
            break;
        case 65:
            return 46;
            break;
        case 66:
            return 47;
            break;
        case 67:
            return 48;
            break;
        case 68:
            return 49;
            break;
        case 69:
            return 50;
            break;
        case 70:
            return 51;
            break;


        case 71:
            return 52;
            break;
        case 72:
            return 53;
            break;    
        case 73:
            return 54;
            break;
        case 74:
            return 54;
            break;
        case 75:
            return 55;
            break;
        case 76:
            return 56;
            break;
        case 77:
            return 57;
            break;
        case 78:
            return 58;
            break;
        case 79:
            return 59;
            break;
        case 80:
            return 60;
            break;


        case 81:
            return 61;
            break;
        case 82:
            return 62;
            break;    
        case 83:
            return 62;
            break;
        case 84:
            return 63;
            break;
        case 85:
            return 64;
            break;
        case 86:
            return 65;
            break;
        case 87:
            return 66;
            break;
        case 88:
            return 67;
            break;
        case 89:
            return 68;
            break;
        case 90:
            return 69;
            break;
            
        case 91:
            return 70;
            break;
        case 92:
            return 71;
            break;    
        case 93:
            return 72;
            break;
        case 94:
            return 73;
            break;
        case 95:
            return 74;
            break;
        case 96:
            return 75;
            break;
        case 97:
            return 76;
            break;
        case 98:
            return 77;
            break;
        case 99:
            return 78;
            break;
        case 100:
            return 79;
            break;
            
        case 101:
            return 80;
            break;
        case 102:
            return 81;
            break;    
        case 103:
            return 82;
            break;
        case 104:
            return 82;
            break;
        case 105:
            return 83;
            break;
        case 106:
            return 84;
            break;
        case 107:
            return 85;
            break;
        case 108:
            return 86;
            break;
        case 109:
            return 87;
            break;
        case 110:
            return 88;
            break;
            
        case 111:
            return 89;
            break;
        case 112:
            return 90;
            break;    
        case 113:
            return 91;
            break;
        case 114:
            return 92;
            break;
        case 115:
            return 93;
            break;
        case 116:
            return 94;
            break;
        case 117:
            return 95;
            break;
        case 118:
            return 96;
            break;
        case 119:
            return 97;
            break;
        case 120:
            return 98;
            break;
            
            
        case 121:
            return 99;
            break;
        case 122:
            return 100;
            break;    
        case 123:
            return 101;
            break;
        case 124:
            return 102;
            break;
        case 125:
            return 102;
            break;
        case 126:
            return 103;
            break;
        case 127:
            return 104;
            break;
        case 128:
            return 105;
            break;
        case 129:
            return 106;
            break;
        case 130:
            return 107;
            break;
            
        case 131:
            return 108;
            break;
        case 132:
            return 109;
            break;    
        case 133:
            return 110;
            break;
        case 134:
            return 111;
            break;
        case 135:
            return 112;
            break;
        case 136:
            return 113;
            break;
        case 137:
            return 114;
            break;
        case 138:
            return 115;
            break;
        case 139:
            return 116;
            break;
        case 140:
            return 117;
            break;
            
        case 141:
            return 118;
            break;
        case 142:
            return 119;
            break;    
        case 143:
            return 120;
            break;
        case 144:
            return 121;
            break;
        case 145:
            return 122;
            break;
        case 146:
            return 122;
            break;
        case 147:
            return 123;
            break;
        case 148:
            return 124;
            break;
        case 149:
            return 125;
            break;
        case 150:
            return 126;
            break;
            
        case 151:
            return 127;
            break;
        case 152:
            return 128;
            break;    
        case 153:
            return 129;
            break;
        case 154:
            return 130;
            break;
        case 155:
            return 131;
            break;
        case 156:
            return 132;
            break;
        case 157:
            return 133;
            break;
        case 158:
            return 134;
            break;
        case 159:
            return 135;
            break;
        case 160:
            return 136;
            break;
            
        case 161:
            return 137;
            break;
        case 162:
            return 138;
            break;    
        case 163:
            return 139;
            break;
        case 164:
            return 140;
            break;
        case 165:
            return 141;
            break;
        case 166:
            return 141;
            break;
        case 167:
            return 143;
            break;
        case 168:
            return 144;
            break;
        case 169:
            return 146;
            break;
        case 170:
            return 147;
            break;
            
        case 171:
            return 148;
            break;
        case 172:
            return 150;
            break;    
        case 173:
            return 151;
            break;
        case 174:
            return 152;
            break;
        case 175:
            return 154;
            break;
        case 176:
            return 155;
            break;
        case 177:
            return 156;
            break;
        case 178:
            return 158;
            break;
        case 179:
            return 159;
            break;
        case 180:
            return 160;
            break;
            
        case 181:
            return 162;
            break;
        case 182:
            return 163;
            break;    
        case 183:
            return 164;
            break;
        case 184:
            return 166;
            break;
        case 185:
            return 167;
            break;
        case 186:
            return 168;
            break;
        case 187:
            return 170;
            break;
        case 188:
            return 171;
            break;
        case 189:
            return 172;
            break;
        case 190:
            return 174;
            break;
            
        case 191:
            return 175;
            break;
        case 192:
            return 177;
            break;    
        case 193:
            return 178;
            break;
        case 194:
            return 179;
            break;
        case 195:
            return 181;
            break;
        case 196:
            return 182;
            break;
        case 197:
            return 183;
            break;
        case 198:
            return 185;
            break;
        case 199:
            return 186;
            break;
        case 200:
            return 187;
            break;
            
        case 201:
            return 189;
            break;
        case 202:
            return 190;
            break;    
        case 203:
            return 191;
            break;
        case 204:
            return 193;
            break;
        case 205:
            return 194;
            break;
        case 206:
            return 195;
            break;
        case 207:
            return 197;
            break;
        case 208:
            return 198;
            break;
        case 209:
            return 199;
            break;
        case 210:
            return 201;
            break;
            
        case 211:
            return 202;
            break;
        case 212:
            return 203;
            break;    
        case 213:
            return 205;
            break;
        case 214:
            return 206;
            break;
        case 215:
            return 208;
            break;
        case 216:
            return 209;
            break;
        case 217:
            return 210;
            break;
        case 218:
            return 212;
            break;
        case 219:
            return 213;
            break;
        case 220:
            return 214;
            break;
            
        case 221:
            return 216;
            break;
        case 222:
            return 217;
            break;    
        case 223:
            return 218;
            break;
        case 224:
            return 220;
            break;
        case 225:
            return 221;
            break;
        case 226:
            return 222;
            break;
        case 227:
            return 224;
            break;
        case 228:
            return 225;
            break;
        case 229:
            return 226;
            break;
        case 230:
            return 228;
            break;
            
        case 231:
            return 229;
            break;
        case 232:
            return 230;
            break;    
        case 233:
            return 232;
            break;
        case 234:
            return 233;
            break;
        case 235:
            return 234;
            break;
        case 236:
            return 236;
            break;
        case 237:
            return 237;
            break;
        case 238:
            return 238;
            break;
        default:
            return 0;
            
    }
}
*/


/*
                         Main application
 */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    
    countSELECT1 = countSELECT2 = countFUNC1 = countFUNC2 = countHALL = 0;
    
    Port.SELECT1 = SELECT1_IN_GetValue();
    Port.SELECT2 = SELECT2_IN_GetValue();
    Port.FUNC1 = FUNC1_IN_GetValue();
    Port.FUNC2 = FUNC2_IN_GetValue();
         
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

    while (1)
    {
        
        // Add your application code
        
        if (SELECT1_IN_GetValue() != Port.SELECT1) {
            if (countSELECT1 == countEnought) {
                Port.SELECT1 = SELECT1_IN_GetValue();
                countSELECT1 = 0;
            } else {
                countSELECT1++;
            }
        }
        
        if (SELECT1_IN_GetValue() != Port.SELECT2) {
            if (countSELECT2 == countEnought) {
                Port.SELECT2 = SELECT2_IN_GetValue();
                countSELECT2 = 0;
            } else {
                countSELECT2++;
            }
        }
        
        if (FUNC1_IN_GetValue() != Port.FUNC1) {
            if (countFUNC1 == countEnought) {
                Port.FUNC1 = FUNC1_IN_GetValue();
                countFUNC1 = 0;
            } else {
                countFUNC1++;
            }
        }
        
        if (FUNC2_IN_GetValue() != Port.FUNC2) {
            if (countFUNC2 == countEnought) {
                Port.FUNC2 = FUNC2_IN_GetValue();
                countFUNC2 = 0;
            } else {
                countFUNC2++;
            }
        }

        LED_DEBUG_Toggle();
    
        //shiftIgnCount = 101;
        //shiftIgn = shiftIgnMassive[shiftIgnCount];

        //readEmpty = SPI_Exchange8bit(SPI_DEBUG_SIMBOL); // without redEmpty compiling too    
        SCREEN_Fill(00);
        SCREEN_DrawBox(50, 50, 55, 55, 1100);
        SCREEN_DrawPixel(150, 150, 1100);
        //__delay_ms(1000);
    
    }
}
/**
 End of File
*/