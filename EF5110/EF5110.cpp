/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 *
 * EF5110.h Library V1.0 for Nokia 5110/3110
 * Created by ElecFreaks. Robi.W,27 June 2011
 *
 * http://www.elecfreaks.com
 */
#include "WProgram.h"
#include "EF5110.h"
#include "lcd.h"

EF_LCM5110::EF_LCM5110(int DB_CE, int DB_RST, int DB_DC, int DB_MOSI, int DB_CLK)
{
  pinMode(DB_CE, OUTPUT);
  pinMode(DB_RST, OUTPUT);
  pinMode(DB_DC, OUTPUT);
  pinMode(DB_MOSI, OUTPUT);
  pinMode(DB_CLK, OUTPUT);

  CE	= DB_CE;
  RST	= DB_RST;
  DC	= DB_DC;
  MOSI	= DB_MOSI;
  CLK	= DB_CLK;
}

void EF_LCM5110::write_byte(unsigned char dt, unsigned char command)
{
	unsigned char i; 
    digitalWrite(CE, 0);
    digitalWrite(DC, command);
	for(i=0;i<8;i++)
	{ 
		if(dt&0x80)
                  digitalWrite(MOSI, 1);
		else
                  digitalWrite(MOSI, 0);
		dt=dt<<1;
        digitalWrite(CLK, 0);	
        digitalWrite(CLK, 1);	
	}
    digitalWrite(DC, 1);
    digitalWrite(CE, 1);
    digitalWrite(MOSI, 1);	
}

void EF_LCM5110::init(void)
{
    digitalWrite(RST, 0);	
  	delay(30);
    digitalWrite(RST, 1);	  
	write_byte(0x21,0);		
	write_byte(0xd0,0);		
	write_byte(0x20,0);		
	write_byte(0x0C,0);		
}

void EF_LCM5110::set_XY(unsigned char X, unsigned char Y)
{
	write_byte(0x40 | Y, 0);// column
	write_byte(0x80 | X, 0);// row
} 

void EF_LCM5110::clearLCM(void)
{
	unsigned char t;
	unsigned char k;
	set_XY(0,0);
	for(t=0;t<6;t++)
	{ 
		for(k=0;k<84;k++)
		{ 
			write_byte(0x00,1);	
		} 
	}
}

void EF_LCM5110::write_char(unsigned char c)
{
	unsigned char line;
	c-=32;
	for (line=0; line<6; line++)
	write_byte(pgm_read_byte(font6x8+c*6+line), 1);
	
}
void EF_LCM5110::write_string(unsigned char X,unsigned char Y,char *s)
{
	set_XY(X,Y);
	while (*s) 
	{
		write_char(*s);
		s++;
	}
} 
