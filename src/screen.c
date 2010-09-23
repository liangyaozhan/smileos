
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

/*
	Description:
		Screen functions.
*/


#include "screen.h"


static unsigned short cursor = 0;
static unsigned short textColor = TEXTC_DEFAULT << 8;  // second byte, low
static unsigned short textBgColor = TEXTC_BLACK << 12; // second byte, high


void screenClear(){
	unsigned short *screen = (unsigned short *)SCREEN;
	unsigned short n;
	
	for(n = 0; n < ROWS * COLS; n++)
		screen[n] = textColor | (unsigned char)' ';
}

void screenScroll(){
	unsigned short *screen = (unsigned short *)SCREEN;
	unsigned short r, c;
	
	for(r = SCROLL_OFFSET; r < ROWS; r++)
		for(c = 0; c < COLS; c++)
			screen[r * COLS + c] = screen[(r + 1) * COLS + c];
}

void putc(unsigned char c){
	unsigned short *screen = (unsigned short *)SCREEN;
	
	if(cursor >= ROWS * COLS){
		cursor -= COLS;
		screenScroll();
	}
	screen[cursor++] = textBgColor | textColor | c;
	
}

void putcxy(unsigned short x, unsigned short y, unsigned char c){
	unsigned short *screen = (unsigned short *)SCREEN;
	
	screen[x * COLS + y] = textColor | (unsigned char)c;
}

void puts(const char *s){
	for(; *s; s++)
		putc(s[0]);
}

void puti(unsigned int i){
	puts(itos(i, 10));
}

void setTextColor(unsigned short newcolor){
	textColor = newcolor << 8;
}

void setTextBgColor(unsigned short newcolor){
	textBgColor = newcolor << 12;
}

void printk(const char *format, ...){
	unsigned *arg = (unsigned *)&format, argc = 1;
	unsigned short n;
	
	while(format[0]){
		if(format[0] == '%'){
			format++;
			switch(format[0]){
				
				case 's': // string
					if((char *)arg[argc] == null)
						puts("(null)");
					else
						puts((char *)arg[argc]);
					argc++;
				break;
				
				case 'd': // decimal
					puts(itos((int)arg[argc++], 10));
				break;
				
				case 'x': // hex
				case 'h':
					puts(itos((int)arg[argc++], 0x10));
				break;
				
				case 'o':
					puts(itos((int)arg[argc++], 8));
				break;
				
				case 'c':
					putc((char)arg[argc++]);
				break;
				
				case 'C': // color
					setTextColor(arg[argc++]);
				break;
				
				case 'B': // color
					setTextBgColor(arg[argc++]);
				break;
				
				default: putc('%');
				
			}
		}
		else if(format[0] == '\n')
			cursor += COLS - cursor % COLS;
		else if(format[0] == '\r')
			cursor -= cursor % COLS;
		else if(format[0] == '\t')
			for(n = 0; n < 4; n++)
				putc(' ');
		else
			putc(format[0]);
		
		format++;
	}	
}

void moveCursor(unsigned short x, unsigned short y){
	//unsigned short z = y << 8 | x;
	
	
}

// EOF
