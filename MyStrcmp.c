#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_StrEqual(char* str1, char* str2);

int main(void)
{
    char str1[10];
    char str2[10];

    printf("���ڿ� : ");
    scanf("%s", &str1);
    printf("ã�� ���ڿ� : ");
    scanf("%s", &str2);

    if (*str1 == *str2)         //ã�� �迭�� ���� ��
    {
        printf("1\n%d\n", my_StrEqual(str1, str2));
    }
    else {                      //���� ��
        printf("%d\n", my_StrEqual(str1, str2));
    }

    return 0;
}

int my_StrEqual(char* str1, char* str2)
{
    int size = 0;						// ã�� �迭�� ũ�⸦ ������ ����

    for (int i = 0; str2[i] != 0; i++)
    {
        size++;								//size 1�� ����
    }

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == str2[0])		// ���� �迭�� ������
        {
            for (int j = 1; j <= size; j++)
            {
                if (str2[j] == str1[i + j]) {
                    return (i + 1);				// ã�� �迭�� ��ġ�� ����
                }

            }
        }
    }
}