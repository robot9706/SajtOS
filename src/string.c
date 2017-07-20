#include "string.h"

size_t strlen(const char* str)
{
	size_t ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}

bool strcomp(const char* a, const char* b)
{
	int lna = strlen(a);
	int lnb = strlen(b);
	
	if (lna != lnb)
		return false;
	
	for (int x = 0;x<lna;x++)
	{
		if(a[x] != b[x])
		{
			return false;
		}
	}
	
	return true;
}