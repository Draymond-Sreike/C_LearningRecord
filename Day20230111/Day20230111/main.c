#include <stdio.h>

void test(int arr[])
{
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("(test)sz = %d\n", sz);
}

int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("(main)sz = %d\n", sz);
	test(arr);
}