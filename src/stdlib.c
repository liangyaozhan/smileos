
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


#include "stdlib.h"


char *itos(long i, unsigned short d){
	
	static char rv[1024], rv2[1024];
	char numset[] = "0123456789abcdef";
	unsigned short n, len;
	
	memset(rv, 0, 1024);
	memset(rv2, 0, 1024);
	
	if(i == 0)
		return (char *)((char []){ '0', 0 });
	
	
	for(len = 0; i > 0; i = (i - i % d) / d, len++)
		rv[len] = numset[i % d];
	
	
	for(n = len; n > 0; n--)
		rv2[n - 1] = rv[len - n];
	
	
	
	return rv2;
}

void sleep(unsigned int msec){
	// TODO: sleep
	unsigned int n;
	for(n = 0; n < 1000 * 1000 * 10; n++);
}

unsigned strlen(const char *str){
	unsigned len = 0;
	for(; str[0] != 0; str++, len++);
	return len;
}

void strcpy(char *dst, const char *src){
	unsigned len = strlen(src), n;
	for(n = 0; n < len; n++)
		dst[n] = src[n];
}

void strcat(char *dst, const char *src){
	strcpy(dst + strlen(dst), src);
}

void memset(void *dst, unsigned char c, unsigned long long len){
	unsigned long long n;
	for(n = 0; n < len; n++, dst++)
		*(unsigned char *)dst = c;
}

void memcpy(void *dst, void *src, unsigned long long len){
	unsigned long long n;
	for(n = 0; n < len; n++, dst++, src++)
		*(char *)dst = *(char *)src;
}

char *bsipre(long i){
	// byte si prefixes
	// http://en.wikipedia.org/wiki/SI_prefix
	
	const char *prefixes[] = { "Byte", "kB", "MB", "GB", "TB", "PB", "EB" };
	const unsigned short unit = 1024;
	static char rv[1024];
	unsigned char n;
	
	memset(rv, 0, 1024);
	
	for(n = 0; i >= unit; i /= unit, n++);
	strcpy(rv, itos((int)i, 10));
	strcat(rv, " ");
	strcat(rv, prefixes[n]);
	
	return rv;
}


// EOF
