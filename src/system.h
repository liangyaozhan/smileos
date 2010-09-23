
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

#ifndef _SMILEOS_SYSTEM_H_
#define _SMILEOS_SYSTEM_H_

#include "screen.h"

#define CPU_EFLAGS_IF			0x200 // interrupt flag


struct cpu_s{
	unsigned ds;
	unsigned eax, ebx, ecx, edx;
	unsigned esi, edi, ebp;
	unsigned intNo, errorNo;
	unsigned eip, cs, eflags, esp, ss;
} __attribute__((packed));


inline void outb(unsigned short, unsigned char);
inline void outw(unsigned short, unsigned short);
inline unsigned char inb(unsigned short);
inline unsigned short inw(unsigned short);
void systemReboot();
void systemPanic(const char *);


#endif

// EOF
