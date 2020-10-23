#include <iostream>
#include <stdio.h>
using namespace std;

typedef unsigned char *bype_pointer;

void show_bytes(bype_pointer start, size_t len)	{
	size_t i;
	for(i = 0; i < len; ++i)	{
		printf("%.2x ", start[i]);
	}
	printf("\n");
}

int main()	{
	int val = 0x87654321;
	bype_pointer valp = (bype_pointer)&val;
	show_bytes(valp, 3);

	return 0;
}