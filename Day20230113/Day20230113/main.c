#include <stdio.h>

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";

	char arr3[] = "abc";
	char arr4[] = "cba";
	
	if (arr1 == arr2)
		printf("ЭЌ\n");
	else
		printf("вь\n");

	if (arr3 == arr4)
		printf("ЭЌ\n");
	else
		printf("вь\n");

	return 0;
}