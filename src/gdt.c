
/*
	Created @ 13.10.2009 by TheFox@fox21.at
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
		Global Descriptor Table
	
	Arch: 386+
*/


#include "gdt.h"


static unsigned long long gdt[GDT_ENTRIES];
unsigned long tss[32] = { 0, 0, 0x10 };

struct{
	unsigned short limit;
	unsigned base;
} __attribute__((packed)) gdtp = {
	.limit = GDT_ENTRIES * 8 - 1,
	.base = (unsigned)&gdt,
};


static void gdtSetEntry(int, unsigned, unsigned, int);
static void gdtLoad();


void gdtInit(){
	
	// null descriptor
	gdtSetEntry(0, 0, 0, 0);
	
	// kernel codesegment
	// 1 * 0x08 = 0x08
    gdtSetEntry(1, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_CODESEG | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT);
    
    // kernel datasegment
	// 2 * 0x08 = 0x10
    gdtSetEntry(2, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_DATASEG | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT);
    
    // userspace codesegment
    // 3 * 0x08 = 0x18
    gdtSetEntry(3, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_CODESEG | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT | GDT_FLAG_RING3);
    
    // userspace datasegment
    // 4 * 0x08 = 0x20
    gdtSetEntry(4, 0, 0xfffff, GDT_FLAG_SEGMENT | GDT_FLAG_32_BIT | GDT_FLAG_DATASEG | GDT_FLAG_4K_GRAN | GDT_FLAG_PRESENT | GDT_FLAG_RING3);
    
    // task state segment
    // 5 * 0x08 = 0x28
    gdtSetEntry(5, (unsigned int)tss, sizeof(tss), GDT_FLAG_TSS | GDT_FLAG_PRESENT | GDT_FLAG_RING3);
    
	
	gdtLoad();
	
}

static void gdtSetEntry(int n, unsigned base, unsigned limit, int flags){
	
	gdt[n] = limit & 0xffffLL;
    gdt[n] |= (base & 0xffffffLL) << 16;
    gdt[n] |= (flags & 0xffLL) << 40;
    gdt[n] |= ((limit >> 16) & 0xfLL) << 48;
    gdt[n] |= ((flags >> 8) & 0xffLL) << 52;
    gdt[n] |= ((base >> 24) & 0xffLL) << 56;
    
}

static void gdtLoad(){
	
	// reload global descriptor table
	asm volatile("lgdt %0" : : "m"(gdtp));
	
	// reload task state segment
	asm volatile(
		"mov $0x28, %ax;"
		"ltr %ax"
	);
	
	asm volatile(
		//"mov $0x10, %%ax;"
		"mov %0, %%ax;"
		"mov %%ax, %%ds;"
		"mov %%ax, %%es;"
		"mov %%ax, %%fs;"
		"mov %%ax, %%gs;"
		"mov %%ax, %%ss;"
		
		//"jmp $0x8, $.kernelCodeSegment;"
		"jmp %1, $.kernelCodeSegment;"
		".kernelCodeSegment:;"
		:
		: "O"(GDT_KERNEL_DATASEG), "O"(GDT_KERNEL_CODESEG)
	);
	
}


// EOF
