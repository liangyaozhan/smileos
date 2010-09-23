
/*
	SmileOS/0.0.0   :-)
	We code for your smile. Don't use in case of fire.
	
	Created @ 07.10.2009 by TheFox@fox21.at
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

COMPILING INFOS
	Compiled on
		i686 32-bit, Gentoo Linux 2008.0 (GNU/Linux 2.6.24-gentoo-r3)
	with
		GNU GCC 4.1.1.
	For IA-32 (386+).

*/

/*

REFERENCES
	- http://www.osdever.net/
	- http://lowlevel.brainsware.org/
	- http://www.i8086.de/asm/8086-88-asm.html
	- http://www.ctyme.com/intr/int.htm
	- http://www-2.cs.cmu.edu/afs/cs/user/ralf/pub/WWW/files.html
	- http://assembler.hpfsc.de/
*/

/*

VERSION HISTORY
	0.0.0 - 07.10.2009: Project created :-)
			14.10.2009: GDT
			16.10.2009: IDT
			17.10.2009: PIT
			31.10.2009: Simple mulittasking in Ring3
			02.11.2009: PMM: bitmap alloc, free
			07.11.2009: PMM extended, multitasking with dynamich memory allocation
*/


#include "config.h"
#include "stdlib.h"
#include "screen.h"
#include "gdt.h"
#include "idt.h"
#include "process.h"
#include "memory.h"


extern void loader();
extern void kernelBase;
extern void kernelEnd;


void main(struct mbs_s *mbs, unsigned ebx, unsigned esp){
	
	
	
	
	
	screenClear();
	
	setTextColor(TEXTC_LGREEN);
	printk("\n%C%s :-)%C V. %C%s%C, Release %d (%s)\n", TEXTC_LRED, KERNEL_NAME, TEXTC_DEFAULT, TEXTC_WHITE, KERNEL_VERSION, TEXTC_DEFAULT, KERNEL_RELEASE, KERNEL_BUILD_DATE);
	printk(KERNEL_COPYRIGHT "\n");
	printk("Licensed under " KERNEL_LICENSE ".\n\n");
	
	printk("Init physical memory manager\n");
	pmmInit(mbs, &kernelBase, &kernelEnd);
	//printk("%Cdone%C\n", TEXTC_GREEN, TEXTC_DEFAULT);
	
	
	printk("Init GDT ... ");
	gdtInit();
	printk("%Cdone%C\n", TEXTC_GREEN, TEXTC_DEFAULT);
	
	/*
	unsigned int kdataseg, kcodeseg;
	asm("mov %%ds, %0" : "=g"(kdataseg));
	asm("mov %%cs, %0" : "=g"(kcodeseg));
	
	printk("\tKernel codesegment ... ");
	kcodeseg == GDT_KERNEL_CODESEG ? printk("%Cok", TEXTC_GREEN) : printk("%Cfailed", TEXTC_RED);
	printk("%C\n", TEXTC_DEFAULT);
	
	printk("\tKernel datasegment ... ");
	kdataseg == GDT_KERNEL_DATASEG ? printk("%Cok", TEXTC_GREEN) : printk("%Cfailed", TEXTC_RED);
	printk("%C\n", TEXTC_DEFAULT);
	*/
	
	
	/**/
	printk("Init IDT ... ");
	idtInit();
	printk("%Cdone%C\n", TEXTC_GREEN, TEXTC_DEFAULT);
	
	printk("Test interrupts\n"); asm volatile("push %eax; xor %eax, %eax; int $0x87; pop %eax;");
	
	char *b = (char *)pmmAllocNext(4096);
	printk("b = %x\n", b);
	
	//systemPanic("STOP\n");
	
	printk("Init Multitasking...\n"); initMultitasking(); printk("Init Multitasking done\n");
	asm volatile("sti");
	
	//pmmGetFreeMem();
	
	/*
	asm volatile(
		"push %eax;"
		"xor %eax, %eax;"
		"mov $0x13, %al;"
		"int $0x10;"
		"pop %eax;"
	);
	unsigned char *VGA = (unsigned char *)0xA0000;
	unsigned int x;
	for(x = 0; x < 320 * 200; x++)
		VGA[x] = (unsigned char)128;
	*/
	
	
	// should never be reached
	printk("Kernel infinite loop.");
	while(1);
	
}


// EOF
