#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	int(*pa)[10] = &arr;
	printf("pa = %p\n", pa);
	printf("*pa = %p\n", *pa);

	printf("pa+1 = %p\n", pa + 1);
	printf("(*pa) + 1 = %p\n", (*pa) + 1);

	return 0;
}