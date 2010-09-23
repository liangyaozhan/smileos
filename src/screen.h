
/*
	Created @ 11.10.2009 by TheFox@fox21.at
	Copyright (c) 2009 TheFox@fox21.at
	
	This file is part of SmileOS.
	
	SmileOS is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	SmileOS is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with SmileOS.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SMILEOS_SCREEN_H_
#define _SMILEOS_SCREEN_H_

#include "types.h"
#include "stdlib.h"


#define SCREEN 0x000B8000
#define ROWS 25
#define COLS 80
#define SCROLL_OFFSET 5 // set to 0 to kill the version, copyright and license text on startup

#define TEXTC_BLACK				0x0
#define TEXTC_BLUE				0x1
#define TEXTC_GREEN				0x2
#define TEXTC_CYAN				0x3
#define TEXTC_RED				0x4
#define TEXTC_MAGENTA			0x5
#define TEXTC_BROWN				0x6
#define TEXTC_LGREY				0x7
#define TEXTC_DBLUE				0x8
#define TEXTC_LBLUE				0x9
#define TEXTC_LGREEN			0xA
#define TEXTC_LCYAN				0xB
#define TEXTC_LRED				0xC
#define TEXTC_LMAGENTA			0xD
#define TEXTC_YELLOW			0xE
#define TEXTC_WHITE				0xF
#define TEXTC_DEFAULT			TEXTC_LGREY


void screenClear();
void screenScroll();
void putc(unsigned char);
void putcxy(unsigned short, unsigned short, unsigned char);
void puts(const char *);
void puti(unsigned int);
void setTextColor(unsigned short);
void setTextBgColor(unsigned short);
void printk(const char *, ...);
void moveCursor(unsigned short, unsigned short);


#endif // _SMILEOS_SCREEN_H

// EOF
