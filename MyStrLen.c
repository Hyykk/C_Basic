#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ�����
int myStrLenCmp(const char* str1, const char* str2);

int main(void)
{
	char str1[100];
	char str2[100];

	//���ڿ� 2���� �Է�
	printf("ù ��° ���ڿ� : ");
	scanf("%s", str1);
	printf("�� ��° ���ڿ� : ");
	scanf("%s", str2);

	printf("%d", myStrLenCmp(str1, str2));
}

//�Լ� ����
int myStrLenCmp(const char* str1, const char* str2)
{
	int count1, count2;

	//�迭���� '\0'�� ���� �� ���� count++
	for (count1 = 0; str1[count1]; count1++);
	for (count2 = 0; str2[count2]; count2++);

	if (count1 > count2)		//ù ��° ���ڿ��� �� �� ���
		return -1;
	if (count1 < count2)		//�� ��° ���ڿ��� �� �� ���
		return 1;
	if (count1 == count2)	//���� ���
		return 0;
}