
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


#include "memory.h"


static unsigned bitmap[PMM_BITMAP_SIZE];
static unsigned memMax = 0;


void pmmInit(struct mbs_s *mbs, void *kernelBase, void *kernelEnd){
	
	printk("Memory: low %d kB, high %d kB\n", mbs->memLower, mbs->memUpper);
	printk("Kernel base addr: %x\n", kernelBase);
	printk("Kernel end addr:  %x\n", kernelEnd);
	
	unsigned long n;
	struct mmap_s *mmap = (struct mmap_s *)mbs->mmapAddr;
	struct mmap_s *mmapEnd = (void *)((unsigned *)mbs->mmapAddr + mbs->mmapLen);
	
	// alloc all memory
	for(n = 0; n < PMM_BITMAP_SIZE; n++)
		bitmap[n] = ~PMM_BITMAP_FLAG_FREE;
	
	while(mmap < mmapEnd){
		if(mmap->type == 1){
			struct mmap_s thisMmap = *mmap;
			
			unsigned addr, endAddr = thisMmap.baseLow + thisMmap.lenLow;
			if(mbs->memUpper * 1024 == thisMmap.lenLow)
				memMax = endAddr;
			for(addr = thisMmap.baseLow; addr < endAddr; addr += PMM_PAGE_SIZE)
				pmmFree(addr);
			
		}
		mmap++;
	}
	
	// alloc kernel memory
	pmmAlloc(0, 1); // first block
	for(n = (long)kernelBase; n < (long)kernelEnd; n += PMM_PAGE_SIZE)
		pmmAlloc(n, 1);
	
	// alloc kernel stack
	for(n = 0x00200000; n >= 0x00100000; n -= PMM_PAGE_SIZE)
		pmmAlloc(n, 1);
	
	/*
	pmmAlloc(0x204000);
	pmmAlloc(0x206000);
	pmmAlloc(0x20A000);
	pmmAlloc(0x20B000, 1);
	*/
	
	//pmmAlloc(0x870000);
	
	
}

void pmmAlloc(unsigned long addr, unsigned short pages){
	unsigned short page = addr / PMM_PAGE_SIZE;
	unsigned short p;
	for(p = page + pages; page < p; page++)
		bitmap[page / 32] |= PMM_BITMAP_FLAG_ALLOC << (page % 32);
		//printk("bitmap[%d / 32] |= %d << (%d %% 32); %d\n", page, PMM_BITMAP_FLAG_ALLOC, page, bitmap[page / 32]);
	
}

void *pmmAllocNext(unsigned long len){
	
	unsigned int pagesNeeded = len / PMM_PAGE_SIZE;
	if(len % PMM_PAGE_SIZE)
		pagesNeeded++;
	
	unsigned long n, c = 0;
	for(n = 256; n < PMM_BITMAP_SIZE; n++){ // TODO: n = 0
		//bitmap[n]
		unsigned char i;
		for(i = 0; i < 32; i++){
			
			if(bitmap[n] & (PMM_BITMAP_FLAG_ALLOC << i))
				c = 0;
			else
				c++;
			
			
			if(pagesNeeded == c){
				void *addr = (void *)((32 * n + i - pagesNeeded + 1) * PMM_PAGE_SIZE);
				
				/*printk("bitmap[n] = %d\n", bitmap[n]);
				printk("n = %d\n", n);
				printk("i = %d\n", i);
				printk("pagesNeeded = %d\n", pagesNeeded);
				printk("PMM_PAGE_SIZE = %d\n", PMM_PAGE_SIZE);
				printk("addr = %x\n", addr);*/
				
				pmmAlloc((unsigned long)addr, pagesNeeded);
				return addr;
			}
		}
	}
	return null;
}

void pmmFree(unsigned long addr){
	unsigned int page = addr / PMM_PAGE_SIZE;
	
	bitmap[page / 32] &= ~(PMM_BITMAP_FLAG_ALLOC << (page % 32));
}

unsigned long pmmGetFreeMem(){
	// TODO: pmmGetFreeMem
	// print free memory
	
	printk("print free memory\n");
	
	unsigned long rv = 0;
	unsigned char lastFree = 0;
	unsigned long lastm = 0, n;
	for(n = 0; n < PMM_BITMAP_SIZE; n++){
		if(bitmap[n] == 0){
			if(!lastFree){
				lastFree = 1;
				printk("frei von %x ", (n * 32) * PMM_PAGE_SIZE);
			}
			lastm = (n * 32 + 31) * PMM_PAGE_SIZE;
		}
		else if(bitmap[n] == ~0){
			if(lastFree){
				lastFree = 0;
				printk("bis %x\n", lastm + PMM_PAGE_SIZE - 1);
			}
			lastm = (n * 32 + 31) * PMM_PAGE_SIZE;
		}
		else{
			unsigned char i;
			for(i = 0; i < 32; i++){
				if(bitmap[n] & (PMM_BITMAP_FLAG_ALLOC << i)){
					if(lastFree){
						lastFree = 0;
						printk("bis %x\n", lastm + PMM_PAGE_SIZE - 1);
					}
				}
				else{
					if(!lastFree){
						lastFree = 1;
						printk("frei von %x ", (n * 32 + i) * PMM_PAGE_SIZE);
					}
				}
				lastm = (n * 32 + i) * PMM_PAGE_SIZE;
			}
		}
	}
	printk("print free memory end\n");
	return rv;
}


// EOF
