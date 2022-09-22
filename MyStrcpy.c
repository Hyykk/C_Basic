#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int myStrCopy(char* out, char* str1, int size);		//함수선언

int main(void)
{
	char str1[100];
	char out[100];
	char* out_p;
	int size_out;

	printf("출력될 문자열의 크기 : ");
	scanf("%d", &size_out);
	 
	
	out_p = (char*)malloc(size_out);						//동적 할당

	printf("복사할 문자열 : ");
	scanf("%s", str1);

	printf("%d\n", myStrCopy(out, str1, size_out));				//return값을 출력

	return 0;
}

//함수 정의
int myStrCopy(char* out, char* str1, int size)
{
	int count;
	char* copy;																	//복사한것을 저장할 배열

	for (copy = out; *out = *str1; str1++, out++);				//out배열에 복사

	for (count = 0; str1[count]; count++);		//크기측정

	if (count > size)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}