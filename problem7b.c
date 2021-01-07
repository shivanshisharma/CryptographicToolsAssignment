/*Shivanshi Sharma
Problem #7 Part b) C Code*/

#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a) {
	//Use BN_bn2hex(a) for hex string
	//Use BN_bn2dec(a) for decimal string
	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

int main () {
	//Required Variable
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *s = BN_new(); //Signature
	BIGNUM *m = BN_new();
	BIGNUM *road_mess = BN_new(); //variable to confirm if its a roadside message's signature

	//Initializing n, e, m, s with new values given
	BN_hex2bn(&n, "22E929B981FFC200B13E601177E398F1B965B34FD419420DD8DB603B35286145");
	BN_hex2bn(&e, "9EF23");
	BN_hex2bn(&m, "506c6174653a20474f4f44203130303b20436c656172205265636f7264");
	BN_hex2bn(&s, "174BC865C9023B4978B807A2CF24B15F4F382D20050307E253373C5AAE246ADD");
 //changed last bit of signature to D from C
	
	//Checking to see if signature belongs to the roadside unit
	BN_mod_exp(road_mess, s, e, n, ctx);
	printBN("The message produced from this signature (in hex) is: ", road_mess);


	return 0;
} //end main
