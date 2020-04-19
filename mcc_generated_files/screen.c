/*
 * File:   screen.c
 * Author: alekseydunaev
 *
 * Created on November 16, 2019, 5:28 PM
 */

#include "screen.h"

extern const font_type TimesNewRoman;

void SCREEN_Initialize(uint8_t orient) {
    
  //SCREEN_RESET_SetHigh();
  SPI_ILI9341_SendCommand(ILI9341_RESET);
  __delay_ms(100);
  
  /// Setup screen
  SPI_ILI9341_SendCommand(ILI9341_POWERA);
  SPI_ILI9341_SendData(0x39);
  SPI_ILI9341_SendData(0x2C);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x34);
  SPI_ILI9341_SendData(0x02);
  SPI_ILI9341_SendCommand(ILI9341_POWERB);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0xC1);
  SPI_ILI9341_SendData(0x30);
  SPI_ILI9341_SendCommand(ILI9341_DTCA);
  SPI_ILI9341_SendData(0x85);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x78);
  SPI_ILI9341_SendCommand(ILI9341_DTCB);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendCommand(ILI9341_POWER_SEQ);
  SPI_ILI9341_SendData(0x64);
  SPI_ILI9341_SendData(0x03);
  SPI_ILI9341_SendData(0x12);
  SPI_ILI9341_SendData(0x81);
  SPI_ILI9341_SendCommand(ILI9341_PRC);
  SPI_ILI9341_SendData(0x20);
  SPI_ILI9341_SendCommand(ILI9341_POWER1);
  SPI_ILI9341_SendData(0x23);
  SPI_ILI9341_SendCommand(ILI9341_POWER2);
  SPI_ILI9341_SendData(0x10);
  SPI_ILI9341_SendCommand(ILI9341_VCOM1);
  SPI_ILI9341_SendData(0x3E);
  SPI_ILI9341_SendData(0x28);
  SPI_ILI9341_SendCommand(ILI9341_VCOM2);
  SPI_ILI9341_SendData(0x86);
  
  SCREEN_SetOrientation(orient);
  
  //SPI_ILI9341_SendCommand(ILI9341_MAC);
  //SPI_ILI9341_SendData(0x48);
  SPI_ILI9341_SendCommand(ILI9341_PIXEL_FORMAT);
  SPI_ILI9341_SendData(0x55);
  SPI_ILI9341_SendCommand(ILI9341_FRC);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x18);
  SPI_ILI9341_SendCommand(ILI9341_DFC);
  SPI_ILI9341_SendData(0x08);
  SPI_ILI9341_SendData(0x82);
  SPI_ILI9341_SendData(0x27);
  SPI_ILI9341_SendCommand(ILI9341_3GAMMA_EN);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendCommand(ILI9341_COLUMN_ADDR);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0xEF);
  SPI_ILI9341_SendCommand(ILI9341_PAGE_ADDR);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x01);
  SPI_ILI9341_SendData(0x3F);
  SPI_ILI9341_SendCommand(ILI9341_GAMMA);
  SPI_ILI9341_SendData(0x01);
  SPI_ILI9341_SendCommand(ILI9341_PGAMMA);
  SPI_ILI9341_SendData(0x0F);
  SPI_ILI9341_SendData(0x31);
  SPI_ILI9341_SendData(0x2B);
  SPI_ILI9341_SendData(0x0C);
  SPI_ILI9341_SendData(0x0E);
  SPI_ILI9341_SendData(0x08);
  SPI_ILI9341_SendData(0x4E);
  SPI_ILI9341_SendData(0xF1);
  SPI_ILI9341_SendData(0x37);
  SPI_ILI9341_SendData(0x07);
  SPI_ILI9341_SendData(0x10);
  SPI_ILI9341_SendData(0x03);
  SPI_ILI9341_SendData(0x0E);
  SPI_ILI9341_SendData(0x09);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendCommand(ILI9341_NGAMMA);
  SPI_ILI9341_SendData(0x00);
  SPI_ILI9341_SendData(0x0E);
  SPI_ILI9341_SendData(0x14);
  SPI_ILI9341_SendData(0x03);
  SPI_ILI9341_SendData(0x11);
  SPI_ILI9341_SendData(0x07);
  SPI_ILI9341_SendData(0x31);
  SPI_ILI9341_SendData(0xC1);
  SPI_ILI9341_SendData(0x48);
  SPI_ILI9341_SendData(0x08);
  SPI_ILI9341_SendData(0x0F);
  SPI_ILI9341_SendData(0x0C);
  SPI_ILI9341_SendData(0x31);
  SPI_ILI9341_SendData(0x36);
  SPI_ILI9341_SendData(0x0F);
  SPI_ILI9341_SendCommand(ILI9341_SLEEP_OUT);
  
  __delay_ms(100);
  SPI_ILI9341_SendCommand(ILI9341_DISPLAY_ON);
  SPI_ILI9341_SendCommand(ILI9341_GRAM);
}

