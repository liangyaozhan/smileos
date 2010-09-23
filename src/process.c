
/*
	Created @ 12.10.2009 by TheFox@fox21.at
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


#include "process.h"

#define DEBUG 1
#define DDELAY 1000 * 1000 * 2 // debug delay



pid_t cpid = 0; // current running process
static pid_t fpid = 1; // last free process id. 0 = kernel
struct process_s *process; // this pointerarray referres to processStruct
char *processStruct; // memory for "struct process_s *process"
struct process_s *processStructLast;
char *t;


static void findNextFid();


char kernelStack_a[4096], userStack_a[4096]; // kernelStack2_a[4096], 
char kernelStack_b[4096], userStack_b[4096]; // kernelStack2_b[4096], 
char kernelStack_c[4096], userStack_c[4096]; // kernelStack2_c[4096], 

void task_a(void){
	
	unsigned short i = 0;
	
	while(1){
		
		printk("1");
		
#ifdef DEBUG
		unsigned long n; for(n = 0; n < DDELAY; n++);
#endif
		i++;
		if(i == 10)
			syscExec();
		else if(i == 20);
			syscExit();
	}
	
}


void task_b(void){
	
	//asm volatile("int $0");
	asm volatile("mov $2, %eax");
	
	while(1){
		
		printk("2");
		
#ifdef DEBUG
		unsigned long n; for(n = 0; n < DDELAY; n++);
#endif
		
		//asm volatile("cli; hlt;");
		
	}
	
}


void task_c(void){
	
	asm volatile("mov $3, %eax");
	
	while(1){
		
		printk("3");
		
#ifdef DEBUG
		unsigned long n; for(n = 0; n < DDELAY; n++);
#endif
		
	}
	
}


void initMultitasking(){
	
	//t = (char *)pmmAllocNext(1024 * 1024 * 10); printk("t = %x\n", t);
	
	unsigned int msize = sizeof(struct process_s) * PROCESS_MAX;
	process = (struct process_s *)pmmAllocNext(msize);
	memset(process, 0, PROCESS_MAX);
	
	processStruct = (char *)pmmAllocNext(sizeof(struct process_s) * PROCESS_MAX);
	if(processStruct == null)
		systemPanic(__FILE__ ": No free memory\n");
	processStructLast = (struct process_s *)processStruct;
	memset(processStruct, 0, msize);
	
	
	printk("max=%d msize=%d base=%x to %x\n", PROCESS_MAX, msize, process, (unsigned int)process + msize);
	//printk("struct process_s = %d, %d, %d, %d, %d, %d\n", PROCESS_MAX, sizeof(struct process_s), sizeof(process), sizeof(struct process_s *), sizeof(struct process_s *) * PROCESS_MAX, sizeof(struct process_s) * PROCESS_MAX);
	
	processInit(task_a);
	processInit(task_b);
	//processInit(task_c);
	
	
	unsigned long n; for(n = 0; n < 1000 * 1000 * 10; n++);
}

void processInit(void *entry){
	
	unsigned int size = 4096;
	
	
	char *kernelStack = (char *)pmmAllocNext(size);
	//char *kernelStack2 = (char *)pmmAllocNext(size);
	char *userStack = (char *)pmmAllocNext(size);
	/*
	kernelStack = (char *)pmmAllocNext(size);
	kernelStack2 = (char *)pmmAllocNext(size);
	userStack = (char *)pmmAllocNext(size);
	*/
	
	memset(kernelStack, 0, size);
	//memset(kernelStack2, 0, size);
	memset(userStack, 0, size);
	
	
	struct process_s proc = {
		.pid = fpid,
		.ppid = 0,
		.type = PROCESS_TYPE_NORMAL,
		.priority = 0
	};
	
	//printk("processInit id=%d, %x, %x, %x\n", fpid, kernelStack, kernelStack2, userStack);
	
	
	struct cpu_s newState = {
		.eax = 0,
		.ebx = 0,
		.ecx = 0,
		.edx = 0,
		
		.esi = 0,
		.edi = 0,
		.ebp = 0,
		.esp = (unsigned long)userStack + 4096,
		.eip = (unsigned long)entry,
		
		/*
		.cs = 0x08,
		.ss = 0x10,
		*/
		
		.cs = 0x18 | 0x03,
		.ss = 0x20 | 0x03,
		//.ds = 0xCEFAADDE,
		
		/*
		.cs = 0x18,
		.ss = 0x20,
		*/
		
		//.eflags = 0x202
		//.eflags = 0x002
		.eflags = CPU_EFLAGS_IF
	};
	
	/*
	struct cpu_s *state = (void *)(stack + 4096 - sizeof(newState));
	*state = newState;
	
	printk("processInit newState.esp %x\n", newState.esp);
	printk("processInit newState.eip %x\n", newState.eip);
	*/
	
	
	proc.cpu = (void *)(kernelStack + 4096 - sizeof(newState));
	*proc.cpu = newState;
	
	//process[fpid] = processStructLast;
	/*
	process[fpid] = kernelStack2;
	*process[fpid] = proc;
	*/
	process[fpid] = proc;
	
	/*
	bool looped = false;
	while(((char *)processStructLast)[0] != 0){
		printk("processStructLast %d, %x, ", sizeof(struct process_s), processStructLast);
		processStructLast++;
		printk("next=%x\n", processStructLast);
		if((unsigned long)processStructLast > (unsigned long)processStruct + (unsigned long)(sizeof(struct process_s) * PROCESS_MAX)){
			processStructLast = (struct process_s *)processStruct;
			printk("von vorne\n");
			if(looped)
				systemPanic(__FILE__ ": No free memory for new process.\n");
			looped = true;
		}
	}
	*/
	
	
	
	printk("processInit id=%d, process=%x, regs=%x, %x\n", fpid, &(process[fpid]), proc.cpu);
	findNextFid();
	
}

