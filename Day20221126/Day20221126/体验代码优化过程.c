#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strcpy(char* dest, char* src);		// 函数声明

// 测试
void test()
{
	char str1[] = "################################";
	char str2[] = "我爱华农！！！华农加油！！！";

	printf("%s\n", my_strcpy(str1, str2));	// 打印被复制后的目标字符串
}


/// <summary>
/// 将src指向的字符串拷贝到dest指向的空间，包括'\0'字符
/// </summary>
/// <param name="dest">
/// 字符串复制的目的地(char*)
/// </param>
/// <param name="src">
/// 要复制的字符串(char*)
/// </param>
char* my_strcpy(char* dest, const char* src)
{
	char* tempSave_Addr = dest;			// 保存目标字符串strDestination的起始地址

	// 以下两行代码是断言，用于保证指针的有效性
	assert(dest != NULL);				// 一旦dest为NULL，该函数就会浮窗报错
	assert(src != NULL);				// 一旦src为NULL，该函数就会浮窗报错

	while (*dest++ = *src++) {}		// 将src指向的字符串拷贝到dest指向的空间，包括'\0'字符

	return tempSave_Addr;				// 返回值目标字符串strDestination的起始地址
}


int main()
{
	test();

	system("pause");
	return 0;
}