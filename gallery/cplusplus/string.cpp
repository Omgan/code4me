// string.cpp

#include <assert.h>
#include <iostream>
using namespace std;

char* xstrcpy(char* strDest, const char* strSrc)
{
	assert((strDest != NULL) && (strSrc != NULL));
	char*	p = strDest;
	while ((*strDest++ = *strSrc++) != '\0')
		NULL;
	return p;
}

int xstrlen(char* strDest)
{
	assert((strDest != NULL));
	int count = 0;
	while (*strDest++ != '\0')
		count ++;
	return count;
}

char* xfoo(char* strDest)
{
	assert((strDest != NULL));
	char*	p = strDest;
	while ((*strDest++) != '\0')
		NULL;
	return p;
}

char* xfoo1(char** strDest)
{
	assert((strDest != NULL));
	char*	p = *strDest;
	while ((*(*strDest)++) != '\0')
		NULL;
	return p;
}

char* GetString1(void)
{
	char str[] = {"Hello World"};
	return str; // error: return stack memory:
}

char* GetString2(void)
{
	char *p = "Hello World";
	return p; // right: return static stack memory(��̬�洢��,��ֻ����)
}

char* GetString3(int num)
{
	char* p = (char*)malloc(sizeof(char) * num);
	return p; // right: return dynamic memory(��̬�ڴ�,���غ����ͷ�)
}

void GetString4(char* str, int num)
{
	str = (char*)malloc(sizeof(char) * num);
	return;  // error: str�ڵ����߶�ջ������NULL,�����ܴ�������Ķ�̬�ڴ�.
}

void GetString5(char** str, int num)
{
	*str = (char*)malloc(sizeof(char) * num);
	return; // right: *str������,�ǿ��Ա��ı䲢�ҿ��Դ�������.
}

void GetMemory(char* p, int num)
{
	//��Ҫ:
	//	����������ҪΪ������ÿ������������ʱ����,ָ�����p�ĸ�����_p,
	//  ������ʹ_p = p; ������������޸���_p������,�͵��²���p����������Ӧ�޸�.
	//	�����ָ����Ϊ���������ԭ��.

	//����:
	//	�ڱ�����,_p�������µ��ڴ�,ֻ�ǰ�_p��ָ���ڴ��ַ�ı���,����p˿���ı䡣
	//  ����GetMemory����������κζ�����
	p = (char*)malloc(sizeof(char)*num);
	return;
}

int main (int argc, char** argv)
{
	// step1:
	char str1[64] = {0};
	char str2[32] = {"Hello"};
	xstrcpy(str1, str2);
	cout << str1 << endl;
	cout <<xstrlen(str1)<<endl;

	char*	p	= xfoo(str1); // surprise: str1: Hello, no ""
	cout << str1 << endl;

	// step2:

};