void processExit(pid_t pid){
	
}

struct cpu_s *processSchedule(struct cpu_s *regs){
	
	
#ifndef DEBUG
	//printk("processSchedule A id=%d, %x, eip=%x esp=%x ebp=%x %x:%x:%x:%x\n", cpid, regs, regs->eip, regs->esp, regs->ebp, regs->eax, regs->ebx, regs->ecx, regs->edx);
#endif
	
	// save the old process status
	//if(process[cpid] != null){
	if(process[cpid].type != PROCESS_TYPE_UNUSED){
		
		//if(cpid >= 1 && process[cpid]->cpu != null){
		if(cpid >= 1 && process[cpid].cpu != null){
#ifndef DEBUG
			//printk("processSchedule save regs: %d, %x = %x\n", cpid, process[cpid]->cpu, regs);
#endif
			//process[cpid]->cpu = regs;
			process[cpid].cpu = regs;
#ifndef DEBUG
			//printk("processSchedule save regs: %d, %x = %x\n", cpid, process[cpid]->cpu, regs);
#endif
		}
	}
	
	// search next process
	bool looped = false;
	do{
		//printk("processSchedule pid %d, %x, %d, %d\r", cpid, &(process[cpid]), process[cpid].type, process[cpid].pid);
		cpid++;
		
		if(cpid == 0 || cpid >= PROCESS_MAX){
			cpid = 1;
			if(looped)
				systemPanic("no more processes\n");
			
			looped = true;
		}
		
	//}while(process[cpid] == null);
	}while(process[cpid].type == PROCESS_TYPE_UNUSED);
	//regs = process[cpid]->cpu;
	regs = process[cpid].cpu;

#ifndef DEBUG
	printk("\n");
	printk("processSchedule E id=%d, p=%x, regs=%x, eip=%x esp=%x ebp=%x %x:%x:%x:%x\n", cpid, &(process[cpid]), regs, regs->eip, regs->esp, regs->ebp, regs->eax, regs->ebx, regs->ecx, regs->edx);
#endif
	
	return regs;
}

static void findNextFid(){
	// find next free process id
	
	if(fpid == 0){
		fpid++;
		return;
	}
	
	bool looped = false;
	//for(; process[fpid] != null; fpid++){
	for(; process[fpid].type != PROCESS_TYPE_UNUSED; fpid++){
		if(fpid >= PROCESS_MAX){
			fpid = 1;
			if(looped)
				systemPanic(__FILE__ ": No free memory for new process.\n");
			looped = true;
		}
	}
}

void syscExit(){
	
}

void syscExec(){
	processInit(task_c);
}


// EOF
