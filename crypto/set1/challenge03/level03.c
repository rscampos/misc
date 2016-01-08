/*
==========[ Single-byte XOR cipher ]==========
http://cryptopals.com/sets/1/challenges/3/

The hex encoded string:

1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736
... has been XOR'd against a single character. Find the key, decrypt the message.

You can do this by hand. But don't: write code to do it for you.

How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.

==[ Achievement Unlocked
You now have our permission to make "ETAOIN SHRDLU" jokes on Twitter.

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

/* take the string 'hex' and apply XOR 'byte' with every 'size' bytes from 'hex' */
void * xor_sbcipher(unsigned char *hex, int byte, int size){
	int i;
	unsigned char *xored;

	xored = malloc(size*sizeof(char));

	for(i=0; i < size; i++)
		xored[i] = hex[i]^byte;
	
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
	void *str_hex, *str_xored;
	int byte;
	
	str_hex   = atoh(argv[1]);

	/* single-byte XOR cipher */
	for(byte=0; byte < 256; byte++){
		str_xored = xor_sbcipher(str_hex, byte, strlen(argv[1])/2);
		printf("XOR:0x%x ::",byte);
		print_htoa(str_xored,strlen(argv[1])/2);
		printf("\n");	
	}

}
