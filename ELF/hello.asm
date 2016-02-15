; Raphael Campos Silva <raphaelcampos.rp@gmail.com>
; 14/01/2016
;
; nasm -f elf32 source.asm
; ld source.o -o binary
; objdump -M att -d binary

global _start
section .text
	do_write:
		mov eax, 4h
		mov ebx, 1h
		mov ecx, msg
		mov edx, 5h
		ret

	_start:
		; write hello
		call do_write

		; exit
		xor eax, eax
		inc eax
		int 0x80

msg	db "hello",0
