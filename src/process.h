
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

#ifndef _SMILEOS_PROCESS_H_
#define _SMILEOS_PROCESS_H_

#include "isr.h"
#include "screen.h"
#include "types.h"
#include "system.h"
#include "memory.h"


// process type in struct process_s
#define PROCESS_TYPE_KERNEL ((unsigned char)0x80) // 1000 0000
#define PROCESS_TYPE_DAEMON ((unsigned char)0x40) // 0100 0000
#define PROCESS_TYPE_NORMAL ((unsigned char)0x01) // 0000 0001
#define PROCESS_TYPE_UNUSED ((unsigned char)0x00) // 0000 0000

#define PROCESS_MAX ((unsigned short)2000) // 0xffff 10000 // TODO: limit


typedef unsigned short pid_t; // short

struct process_s{
	struct cpu_s *cpu;
	pid_t pid; // process id
	pid_t ppid; // parent process id
	unsigned char type;
	unsigned char priority; // from 0 to 16
} __attribute__((packed));


void task_a(void);
void task_b(void);
void task_c(void);
void initMultitasking();
void processInit(void *);
void processExit(pid_t);
struct cpu_s *processSchedule(struct cpu_s *);
void syscExit();
void syscExec();


#endif

// EOF
