#include<iostream>
using namespace std;
#include<string.h>

int main()
{	// 自动窗口使用
	int b = 10;
	{
		int tem = 10;
	}
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	system("pause");
}