void SCREEN_SetOrientation(uint8_t orient)
{
	SPI_ILI9341_SendCommand(0x36);
	switch (orient)
	{
		case 0: SPI_ILI9341_SendData(0x48);
		break;
		case 1: SPI_ILI9341_SendData(0x28);
		break;
		case 2: SPI_ILI9341_SendData(0x88);
		break;
		case 3: SPI_ILI9341_SendData(0xE8);
		break;
	}
	if (orient == 0 || orient == 2)
	{
		SCREEN_WIDTH = 239;
        SCREEN_HEIGHT = 319;
	}
	else
	{
		SCREEN_WIDTH = 319;
		SCREEN_HEIGHT = 239;
	}
}


void SCREEN_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
    
	SPI_ILI9341_SendCommand(ILI9341_COLUMN_ADDR);
	SPI_ILI9341_SendData(x1 >> 8);
	SPI_ILI9341_SendData(x1 & 0xFF);
	SPI_ILI9341_SendData(x2 >> 8);
	SPI_ILI9341_SendData(x2 & 0xFF);

	SPI_ILI9341_SendCommand(ILI9341_PAGE_ADDR);
	SPI_ILI9341_SendData(y1 >> 8);
	SPI_ILI9341_SendData(y1 & 0xFF);
	SPI_ILI9341_SendData(y2 >> 8);
	SPI_ILI9341_SendData(y2 & 0xFF);
    
}

void SCREEN_Fill(uint16_t color) {
	uint8_t i, j;
	i = color >> 8;
	j = color & 0xFF;
	SCREEN_SetCursorPosition(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    SPI_ILI9341_SendCommand(ILI9341_GRAM);

	for (uint16_t n = 0; n <= SCREEN_WIDTH; n++) {
        for (uint16_t k = 0; k <= SCREEN_HEIGHT; k++) {
            SPI_ILI9341_SendData(i);
            SPI_ILI9341_SendData(j);
        }
    }
}

void SCREEN_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
    SCREEN_SetCursorPosition(x, y, x, y);
    SPI_ILI9341_SendCommand(ILI9341_GRAM);
    
    SPI_ILI9341_SendData(color >> 8);
    SPI_ILI9341_SendData(color & 0xFF);

}

void SCREEN_DrawBox(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) {
    uint8_t i, j;
	i = color >> 8;
	j = color & 0xFF;
    
	SCREEN_SetCursorPosition(x1, y1, x2, y2);
    SPI_ILI9341_SendCommand(ILI9341_GRAM);

	for (uint16_t n = 0; n < ((x2 - x1) * (y2 - y1)) ; n++) {
		SPI_ILI9341_SendData(i);
		SPI_ILI9341_SendData(j);
    }
}

uint16_t SCREEN_Putchar(uint16_t x, uint16_t y, char c) {
        uint16_t i, j;
        //unsigned short Data;
        uint16_t Data;
        
        //uint16_t offset = (c-47)*TimesNewRoman.height;
        uint16_t offset = c * TimesNewRoman.height;
        uint16_t width = TimesNewRoman.width;
        
    	for (i = 0; i < TimesNewRoman.height; i++) {

            Data = TimesNewRoman.data_table[offset+i];    
            
            
            for (j = 0; j < width; j++) {
                if ((Data << j) & 0x8000) {
                    SCREEN_DrawPixel(x + j, (y + i), 0xFFFF);  //white
                } else {
                    SCREEN_DrawPixel(x + j, (y + i), 0x0000);  //black
                }
            }
        }
        
        return x+width;
}

/*
void SCREEN_DrawString(uint16_t x, uint16_t y, char *str)
{
    while(*str) {
        x = SCREEN_Putchar(x,y,*str++);
    }
}
*/
