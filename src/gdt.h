
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

#ifndef _SMILEOS_GDT_H_
#define _SMILEOS_GDT_H_

#include "types.h"
#include "screen.h" // only for debug


#define GDT_ENTRIES			6
#define GDT_ENTRY_LEN		8

#define GDT_KERNEL_CODESEG	0x08
#define GDT_KERNEL_DATASEG	0x10

#define GDT_FLAG_DATASEG	0x002
#define GDT_FLAG_CODESEG	0x00a
#define GDT_FLAG_TSS		0x009
 
#define GDT_FLAG_SEGMENT	0x010
#define GDT_FLAG_RING0		0x000
//#define GDT_FLAG_RING1		0x020
//#define GDT_FLAG_RING2		0x040
#define GDT_FLAG_RING3		0x060
#define GDT_FLAG_PRESENT	0x080
 
#define GDT_FLAG_4K_GRAN	0x800 // granularity
#define GDT_FLAG_32_BIT		0x400



void gdtInit();


#endif

// EOF
