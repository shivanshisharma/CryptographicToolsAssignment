/*Shivanshi Sharma
Problem #5 C Code*/

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
	//Required Variables
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *d= BN_new();
	BIGNUM *c = BN_new(); //represents the ciphertext

	
	//Initializing n, e, m, d, c with provided values
	BN_hex2bn(&n, "22E929B981FFC200B13E601177E398F1B965B34FD419420DD8DB603B35286145");
	BN_hex2bn(&e, "9EF23");
	BN_hex2bn(&m, "506c6174653a2041424344203132333b204661696c65642053746f70");
	BN_hex2bn(&d, "07A0CC8B662312154E670D2B767A6E5FE4607BE3215AE3CCD710D1418828D507");
	BN_hex2bn(&c, "19C308D172F3E6CB4A9E2D93FC75D662B97C6743FF94BE50CF5F788106C8AA71"); //ciphertext
	
	//Decrypting the ciphertext using m = c^d mod n
	BN_mod_exp(m, c, d, n, ctx);
	printBN("The Original text which was sent (in hex) is: ", m);

	return 0;
}
