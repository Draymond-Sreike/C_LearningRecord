#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strcpy(char* dest, char* src);		// ��������

// ����
void test()
{
	char str1[] = "################################";
	char str2[] = "�Ұ���ũ��������ũ���ͣ�����";

	printf("%s\n", my_strcpy(str1, str2));	// ��ӡ�����ƺ��Ŀ���ַ���
}


/// <summary>
/// ��srcָ����ַ���������destָ��Ŀռ䣬����'\0'�ַ�
/// </summary>
/// <param name="dest">
/// �ַ������Ƶ�Ŀ�ĵ�(char*)
/// </param>
/// <param name="src">
/// Ҫ���Ƶ��ַ���(char*)
/// </param>
char* my_strcpy(char* dest, const char* src)
{
	char* tempSave_Addr = dest;			// ����Ŀ���ַ���strDestination����ʼ��ַ

	// �������д����Ƕ��ԣ����ڱ�ָ֤�����Ч��
	assert(dest != NULL);				// һ��destΪNULL���ú����ͻḡ������
	assert(src != NULL);				// һ��srcΪNULL���ú����ͻḡ������

	while (*dest++ = *src++) {}		// ��srcָ����ַ���������destָ��Ŀռ䣬����'\0'�ַ�

	return tempSave_Addr;				// ����ֵĿ���ַ���strDestination����ʼ��ַ
}


int main()
{
	test();

	system("pause");
	return 0;
}