#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_StrEqual(char* str1, char* str2);

int main(void)
{
    char str1[10];
    char str2[10];

    printf("문자열 : ");
    scanf("%s", &str1);
    printf("찾을 문자열 : ");
    scanf("%s", &str2);

    if (*str1 == *str2)         //찾는 배열이 있을 때
    {
        printf("1\n%d\n", my_StrEqual(str1, str2));
    }
    else {                      //없을 때
        printf("%d\n", my_StrEqual(str1, str2));
    }

    return 0;
}

int my_StrEqual(char* str1, char* str2)
{
    int size = 0;						// 찾을 배열의 크기를 저장할 변수

    for (int i = 0; str2[i] != 0; i++)
    {
        size++;								//size 1씩 증가
    }

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == str2[0])		// 같은 배열이 나오면
        {
            for (int j = 1; j <= size; j++)
            {
                if (str2[j] == str1[i + j]) {
                    return (i + 1);				// 찾은 배열의 위치를 리턴
                }

            }
        }
    }
}