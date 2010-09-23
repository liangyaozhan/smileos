
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

#ifndef _SMILEOS_STDLIB_H_
#define _SMILEOS_STDLIB_H_

#include "types.h"
#include "screen.h"


char *itos(long, unsigned short);
void sleep(unsigned int);
unsigned strlen(const char *);
void strcpy(char *, const char *);
void strcat(char *, const char *);
void memset(void *, unsigned char, unsigned long long);
void memcpy(void *, void *, unsigned long long);
char *bsipre(long);


#endif

// EOF
