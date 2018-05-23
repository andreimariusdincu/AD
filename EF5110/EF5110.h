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

#ifndef __EF5110_H__
#define __EF5110_H__
#include "Arduino.h"
#include <avr/pgmspace.h>

class EF_LCM5110
{
   public:
     EF_LCM5110(int CE, int RST, int DC, int MOSI, int CLK);
     void init(void);
     void clearLCM(void);
     void set_XY(unsigned char X, unsigned char Y);
     void write_char(unsigned char c);
     void write_string(unsigned char X,unsigned char Y,char *s);
     
   private:
     int CE, RST, DC, MOSI, CLK;
     void write_byte(unsigned char data, unsigned char command);
  
};
#endif
