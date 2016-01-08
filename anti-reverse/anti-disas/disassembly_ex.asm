; Simple disassembly example 
; nasm -f elf32 source.asm
; ld source.o -o binary
; objdump -M intel -d binary

global _start
section .text
	_start:
		xor eax, eax
		inc eax
		dec eax
		mov ebx, eax
		xor eax, eax

		; exit syscall
		mov eax, 1
		int 80h
