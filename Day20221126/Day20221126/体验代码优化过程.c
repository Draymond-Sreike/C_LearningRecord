#include<stdio.h>
#include<stdlib.h>
void my_strcpy(char* dest, char* src);	// ��������

// ����
void test()
{
	char str1[] = "#################";
	char str2[] = "bit";

	my_strcpy(str1, str2);	// �Լ�ʵ��strcpy
	printf("%s\n", str1);
 }


/// <summary>
/// �Լ�ʵ�ֵ�strcpy����
/// </summary>
/// <param name="dest">
/// �ַ������Ƶ�Ŀ�ĵ�(char*)
/// </param>
/// <param name="src">
/// Ҫ���Ƶ��ַ���(char*)
/// </param>
void my_strcpy(char* dest, char* src)
{
	while (*dest++ = *src++) {}		// �Ż�
}

int main()
{
	test();

	system("pause");
	return 0;
}