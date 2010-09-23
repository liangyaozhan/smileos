
/*
	Created @ 17.10.2009 by TheFox@fox21.at
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


#include "system.h"


inline void outb(unsigned short port, unsigned char data){
	asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
	//asm("outb %%al,%%dx"::"a"(data),"d"(port));
}

inline void outw(unsigned short port, unsigned short data){
	asm volatile("outw %0, %1" : : "a"(data), "Nd"(port));
}

inline unsigned char inb(unsigned short port){
	register unsigned char rv;
	asm volatile("inb %%dx, %%al" : "=a"(rv) : "d"(port));
	return rv;
}

inline unsigned short inw(unsigned short port){
	register unsigned short rv;
	asm volatile("inw %%dx, %%ax" : "=a"(rv) : "d"(port));
	return rv;
}

void systemReboot(){
	// pc reboot
	unsigned r;
	do{
		r = inb(0x64);
		if(r & 0x01){
			(void)inb(0x60);
			continue;
		};
	} while(r & 0x02);
	outb(0x64, 0xFE);
}

void systemPanic(const char *text){
	puts("Kernel panic: ");
	printk(text);
	printk("Kernel halt.\n");
	asm volatile("cli; hlt;");
}


// EOF
