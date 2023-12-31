#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BIT(n) (1<<(n))

char *byte2bin(uint8_t n, char *binstr) 
{
    // one element per bit (0/1)
    uint8_t binary[8];

    int i = 0;
    for(i = 0; i < 8; i++) {
        binary[i] = n % 2;
        n = n / 2;
    }

    // printing binary array in reverse order
    for (int j = 7, k= 0; j >= 0; j--, k++)
        sprintf(binstr + k, "%d", binary[j]);
        
	return binstr;
}

void print_usage(char *name) {
	printf("Usage: %s <action> <byte> <bit no>\n", name);
	printf("\tWhere: <action> one of 'h'|'l'|'r'|'s'|'t'\n"
		"\t\t <byte> 8-bit integer in hexadecimal\n"
		"\t\t <bit no> of bit to operate on\n");
}

int main(int argc, char *argv[])
{
    char a;	// action: 'h', 'l', 'r', 's', 't'
	unsigned long n; // value to convert must be smaller than 256
	int bit; // bit to operate on: must be between 0 an 7
    char binary[9]; // array for binary representation of n,

	a = argv[1][0];
    if( a != 'h' && a != 'l' && a != 'r' && a != 's' && a != 't' ) {
        print_usage(argv[0]);
        printf("\t<action> must be one of 'h'|'l'|'r'|'s'|'t'\n");
        return 1;
    }
    
    // We are expecting the argument to be an hexadecimal string
    n = strtoul(argv[2],NULL,16);
    if( n < 0 || n > (1 << 8) - 1) {
        print_usage(argv[0]);
        printf("\t<byte> must be non-negative and smaller than 256\n");
        return 1;
    }
    byte2bin(n, &binary);

        
    bit = abs(8-atoi(argv[3])-1);
    if( bit < 0 || bit > 7 ) {
        print_usage(argv[0]);
        printf("\t<bit no> must be between 0 and 7\n");
        return 1;
    }
 
    switch (a){
    case 'h':
        printf("h - %s\n", binary);
        if(binary[bit] == '1'){
            printf("It is 1!\n");
        }
        else{
            printf("It isn't 1!\n");
        }
        break;

    case 'l':
        printf("l - %s\n", binary);
        if(binary[bit] == '0'){
            printf("It is 0!\n");
        }
        else{
            printf("It isn't 0!\n");
        }
        break;

    case 'r':
        printf("r - %s\n", binary);
        binary[bit] = binary[bit] | '1';
        printf("Result -> %s\n", binary);
        break;

    case 's':
        printf("s - %s\n", binary);
        binary[bit] = binary[bit] & '0';
        printf("Result -> %s\n", binary);
        break;

    case 't':
        printf("t - %s\n", binary);
        binary[bit] = binary[bit] ^ binary[bit];
        printf("Result -> %s\n", binary);
        break;

    default:
        printf("Error! Invalid action\n");
        return EXIT_FAILURE;
    }
	// Validate command line arguments
	
	// Print to stdout the binary representation of n
	
	// Do what the user asked and print the result
	
    return 0;
}

