#if defined(MC_BENCH)
#include "monocypher.h"
#include "optional/monocypher-ed25519.h"

const unsigned char private_key[32] = {
	0x9b, 0xad, 0x36, 0x0b, 0xc9, 0xf5, 0xbf, 0x9d,
	0xbd, 0x91, 0x24, 0x7a, 0xcb, 0x19, 0x02, 0x26,
	0xb7, 0xbf, 0x7c, 0xfe, 0x7e, 0x32, 0x81, 0xf9,
	0x85, 0x27, 0xb8, 0x32, 0xcf, 0x14, 0x93, 0x9d};

const unsigned char public_key[32] = {
	0xf4, 0x88, 0xbb, 0x52, 0xfc, 0xd5, 0xa6, 0x0e,
	0xc6, 0x83, 0x56, 0x84, 0xff, 0xba, 0x24, 0x57,
	0x9f, 0x6a, 0x64, 0xda, 0x14, 0xfb, 0x5f, 0x1d,
	0x4e, 0xa9, 0x9e, 0xc4, 0x2e, 0xf3, 0x9e, 0x52};

#elif defined(TN_BENCH)
#include "tweetnacl.h"

const unsigned char signing_key[64] = {
	0x9b, 0xad, 0x36, 0x0b, 0xc9, 0xf5, 0xbf, 0x9d,
	0xbd, 0x91, 0x24, 0x7a, 0xcb, 0x19, 0x02, 0x26,
	0xb7, 0xbf, 0x7c, 0xfe, 0x7e, 0x32, 0x81, 0xf9,
	0x85, 0x27, 0xb8, 0x32, 0xcf, 0x14, 0x93, 0x9d,
	0xf4, 0x88, 0xbb, 0x52, 0xfc, 0xd5, 0xa6, 0x0e,
	0xc6, 0x83, 0x56, 0x84, 0xff, 0xba, 0x24, 0x57,
	0x9f, 0x6a, 0x64, 0xda, 0x14, 0xfb, 0x5f, 0x1d,
	0x4e, 0xa9, 0x9e, 0xc4, 0x2e, 0xf3, 0x9e, 0x52};
#else
#error
#endif

const unsigned char message[45] = {
	0x4d, 0x75, 0x6c, 0x6c, 0x76, 0x61, 0x64, 0x20,
	0x69, 0x73, 0x20, 0x74, 0x65, 0x73, 0x74, 0x69,
	0x6e, 0x67, 0x20, 0x54, 0x77, 0x65, 0x65, 0x74,
	0x4e, 0x61, 0x43, 0x6c, 0x20, 0x45, 0x64, 0x32,
	0x35, 0x35, 0x31, 0x39, 0x20, 0x73, 0x69, 0x67,
	0x6e, 0x69, 0x6e, 0x67, 0x2e};

unsigned char signature[64];

void _start(void)
{
#if defined(TN_BENCH)
	unsigned long long siglen = sizeof(signature);

	crypto_sign(signature, &siglen, message, sizeof(message), signing_key);
#elif defined(MC_BENCH)
	crypto_ed25519_sign(signature, private_key, public_key, message, sizeof(message));
#endif
}
