
;	Created @ 15.10.2009 by TheFox@fox21.at
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

;	Interrupt Service Routine


%macro ISR_STUB 1
	global isrStub%1
	
	isrStub%1:
		
		cli ; disable hardware interrupts
		
		push byte 0 ; push error 0
		push dword %1
		
		jmp isrCommonStub
		
%endmacro

%macro ISR_STUB_ERROR 1
	global isrStub%1
	isrStub%1:
		
		cli ; disable hardware interrupts
		
		push dword %1
		
		jmp isrCommonStub
		
%endmacro

; 0x00 to 0x1f - Exceptions
; 0x20 to 0x2f - IRQs
; 0x30 to 0xff - Software int

; Exceptions
ISR_STUB 0 ; 0x00
ISR_STUB 1
ISR_STUB 2
ISR_STUB 3
ISR_STUB 4
ISR_STUB 5
ISR_STUB 6
ISR_STUB 7
ISR_STUB_ERROR 8
ISR_STUB 9
ISR_STUB_ERROR 10
ISR_STUB_ERROR 11
ISR_STUB_ERROR 12
ISR_STUB_ERROR 13
ISR_STUB_ERROR 14
ISR_STUB 15
ISR_STUB 16
ISR_STUB_ERROR 17
ISR_STUB 18
ISR_STUB 19
ISR_STUB 20
ISR_STUB 21
ISR_STUB 22
ISR_STUB 23
ISR_STUB 24
ISR_STUB 25
ISR_STUB 26
ISR_STUB 27
ISR_STUB 28
ISR_STUB 29
ISR_STUB 30
ISR_STUB 31 ; 0x1f
; Exceptions end

; IRQs
ISR_STUB 32 ; 0x20
ISR_STUB 33
ISR_STUB 34
ISR_STUB 35
ISR_STUB 36
ISR_STUB 37
ISR_STUB 38
ISR_STUB 39
ISR_STUB 40 ; 0x28
ISR_STUB 41
ISR_STUB 42
ISR_STUB 43
ISR_STUB 44
ISR_STUB 45
ISR_STUB 46
ISR_STUB 47 ; 0x2f
; IRQs end

