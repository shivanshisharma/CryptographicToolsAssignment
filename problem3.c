/* Shivanshi Sharma
problem 3 c file */

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


int main () { //as given in assignment

	BN_CTX *ctx = BN_CTX_new();
	// the required variables
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *d = BN_new();
	BIGNUM *phi = BN_new();

	//Additional variables
	BIGNUM *x = BN_new();
	BN_dec2bn(&x,"1");
	BIGNUM *pnew = BN_new();
	BIGNUM *qnew = BN_new();

	//Initializing p, q, e with values provided
	BN_hex2bn(&p, "B5E26E74EB5068C447D660920255A6EF");
	BN_hex2bn(&q, "3122EFFD6FF0246608195B81D3111B0B");
	BN_hex2bn(&e, "34CA9");

	//n = p*q
	BN_mul(n, p, q, ctx);
	
	//Calculatng phi: 
	BN_sub(pnew, p, x); // pnew = p - x
	BN_sub(qnew, q, x); // qnew = q - x
	
	BN_mul(phi, pnew, qnew, ctx); // phi = pnew * qnew
	
	// Computing modular multiplicative inverse, so (e*d) mod phi = 1
	BN_mod_inverse(d, e, phi, ctx);
	printBN("private key value d (hex): ", d);

	return 0;
} //end main
