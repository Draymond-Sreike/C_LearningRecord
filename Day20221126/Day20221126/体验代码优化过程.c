#include<stdio.h>
#include<stdlib.h>
void my_strcpy(char* dest, char* src);	// 函数声明

// 测试
void test()
{
	char str1[] = "#################";
	char str2[] = "bit";

	my_strcpy(str1, str2);	// 自己实现strcpy
	printf("%s\n", str1);
 }


/// <summary>
/// 自己实现的strcpy函数
/// </summary>
/// <param name="dest">
/// 字符串复制的目的地(char*)
/// </param>
/// <param name="src">
/// 要复制的字符串(char*)
/// </param>
void my_strcpy(char* dest, char* src)
{
	while (*dest++ = *src++) {}		// 优化
}

int main()
{
	test();

	system("pause");
	return 0;
}