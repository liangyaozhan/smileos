
/*
	Created @ 15.10.2009 by TheFox@fox21.at
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
		Interrupt Service Routine
*/


#include "isr.h"


const char *isrMsg[] = {
	// Exceptions
	/* 0x00 */ "Division by Zero",
	/* 0x01 */ "Debugging",
	/* 0x02 */ "NMI",
	/* 0x03 */ "Breakpoint",
	/* 0x04 */ "INTO DETECTED OVERFLOW",
	/* 0x05 */ "BOUND RANGE EXCEEDED",
	/* 0x06 */ "INVALID OPCODE",
	/* 0x07 */ "PROCESSOR EXTENSION NOT AVAILABLE",
	/* 0x08 */ "DOUBLE EXCEPTION DETECTED",
	/* 0x09 */ "PROCESSOR EXTENSION PROTECTION ERROR",
	/* 0x0a */ "INVALID TASK STATE SEGMENT",
	/* 0x0b */ "SEGMENT NOT PRESENT",
	/* 0x0c */ "STACK FAULT",
	/* 0x0d */ "GENERAL PROTECTION VIOLATION",
	/* 0x0e */ "PAGE FAULT",
	/* 0x0f */ "PARALLEL PRINTER",
	
	/* 0x10 */ "COPROCESSOR ERROR",
	/* 0x11 */ "N/A",
	/* 0x12 */ "N/A",
	/* 0x13 */ "N/A",
	/* 0x14 */ "N/A",
	/* 0x15 */ "N/A",
	/* 0x16 */ "N/A",
	/* 0x17 */ "N/A",
	/* 0x18 */ "N/A",
	/* 0x19 */ "N/A",
	/* 0x1a */ "N/A",
	/* 0x1b */ "N/A",
	/* 0x1c */ "SYSTEM TIMER TICK",
	/* 0x1d */ "N/A",
	/* 0x1e */ "N/A",
	/* 0x1f */ "N/A",
	// Exceptions end
	
	// IRQs
	/* 0x20 */ "SYSTEM TIMER TICK",
	/* 0x21 */ "KEYBOARD",
	/* 0x22 */ "N/A",
	/* 0x23 */ "N/A",
	/* 0x24 */ "N/A",
	/* 0x25 */ "N/A",
	/* 0x26 */ "N/A",
	/* 0x27 */ "N/A",
	/* 0x28 */ "N/A",
	/* 0x29 */ "N/A",
	/* 0x2a */ "N/A",
	/* 0x2b */ "N/A",
	/* 0x2c */ "N/A",
	/* 0x2d */ "N/A",
	/* 0x2e */ "N/A",
	/* 0x2f */ "N/A",
	// IRQs end
	
	/* 0x30 */ "N/A",
	/* 0x31 */ "N/A",
	/* 0x32 */ "N/A",
	/* 0x33 */ "N/A",
	/* 0x34 */ "N/A",
	/* 0x35 */ "N/A",
	/* 0x36 */ "N/A",
	/* 0x37 */ "N/A",
	/* 0x38 */ "N/A",
	/* 0x39 */ "N/A",
	/* 0x3a */ "N/A",
	/* 0x3b */ "N/A",
	/* 0x3c */ "N/A",
	/* 0x3d */ "N/A",
	/* 0x3e */ "N/A",
	/* 0x3f */ "N/A",
	
	/* 0x40 */ "N/A",
	/* 0x41 */ "N/A",
	/* 0x42 */ "N/A",
	/* 0x43 */ "N/A",
	/* 0x44 */ "N/A",
	/* 0x45 */ "N/A",
	/* 0x46 */ "N/A",
	/* 0x47 */ "N/A",
	/* 0x48 */ "N/A",
	/* 0x49 */ "N/A",
	/* 0x4a */ "N/A",
	/* 0x4b */ "N/A",
	/* 0x4c */ "N/A",
	/* 0x4d */ "N/A",
	/* 0x4e */ "N/A",
	/* 0x4f */ "N/A",
	
	/* 0x50 */ "N/A",
	/* 0x51 */ "N/A",
	/* 0x52 */ "N/A",
	/* 0x53 */ "N/A",
	/* 0x54 */ "N/A",
	/* 0x55 */ "N/A",
	/* 0x56 */ "N/A",
	/* 0x57 */ "N/A",
	/* 0x58 */ "N/A",
	/* 0x59 */ "N/A",
	/* 0x5a */ "N/A",
	/* 0x5b */ "N/A",
	/* 0x5c */ "N/A",
	/* 0x5d */ "N/A",
	/* 0x5e */ "N/A",
	/* 0x5f */ "N/A",
	
	/* 0x60 */ "N/A",
	/* 0x61 */ "N/A",
	/* 0x62 */ "N/A",
	/* 0x63 */ "N/A",
	/* 0x64 */ "N/A",
	/* 0x65 */ "N/A",
	/* 0x66 */ "N/A",
	/* 0x67 */ "N/A",
	/* 0x68 */ "N/A",
	/* 0x69 */ "N/A",
	/* 0x6a */ "N/A",
	/* 0x6b */ "N/A",
	/* 0x6c */ "N/A",
	/* 0x6d */ "N/A",
	/* 0x6e */ "N/A",
	/* 0x6f */ "N/A",
	
	/* 0x70 */ "N/A",
	/* 0x71 */ "N/A",
	/* 0x72 */ "N/A",
	/* 0x73 */ "N/A",
	/* 0x74 */ "N/A",
	/* 0x75 */ "N/A",
	/* 0x76 */ "N/A",
	/* 0x77 */ "N/A",
	/* 0x78 */ "N/A",
	/* 0x79 */ "N/A",
	/* 0x7a */ "N/A",
	/* 0x7b */ "N/A",
	/* 0x7c */ "N/A",
	/* 0x7d */ "N/A",
	/* 0x7e */ "N/A",
	/* 0x7f */ "N/A",
	
	/* 0x80 */ "N/A",
	/* 0x81 */ "N/A",
	/* 0x82 */ "N/A",
	/* 0x83 */ "N/A",
	/* 0x84 */ "N/A",
	/* 0x85 */ "N/A",
	/* 0x86 */ "N/A",
	/* 0x87 */ "SmileOS StdCall",
	/* 0x88 */ "N/A",
	/* 0x89 */ "N/A",
	/* 0x8a */ "N/A",
	/* 0x8b */ "N/A",
	/* 0x8c */ "N/A",
	/* 0x8d */ "N/A",
	/* 0x8e */ "N/A",
	/* 0x8f */ "N/A",
	
	/* 0x90 */ "N/A",
	/* 0x91 */ "N/A",
	/* 0x92 */ "N/A",
	/* 0x93 */ "N/A",
	/* 0x94 */ "N/A",
	/* 0x95 */ "N/A",
	/* 0x96 */ "N/A",
	/* 0x97 */ "N/A",
	/* 0x98 */ "N/A",
	/* 0x99 */ "N/A",
	/* 0x9a */ "N/A",
	/* 0x9b */ "N/A",
	/* 0x9c */ "N/A",
	/* 0x9d */ "N/A",
	/* 0x9e */ "N/A",
	/* 0x9f */ "N/A",
	
	/* 0xa0 */ "N/A",
	/* 0xa1 */ "N/A",
	/* 0xa2 */ "N/A",
	/* 0xa3 */ "N/A",
	/* 0xa4 */ "N/A",
	/* 0xa5 */ "N/A",
	/* 0xa6 */ "N/A",
	/* 0xa7 */ "N/A",
	/* 0xa8 */ "N/A",
	/* 0xa9 */ "N/A",
	/* 0xaa */ "N/A",
	/* 0xab */ "N/A",
	/* 0xac */ "N/A",
	/* 0xad */ "N/A",
	/* 0xae */ "N/A",
	/* 0xaf */ "N/A",
	
	/* 0xb0 */ "N/A",
	/* 0xb1 */ "N/A",
	/* 0xb2 */ "N/A",
	/* 0xb3 */ "N/A",
	/* 0xb4 */ "N/A",
	/* 0xb5 */ "N/A",
	/* 0xb6 */ "N/A",
	/* 0xb7 */ "N/A",
	/* 0xb8 */ "N/A",
	/* 0xb9 */ "N/A",
	/* 0xba */ "N/A",
	/* 0xbb */ "N/A",
	/* 0xbc */ "N/A",
	/* 0xbd */ "N/A",
	/* 0xbe */ "N/A",
	/* 0xbf */ "N/A",
	
	/* 0xc0 */ "N/A",
	/* 0xc1 */ "N/A",
	/* 0xc2 */ "N/A",
	/* 0xc3 */ "N/A",
	/* 0xc4 */ "N/A",
	/* 0xc5 */ "N/A",
	/* 0xc6 */ "N/A",
	/* 0xc7 */ "N/A",
	/* 0xc8 */ "N/A",
	/* 0xc9 */ "N/A",
	/* 0xca */ "N/A",
	/* 0xcb */ "N/A",
	/* 0xcc */ "N/A",
	/* 0xcd */ "N/A",
	/* 0xce */ "N/A",
	/* 0xcf */ "N/A",
	
	/* 0xd0 */ "N/A",
	/* 0xd1 */ "N/A",
	/* 0xd2 */ "N/A",
	/* 0xd3 */ "N/A",
	/* 0xd4 */ "N/A",
	/* 0xd5 */ "N/A",
	/* 0xd6 */ "N/A",
	/* 0xd7 */ "N/A",
	/* 0xd8 */ "N/A",
	/* 0xd9 */ "N/A",
	/* 0xda */ "N/A",
	/* 0xdb */ "N/A",
	/* 0xdc */ "N/A",
	/* 0xdd */ "N/A",
	/* 0xde */ "N/A",
	/* 0xdf */ "N/A",
	
	/* 0xe0 */ "N/A",
	/* 0xe1 */ "N/A",
	/* 0xe2 */ "N/A",
	/* 0xe3 */ "N/A",
	/* 0xe4 */ "N/A",
	/* 0xe5 */ "N/A",
	/* 0xe6 */ "N/A",
	/* 0xe7 */ "N/A",
	/* 0xe8 */ "N/A",
	/* 0xe9 */ "N/A",
	/* 0xea */ "N/A",
	/* 0xeb */ "N/A",
	/* 0xec */ "N/A",
	/* 0xed */ "N/A",
	/* 0xee */ "N/A",
	/* 0xef */ "N/A",
	
	/* 0xf0 */ "N/A",
	/* 0xf1 */ "N/A",
	/* 0xf2 */ "N/A",
	/* 0xf3 */ "N/A",
	/* 0xf4 */ "N/A",
	/* 0xf5 */ "N/A",
	/* 0xf6 */ "N/A",
	/* 0xf7 */ "N/A",
	/* 0xf8 */ "N/A",
	/* 0xf9 */ "N/A",
	/* 0xfa */ "N/A",
	/* 0xfb */ "N/A",
	/* 0xfc */ "N/A",
	/* 0xfd */ "N/A",
	/* 0xfe */ "N/A",
	/* 0xff */ "N/A"
	
};


