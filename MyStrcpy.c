#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int myStrCopy(char* out, char* str1, int size);		//�Լ�����

int main(void)
{
	char str1[100];
	char out[100];
	char* out_p;
	int size_out;

	printf("��µ� ���ڿ��� ũ�� : ");
	scanf("%d", &size_out);
	 
	
	out_p = (char*)malloc(size_out);						//���� �Ҵ�

	printf("������ ���ڿ� : ");
	scanf("%s", str1);

	printf("%d\n", myStrCopy(out, str1, size_out));				//return���� ���

	return 0;
}

//�Լ� ����
int myStrCopy(char* out, char* str1, int size)
{
	int count;
	char* copy;																	//�����Ѱ��� ������ �迭

	for (copy = out; *out = *str1; str1++, out++);				//out�迭�� ����

	for (count = 0; str1[count]; count++);		//ũ������

	if (count > size)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}