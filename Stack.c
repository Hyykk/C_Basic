/*2020741067 홍윤교*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//스택 구조 선언
typedef struct Stack
{
	char word[100];
	int top;
}Stack;

//스택 초기화
void init(Stack* S) {
	S->top = -1;
}

//스택 push
void push(Stack* S, char word)
{
	S->top++;
	S->word[S->top] = word;
}

//스택 pop
char pop(Stack* S)
{
	int Temp;

	Temp = S->word[S->top];
	S->top--;
	return Temp;
}

//회문인지 판별
int palindrome(char String[])
{
	Stack S;
	int i;
	init(&S);
	for (i = 0; String[i] != 0; i++)
	{
		if (String[i] >= 65 && String[i] <= 90)
			String[i] += 32;
		push(&S, String[i]);
	}
	for (i = 0; String[i] != 0; i++)
	{
		if (String[i] != pop(&S))
		{
			return 0;					//회문이면 0
		}
	}	//아니면 1반환
	return 1;
}


int main(void)
{
	char String[100];
	
	printf("문장을 입력하세요 : ");
	scanf("%s", String);

	//1이면 회문, 0이면 회문x를 출력
	if (palindrome(String))
		printf("회문입니다.");
	else
		printf("회문이 아닙니다.");
	
}