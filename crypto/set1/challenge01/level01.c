/* http://stackoverflow.com/questions/342409/how-do-i-base64-encode-decode-in-c
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Encoding table - 64 characters */
static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

/* Receive any string in hex and convert to base64 */
void * base64encode(char * string){
	int size, s_enc, s_str, pad, div,i=0, j=0, i_e=0, i_inv=0;
	unsigned int triple = 0x0;
	unsigned char *enc_str, *new_str, temp;

	size	= strlen(string);
	pad	= (size % 3);	/* padding */
	div	= (size/3);	/* division */
	pad	= (3 - pad) % 3;
	s_enc	= (div*4) + (pad == 0 ? 0:4); /* size of encoded string */
	s_str	= size + pad; /* size of the new string */
	enc_str = malloc(s_enc * sizeof(char));
	new_str = malloc(s_str * sizeof(char));
	
	/* make the new string */
	strcpy(new_str,string);
	if(pad == 2){
		new_str[s_str-2]=0x00;
		new_str[s_str-1]=0x00;
	}else if(pad == 1){
		new_str[s_str-1]=0x00;
	}

	/* Final operation - break the bytes in chuncks of three bytes and
	 * store then (after encoded) in an alloced buffer.
	 */
	for(i; i < size; i=i+3){
		triple	= new_str[i] << 0x10;
		triple	= triple | (new_str[i+1] << 0x8);
		triple	= triple | new_str[i+2];
		for(j=0; j < 4; j++)
			enc_str[i_e++] = encoding_table[((triple >> 6*j) & 0x0000003F)];
		
		/* invert */
		temp = enc_str[i_e-1];
		enc_str[i_e-1] = enc_str[i_e-4];
		enc_str[i_e-4] = temp;
		temp = enc_str[i_e-2];
		enc_str[i_e-2] = enc_str[i_e-3];
		enc_str[i_e-3] = temp;
	}

	if(pad == 2){
		enc_str[s_enc-2]=0x3D;
		enc_str[s_enc-1]=0x3D;
	}else if(pad == 1){
		enc_str[s_enc-1]=0x3D;
	}

	free(new_str);
	return enc_str;
}

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

void main(int argc, char ** argv){
	void *encoded, *str_hex;	
	str_hex	= atoh(argv[1]);
	encoded = base64encode(str_hex);
	puts(encoded);
}
