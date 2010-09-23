
/*
	Created @ 01.11.2009 by TheFox@fox21.at
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

#ifndef _SMILEOS_MEMORY_H_
#define _SMILEOS_MEMORY_H_

#include "screen.h"
#include "stdlib.h"


#define PMM_PAGE_SIZE 4096 
#define PMM_BITMAP_SIZE 32768 // 32768 * 32(int) * PMM_PAGE_SIZE = 4 GB
#define PMM_BITMAP_FLAG_FREE 0
#define PMM_BITMAP_FLAG_ALLOC 1


// multiboot structure
struct mbs_s{
	unsigned flags;
	unsigned memLower;
	unsigned memUpper;
	unsigned bootdevice;
	unsigned cmdline;
	unsigned modsCount;
	unsigned modsAddr;
	unsigned syms[4];
	unsigned mmapLen;
	unsigned mmapAddr;
	unsigned drivesLen;
	unsigned drivesAddr;
	unsigned configTable;
	unsigned bootLoaderName;
	unsigned apmTable;
	unsigned vbeControlInfo;
	unsigned vbeModeInfo;
	unsigned vbeMode;
	unsigned vbeInterfaceSeg;
	unsigned vbeInterfaceOff;
	unsigned vbeInterfaceLen;
} __attribute__((packed));

// entry of multiboot memory map
struct mmap_s{
	unsigned size;
	unsigned baseLow, baseHi;
	unsigned lenLow, lenHi;
	unsigned type;
	
} __attribute__((packed));


void pmmInit(struct mbs_s *, void *, void *);
void pmmAlloc(unsigned long, unsigned short);
void *pmmAllocNext(unsigned long);
void pmmFree(unsigned long);
unsigned long pmmGetFreeMem();


#endif

// EOF
