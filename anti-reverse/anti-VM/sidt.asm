; sidt from ring3
; nasm -f elf32 source.asm
; ld source.o -o binary
; objdump -M att -d binary
; Reference: BOOK - Pratical Malware Analysis

; status: temp

global _start
section .text
	_start:
	
	xor eax, eax
	sidt [msg]
	xor eax, eax

msg	db "noob",0
