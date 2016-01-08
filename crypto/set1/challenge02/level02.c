/*
==========[ Fixed XOR ]==========
http://cryptopals.com/sets/1/challenges/2/

Write a function that takes two equal-length buffers and produces their XOR combination.
If your function works properly, then when you feed it the string:

1c0111001f010100061a024b53535009181c

... after hex decoding, and when XOR'd against:

686974207468652062756c6c277320657965

... should produce:

746865206b696420646f6e277420706c6179

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Convert ASCII string to hex */
void * atoh(char * ascii){
	char *str_hex, temp;
	int s_ascii, s_hex, i=0;

	s_ascii = strlen(ascii);
	str_hex = malloc((s_ascii/2)*sizeof(char));
	
	for(i; i < s_ascii; i++){
		
		if(isdigit(ascii[i]))
			temp = ascii[i] - 0x30;
		else
			temp = toupper(ascii[i]) - 0x37;

		if(i%2==0)
			str_hex[i/2] = temp<<4;
		else
			str_hex[i/2] = str_hex[i/2] | temp;

	}
		
	return str_hex;
}

void * xor(unsigned char *hex1, unsigned char *hex2, int size){
	int i;
	unsigned char *xored;

	xored = malloc(size*sizeof(char));

	for(i=0; i < size; i++)
		xored[i] = hex1[i]^hex2[i];
	
	return xored;
}

/* interpret a single byte - hex to ASCII */
void print_htoa(unsigned char *hex, int size){
	int i;
	for(i=0; i < size; i++)
		printf("%c",hex[i]);
}

/* just show the byte hex - don't interpret the byte*/
void print_hex(unsigned char *hex, int size){
	int i;
	char * str_hex, low, high;
	str_hex = malloc((size+1)*sizeof(char));
	
	for(i=0; i < size; i++){
		low  = hex[i] & 0xF; /* low */
		high = (hex[i] & 0xF0) >> 4; /* high */
		
		str_hex[i*2] = high + (high > 9 ? 0x37: 0x30);
		str_hex[i*2+1] = low + (low > 9 ? 0x37: 0x30);
	}

	str_hex[size] = '\0';

	printf("%s",str_hex);
			
}

void main(int argc, char ** argv){
	void *str_hex1, *str_hex2, *str_xored;
	
	if(strlen(argv[1]) != strlen(argv[2])){
		printf("XOR between string1 and string2 - must be the same size.\n");	
		printf("Usage:%s string1_hex string2_hex\n",argv[0]);
		exit(0);
	}
	
	str_hex1  = atoh(argv[1]);
	str_hex2  = atoh(argv[2]);
	str_xored = xor(str_hex1, str_hex2, strlen(argv[1]));
	
	printf("[+] String 1:\n");
	printf(" [-] ASCII: ");
	print_htoa(str_hex1,strlen(argv[1])/2);
	printf("\n");
	printf(" [-] HEX  : %s\n", argv[1]);

	printf("[+] String 2:\n");
	printf(" [-] ASCII: ");
	print_htoa(str_hex2,strlen(argv[2])/2);
	printf("\n");
	printf(" [-] HEX  : %s\n", argv[2]);

	printf("[+] After XORed:\n");
	printf(" [-] ASCII: ");
	print_htoa(str_xored,strlen(argv[2])/2);
	printf("\n");
	printf(" [-] HEX  : ");
	print_hex(str_xored,strlen(argv[2]));
	printf("\n");

}
