#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수선언
int myStrLenCmp(const char* str1, const char* str2);

int main(void)
{
	char str1[100];
	char str2[100];

	//문자열 2개를 입력
	printf("첫 번째 문자열 : ");
	scanf("%s", str1);
	printf("두 번째 문자열 : ");
	scanf("%s", str2);

	printf("%d", myStrLenCmp(str1, str2));
}

//함수 정의
int myStrLenCmp(const char* str1, const char* str2)
{
	int count1, count2;

	//배열에서 '\0'이 나올 때 까지 count++
	for (count1 = 0; str1[count1]; count1++);
	for (count2 = 0; str2[count2]; count2++);

	if (count1 > count2)		//첫 번째 문자열이 더 길 경우
		return -1;
	if (count1 < count2)		//두 번째 문자열이 더 길 경우
		return 1;
	if (count1 == count2)	//같을 경우
		return 0;
}