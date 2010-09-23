
;	Created @ 07.10.2009 by TheFox@fox21.at
;	Copyright (c) 2009 TheFox@fox21.at
;	
;	This file is part of SmileOS.
;	
;	SmileOS is free software: you can redistribute it and/or modify
;	it under the terms of the GNU General Public License as published by
;	the Free Software Foundation, either version 3 of the License, or
;	(at your option) any later version.
;	
;	SmileOS is distributed in the hope that it will be useful,
;	but WITHOUT ANY WARRANTY; without even the implied warranty of
;	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;	GNU General Public License for more details.
;	
;	You should have received a copy of the GNU General Public License
;	along with SmileOS.  If not, see <http://www.gnu.org/licenses/>.

;	Bootstrap loader


global loader
extern main ; main-function in c-kernel

 
FLAGS    equ 0
MAGIC    equ 0x1BADB002       ; magicnumber for GRUB
CHECKSUM equ -(MAGIC + FLAGS) ; checksum
 
section .text
	align 4
	
	MultiBootHeader:
		dd MAGIC       ; magicnumber
		dd FLAGS       ; flags
		dd CHECKSUM    ; checksum
	
	loader:
		mov esp, 0x200000	; stack to the 2mb-limit
		push esp
		
		
		push ebx			; multiboot address to the stack
		
		call main			; call main-function in c-kernel
		
		cli
		hlt

; EOF
