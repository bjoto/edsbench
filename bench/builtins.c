typedef unsigned long size_t;

void *memset(void *s, int c, size_t n)
{
	return __builtin_memset(s, c, n);
}

void *memcpy(void *dest, const void *src, size_t n)
{
	return __builtin_memcpy(dest, src, n);
}

