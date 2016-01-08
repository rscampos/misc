#include <stdio.h>
#include <stdlib.h>

void main(int argc, char ** argv){
	int par[4], sys_num;
	par[0]	= 0;
	par[1]	= 0;
	par[2]	= 0;
	par[3]	= 0;
	sys_num = atoi(argv[1]);

	if(argc < 2){
		printf("%s sys_number par1 par2 ... par3\n", argv[0]);
		exit(0);
	}

	printf("Calling syscall:%d - qnt_pars:%d\n", sys_num, argc-2);



	if(argc >= 3) ((par[0] = atoi(argv[2])));	/* first arg 	*/
	if(argc >= 4) ((par[1] = atoi(argv[3])));	/* second arg 	*/
	if(argc >= 5) ((par[2] = atoi(argv[4])));	/* third arg	*/
	//if(argc >= 6) ((par[3] = atoi(argv[5])));	/* fourth arg	*/
	
	asm(		"movl %0, %%eax;"
			"movl %0, %%ebx;"
			"movl %0, %%ecx;"
			"movl %0, %%edx;"
			"int $0x80"
 			:: "r" (sys_num), "r" (par[0]), "r" (par[1]), "r" (par[2]));

//	exit(0);
}
