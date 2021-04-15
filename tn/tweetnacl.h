#ifndef TWEETNACL_H
#define TWEETNACL_H

#define crypto_sign_PRIMITIVE "ed25519"
#define crypto_sign_BYTES 64
#define crypto_sign_PUBLICKEYBYTES 32
#define crypto_sign_SECRETKEYBYTES 64


extern int crypto_sign(unsigned char *,unsigned long long *,const unsigned char *,unsigned long long,const unsigned char *);

#endif
