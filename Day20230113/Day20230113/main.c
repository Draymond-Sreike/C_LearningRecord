#include <stdio.h>

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	char arr3[] = "abc";
	char arr4[] = "cba";
	
	if (arr1 == arr2)
		printf("ͬ\n");
	else
		printf("��\n");

	if (arr3 == arr4)
		printf("ͬ\n");
	else
		printf("��\n");

	return 0;
}