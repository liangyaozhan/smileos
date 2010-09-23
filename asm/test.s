
; Created @ 19.10.2009 by TheFox@fox21.at


extern puti

global test1
global test5

test1:
	
	enter 4, 0
	push ebx
	
	; pointer
	mov dword [ebp-4], 1234
	;mov eax, [ebp-4]
	;mov [ebx], eax
	;push ebx
	
	; pointer
	;mov dword [ebp-4], 1234
	;lea eax, [ebp-4]
	;push eax
	
	
	;push 23456
	;push 4445
	;lea eax, [esp]
	;push eax
	
	push 55667
	push 89942
	push esp
	
	
	;call test4
	add esp, 4
	add esp, 4
	add esp, 4
	
	
	pop ebx
	leave
	ret
	
test5:
	
	enter 0, 0
	push ebx
	
	mov eax, esp
	push eax
	call puti
	
	pop ebx
	leave
	ret

