/*Shivanshi Sharma
Problem #6b C Code*/

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
	//Required variables
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *n = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *s = BN_new();
	BIGNUM *d= BN_new();
	BIGNUM *m = BN_new();
	
	//Initializing n, e, m, d, c
	BN_hex2bn(&n, "22E929B981FFC200B13E601177E398F1B965B34FD419420DD8DB603B35286145");
	BN_hex2bn(&e, "9EF23");
	BN_hex2bn(&m, "506c6174653a204c4d4e4f203435373b20496c6c6567616c205475726e");
 //making a slight change to M
	BN_hex2bn(&d, "07A0CC8B662312154E670D2B767A6E5FE4607BE3215AE3CCD710D1418828D507");
	
	//Generating Signature for the original message 
	BN_mod_exp(s, m, d, n, ctx); //s = m^d mod n
	printBN("The signature for the given message (in hex) is: ", s);

	//Verifying the original text message to see if the the signaure is right
	BN_mod_exp(m, s, e, n, ctx); // m = s^e mod n
	printBN("The original text message which was used to generate the signature (in hex) was: ", m);

	return 0;
}//end main
