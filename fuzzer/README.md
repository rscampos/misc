Syscall Fuzzer
---

|

all_syscall.sh
	|
	| (pass syscall number)
	|
	`--> syscall_num.sh
		|
		| (pass syscall parameters)
		|
		`--> ./poc par1 par2 par3

The file poc is a ELF file modified at machine code to do syscall correctly.
The file poc.c after compiled need to be modified.

TODO:
- Fix the problem with the compilation.
- Create a syscall and test the fuzzer.
- Utilizar o sysenter ao invés de 'int 0x80'. 
