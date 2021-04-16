#if defined(MC_BENCH)
#include "monocypher.h"
#include "optional/monocypher-ed25519.h"

volatile unsigned char *private_key;
volatile unsigned char *public_key;

#elif defined(TN_BENCH)
#include "tweetnacl.h"

volatile unsigned char *signing_key;
volatile unsigned long long *siglen;

#elif defined(C_BENCH)
#include "edsign.h"

volatile unsigned char *private_key;
volatile unsigned char *public_key;

#else
#error
#endif

volatile unsigned char *message;
volatile unsigned long *messagelen;
volatile unsigned char *signature;

void _start(void)
{
#if defined(TN_BENCH)
	crypto_sign(signature, siglen, message, *messagelen, signing_key);
#elif defined(MC_BENCH)
	crypto_ed25519_sign(signature, private_key, public_key, message, *messagelen);
#elif defined(C_BENCH)
        edsign_sign(signature, public_key, private_key, message, *messagelen);
#endif
}

