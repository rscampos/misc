#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex(unsigned int *address, int size){
	int i=0;
	printf("00: ");
	for(i; i < size; i++){
		printf("0x%.2x ", (unsigned char) *address);
		if (((i+1) %8 == 0) && i > 0){
			printf("\n%.2d: ", i+1);
		}
	}
	printf("\n");
}
void main(int argc, char **argv){
	FILE *elf_fd;
	Elf32_Ehdr elf_header;
	ssize_t elf_sheader;
	unsigned int header[52];

	if(argc < 2){
		printf("Usage: %s elf_object\n", argv[0]);
		exit(0);
	}
	memset(header, '\0', 52);
	print_hex(header, 52);
	
	printf("File: %s\n", argv[1]);
	
	elf_fd = fopen(argv[1],"r");
	//elf_sheader = read(elf_fd, &elf_header, sizeof(Elf32_Ehdr));
	elf_sheader = read(elf_fd, &header, sizeof(Elf32_Ehdr));
	printf("Size:%d\n", elf_sheader);

}