extern unsigned long tss[]; // from gdt.c
extern pid_t cpid; // from process.c

struct cpu_s *isrDefault(struct cpu_s *regs){
	
	//struct cpu_s *newregs = regs;
	struct cpu_s thisregs = *regs;
	
	printk("%C%B", TEXTC_WHITE, TEXTC_RED);
	
	if(thisregs.intNo != 0x20)
		printk("int %x, PID %d err=%d %x:%x:%x %x:%x:%x ",
			thisregs.intNo, cpid, thisregs.errorNo, thisregs.cs, thisregs.ds, thisregs.ss, thisregs.ebp, thisregs.esp, thisregs.eip);
		
		//printk("int %d (0x%x), err=%d (CS=%d) - ", thisregs.intNo, thisregs.intNo, thisregs.errorNo, thisregs.cs);
	//else printk("int %d (0x%x), err=%d (CS=%x DS=%x EBP=%x ESP=%x) - ", thisregs.intNo, thisregs.intNo, thisregs.errorNo, thisregs.cs, thisregs.ds, thisregs.ebp, thisregs.esp);
	
	if(thisregs.intNo <= 0x1f){ // Exceptions
		printk("exception '%s'\n", isrMsg[thisregs.intNo]);
		
		// TODO: terminate process instead of kernel
		printk("kernel halt\n"); asm volatile("cli; hlt;");
	}
	else if(thisregs.intNo >= 0x20 && thisregs.intNo <= 0x2f){ // IRQs
		
		if(thisregs.intNo == 0x20){
			regs = processSchedule(regs);
			//printk("isrDefault: tss=%x, ", tss[1]);
			tss[1] = (unsigned long)(regs + 1);
			//printk("tss=%x, regs=%x, %x\n\n", tss[1], regs, (unsigned long)(regs + 1)); unsigned long n; for(n = 0; n < 1000 * 1000 * 10; n++);
		}
		else
			printk("irq '%s'\n", isrMsg[thisregs.intNo]);
		
		if(thisregs.intNo >= 0x28)
			outb(PIC2, PIC_EOI);
		outb(PIC1, PIC_EOI);
		
	}
	else if(thisregs.intNo >= 0x30){
		printk("'%s'\n", isrMsg[thisregs.intNo]);
		
		if(thisregs.intNo >= 0x87){ // 1987
			// syscalls
			
		}
	}
	
	//printk("isrDefault ende >%d< >%d<\n", regs, newregs);
	
	printk("%C%B", TEXTC_DEFAULT, TEXTC_BLACK);
	
	//while(1);
	return regs;
}

// EOF