ISR_STUB 48 ; 0x30
ISR_STUB 49
ISR_STUB 50
ISR_STUB 51
ISR_STUB 52
ISR_STUB 53
ISR_STUB 54
ISR_STUB 55
ISR_STUB 56
ISR_STUB 57
ISR_STUB 58
ISR_STUB 59
ISR_STUB 60
ISR_STUB 61
ISR_STUB 62
ISR_STUB 63
ISR_STUB 64
ISR_STUB 65
ISR_STUB 66
ISR_STUB 67
ISR_STUB 68
ISR_STUB 69
ISR_STUB 70
ISR_STUB 71
ISR_STUB 72
ISR_STUB 73
ISR_STUB 74
ISR_STUB 75
ISR_STUB 76
ISR_STUB 77
ISR_STUB 78
ISR_STUB 79
ISR_STUB 80
ISR_STUB 81
ISR_STUB 82
ISR_STUB 83
ISR_STUB 84
ISR_STUB 85
ISR_STUB 86
ISR_STUB 87 ; smileos std syscall
ISR_STUB 88
ISR_STUB 89
ISR_STUB 90
ISR_STUB 91
ISR_STUB 92
ISR_STUB 93
ISR_STUB 94
ISR_STUB 95
ISR_STUB 96
ISR_STUB 97
ISR_STUB 98
ISR_STUB 99
ISR_STUB 100
ISR_STUB 101
ISR_STUB 102
ISR_STUB 103
ISR_STUB 104
ISR_STUB 105
ISR_STUB 106
ISR_STUB 107
ISR_STUB 108
ISR_STUB 109
ISR_STUB 110
ISR_STUB 111
ISR_STUB 112
ISR_STUB 113
ISR_STUB 114
ISR_STUB 115
ISR_STUB 116
ISR_STUB 117
ISR_STUB 118
ISR_STUB 119
ISR_STUB 120
ISR_STUB 121
ISR_STUB 122
ISR_STUB 123
ISR_STUB 124
ISR_STUB 125
ISR_STUB 126
ISR_STUB 127
ISR_STUB 128
ISR_STUB 129
ISR_STUB 130
ISR_STUB 131
ISR_STUB 132
ISR_STUB 133
ISR_STUB 134
ISR_STUB 135
ISR_STUB 136
ISR_STUB 137
ISR_STUB 138
ISR_STUB 139
ISR_STUB 140
ISR_STUB 141
ISR_STUB 142
ISR_STUB 143
ISR_STUB 144
ISR_STUB 145
ISR_STUB 146
ISR_STUB 147
ISR_STUB 148
ISR_STUB 149
ISR_STUB 150
ISR_STUB 151
ISR_STUB 152
ISR_STUB 153
ISR_STUB 154
ISR_STUB 155
ISR_STUB 156
ISR_STUB 157
ISR_STUB 158
ISR_STUB 159
ISR_STUB 160
ISR_STUB 161
ISR_STUB 162
ISR_STUB 163
ISR_STUB 164
ISR_STUB 165
ISR_STUB 166
ISR_STUB 167
ISR_STUB 168
ISR_STUB 169
ISR_STUB 170
ISR_STUB 171
ISR_STUB 172
ISR_STUB 173
ISR_STUB 174
ISR_STUB 175
ISR_STUB 176
ISR_STUB 177
ISR_STUB 178
ISR_STUB 179
ISR_STUB 180
ISR_STUB 181
ISR_STUB 182
ISR_STUB 183
ISR_STUB 184
ISR_STUB 185
ISR_STUB 186
ISR_STUB 187
ISR_STUB 188
ISR_STUB 189
ISR_STUB 190
ISR_STUB 191
ISR_STUB 192
ISR_STUB 193
ISR_STUB 194
ISR_STUB 195
ISR_STUB 196
ISR_STUB 197
ISR_STUB 198
ISR_STUB 199
ISR_STUB 200
ISR_STUB 201
ISR_STUB 202
ISR_STUB 203
ISR_STUB 204
ISR_STUB 205
ISR_STUB 206
ISR_STUB 207
ISR_STUB 208
ISR_STUB 209
ISR_STUB 210
ISR_STUB 211
ISR_STUB 212
ISR_STUB 213
ISR_STUB 214
ISR_STUB 215
ISR_STUB 216
ISR_STUB 217
ISR_STUB 218
ISR_STUB 219
ISR_STUB 220
ISR_STUB 221
ISR_STUB 222
ISR_STUB 223
ISR_STUB 224
ISR_STUB 225
ISR_STUB 226
ISR_STUB 227
ISR_STUB 228
ISR_STUB 229
ISR_STUB 230
ISR_STUB 231
ISR_STUB 232
ISR_STUB 233
ISR_STUB 234
ISR_STUB 235
ISR_STUB 236
ISR_STUB 237
ISR_STUB 238
ISR_STUB 239
ISR_STUB 240
ISR_STUB 241
ISR_STUB 242
ISR_STUB 243
ISR_STUB 244
ISR_STUB 245
ISR_STUB 246
ISR_STUB 247
ISR_STUB 248
ISR_STUB 249
ISR_STUB 250
ISR_STUB 251
ISR_STUB 252
ISR_STUB 253
ISR_STUB 254
ISR_STUB 255 ; 0xff


; isrDefault in isr.c
extern isrDefault
extern printk
extern putc
extern puti

; This is our common ISR stub. It saves the processor state, sets
; up for kernel mode segments, calls the C-level fault handler,
; and finally restores the stack frame.
;isrCommonStub:
;	
;	pusha                    ; Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax
;    mov ax, ds               ; Lower 16-bits of eax = ds.
;    push eax                 ; save the data segment descriptor
;    
;    mov ax, 0x10  ; load the kernel data segment descriptor
;    mov ds, ax
;    mov es, ax
;    mov fs, ax
;    mov gs, ax
;    
;    push esp ; set the "struct cpu_s" pointer
;    call isrDefault ; isrDefault saves the return value to eax
;    mov esp, eax
;    ;pop esp
;
;    pop ebx        ; reload the original data segment descriptor
;    mov ds, bx
;    mov es, bx
;    mov fs, bx
;    mov gs, bx   
;
;    popa           ; pops edi, esi, ebp, esp, ebx, edx, ecx, eax
;    add esp, 8     ; Cleans up the pushed error code and pushed ISR number
;    
;    sti
;    iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP

isrCommonStub:
	
	push ebp
	push edi
	push esi
	push edx
	push ecx
	push ebx
	push eax
	
	xor eax, eax
	mov ax, ds ; save the datasegment selector to the stack
	push eax
	
	xor eax, eax
	mov ax, 0x10 ; load the kernel data segment descriptor
	mov ds, ax
	mov es, ax
	;mov fs, ax
	;mov gs, ax
	
	push esp
	call isrDefault
	mov esp, eax
	
	pop eax
	xor eax, eax
	mov ax, 0x23
	mov ds, ax
	mov es, ax
	;mov fs, ax
	;mov gs, ax
	
	pop eax
	pop ebx
	pop ecx
	pop edx
	pop esi
	pop edi
	pop ebp
	
	add esp, 8 ; pop error code, isr no
	
	
	;sti ; sti in process.c, processInit(), .eflags
	iret ; interrupt return. pops cs, eip, eflags, ss, esp

; EOF
