#include <stdio.h>
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	printf("%d \n", (p+2)[2]);
	
}