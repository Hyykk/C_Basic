#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Add(char* input, char* num, int count);
void Remove(char* input, char* num, int count, char* compare);
int Check(char* input, char* num);
int Toggle(char* input, char* num, int count);
void All(char* input, char* num);
void Empty(char* input, char* num);
void isFull(char* input);

int size;																		//배열크기와 원소위치는 전역변수로 선언
int count = 0;

int main(void)
{
	char cal[10] = { 0, };

	printf("배열 최대 크기 : ");
	scanf("%d", &size);									//	배열 크기 입력

	char* input = (char*)malloc(sizeof(char) * (size + 1));							//동적할당
	char* num = (char*)malloc(sizeof(char) * (size + 1));
	char* compare = (char*)malloc(sizeof(char) * (size + 1));


	for (int i = 0; i < size; i++)
	{
		input[i] = 0;
		num[i] = 0;
		compare[i] = 0;
	}

	while (1)
	{
		if (count >= size + 1)
		{
			isFull(input);
			break;
		}

		else
		{
			printf("\n연산을 선택하세요.\n");
			printf("add : \n");
			printf("remove : \n");
			printf("check : \n");
			printf("toggle : \n");
			printf("all : \n");
			printf("empty :\n");
			printf("\n");
			scanf("%s", cal);
			printf("input : %s\n", cal);

			if (cal[1] == 'd')					//add
			{
				scanf("%s", num);
				int res = Add(input, num, count);
				count++;
				if (res == 0)					//이미 있을 때
				{
					printf("연산이 무시되었습니다.\n");
					count--;
				}
				else
				{
					if (count > size)
					{
						continue;
					}
					else
					{
						input[count - 1] = num[0];
					}
				}
				for (int i = 0; i < count; i++)
				{
					if ((int)input[i] >= '0' && (int)input[i] <= '9')		//숫자일 때
						printf("%c, ", *(input + i));								//집합 출력
				}
				printf("\n");
			}
			else if (cal[1] == 'e')							//remove
			{
				scanf("%s", num);
				Remove(input, num, count, compare);
				count--;
				for (int i = 0; input[i] != '\0'; i++)
				{
					if ((int)input[i] >= '0' && (int)input[i] <='9')
						printf("%c, ", *(input + i));
				}
				printf(" \n");
			}
			else if (cal[1] == 'h')						//check
			{
				int res = Check(input, num);
				if (res == 1)
				{
					printf("1\n");
				}
				if (res == 0)
				{
					printf("0\n");
				}
			}
			else if (cal[1] == 'o')			//toggle
			{
				scanf("%s", num);

				int res = Toggle(input, num, count);

				if (res == 0)  //이미 있을때 삭제
				{
					Remove(input, num, count, compare);
					count--;
					for (int i = 0; input[i] != '\0'; i++)
					{
						if ((int)input[i] >= '0' && (int)input[i] <= '9')
							printf("%c, ", *(input + i));
					}
					printf(" \n");
				}
				else // 없을때 추가
				{
					input[count] = num[0];
					count++;
					for (int i = 0; i < count; i++)
					{
						if ((int)input[i] >= '0' && (int)input[i] <='9')
							printf("%c, ", *(input + i));
					}
					printf(" \n");
				}


			}
			else if (cal[1] == 'l')			//all
			{
				All(input, num);
				for (int i = 0; i < count; i++)
				{
					if ((int)input[i] >= '0' && (int)input[i] <= '9')
						printf("%c, ", *(input + i));
				}
				printf("\n");


			}

			else if (cal[1] == 'm')			//empty
			{
				Empty(input, num);
				for (int i = 0; input[i] != '\0'; i++)
				{
					if ((int)input[i] >= '0' && (int)input[i] <= '9')
						printf("%c, ", *(input + i));
				}
				printf("\n");
				printf("\n배열 최대 크기 : ");				//배열크기 다시 입력

				scanf("%d", &size);

				count = 0;					//카운트 초기화

				input = (char*)malloc(sizeof(char) * (size + 1));		//동적할당
			}

			else
			{
				printf("%d", count);
			}
		}
	}
}
int Add(char* input, char* num, int count)
{
	for (int j = 0; j < count + 1; j++)
	{
		if (num[0] == input[j])
		{
			return 0;
		}
		else
		{
			continue;
		}
	}

	return 1;
}

void Remove(char* input, char* num, int count, char* compare)
{
	char h = num[0];
	int j = 0, i;
	for (i = 0; i < count; i++)
	{
		if (input[i] == h)
		{
			continue;
		}
		else
		{
			compare[j] = input[i];
			j++;
		}

	}

	if (i == 1)
	{
		compare[i - 1] = 0;
		input[i - 1] = 0;
	}
	else 
	{
		for (i = 0; compare[i] != '\0'; i++)
		{
			input[i] = compare[i];
		}
		input[i] = '\0';
	}

}

int Check(char* input, char* num)
{
	int i;
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == num[0])
		{
			return 1;
		}
		else
		{
			continue;
		}
	}
	return 0;
}

int Toggle(char* input, char* num, int count)
{
	for (int j = 0; j < count + 1; j++)
	{
		if (num[0] == input[j])			//이미 있을 때 
		{
			return 0;
		}
		else									//없다면 컨티뉴
		{
			continue;
		}
	}

	return 1;
}

void All(char* input, char* num)
{
	int i;
	char plus = '0';
	for (i = 0; i < count; i++)
	{
		plus++;									//1부터 plus까지 입력
		input[i] = plus;
	}
}

void Empty(char* input, char* num)
{
	int i;
	for (i = 0; input[i] != '\0'; i++)
	{
		input[i] = '0';								//모두 초기화
	}


}

void isFull(char* input)
{
	printf("최대 저장 가능한 배열 크기를 넘어섰습니다.\n");
}