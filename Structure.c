/* 2020741067 로봇학부 1학년 홍윤교 출석부과제*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student Student;								//자료형 선언

struct Student															//학생 구조체 선언
{														
	int stdNum;
	char* stdName[10];
	char* stdAddress[10];
	float stdGrade;
};

void loadData(struct Student* std, int* stdIndex)				//불러오는 함수 정의
{
	FILE* fp = fopen("text.txt", "r");
	if (fp == '\0')															//파일이 없을 경우
	{
		printf("불러올 파일이 없습니다.\n");
		return;
	}
	for (int i = 0;i<*stdIndex;i++)								//저장한 파일에서 불러오기
	{
		fscanf(fp, "%d %s %s %f", &std[i].stdNum, &std[i].stdName, &std[i].stdAddress, &std[i].stdGrade);
	}
	fclose(fp);
}

void saveData(struct Student* std, int stdIndex)				//저장하는 함수 정의
{
	FILE* fp = fopen("text.txt", "w");
	for (int i = 0; i < stdIndex; i++)										//학생 수 만큼 저장
	{
		fprintf(fp, "%d %s %s %f\n", std[i].stdNum, std[i].stdName, std[i].stdAddress, std[i].stdGrade);
	}
	fclose(fp);
}

int myStrCmp(char* str1, const char* str2)				//strcmp(문자열 비교)함수 정의
{

	//do while문을 통해 다른문자 일때 까지 비교
	do {
		if (*str1 < *str2) {						//str1 < str2일 때 -1
			return -1;
		}
		else if (*str1 > * str2)				//str1 > str2일 때 1
		{
			return 1;
		}
		else if (*str1 == *str2)				//같을 때 0
		{
			return 0;
		}
		str1++;
		str2++;
	} while (!(*str1 == '\0' && *str2 == '\0'));				//NULL값이 나올  때 까지
}


int main(void) 
{
	struct Student std[10];
	static int stdIndex = 0;				//학생 수를 저장할 변수

	//반복문 변수
	int i, j;
	int sort, find, del;

	//구조체 선언
	struct Student tmp;

	//메뉴선택 변수
	int input = 0;
	int size;

	printf("최대 입력크기를 입력하세요(또는 불러올 크기) : ");
	scanf("%d", &size);

	//동적할당
	Student* ptr = 0;									
	ptr = (Student*)malloc(sizeof(Student) * size);

	while (input != 8)
	{
		printf("\n학생출석부입니다.\n번호를 입력해주세요.\n");

		printf("1. 학생 정보 입력\n");
		printf("2. 전체 정보 출력\n");
		printf("3. 학생 정렬\n");
		printf("4. 학생 삭제\n");
		printf("5. 저장 \n");
		printf("6. 불러오기 \n");
		printf("7. 학생 검색 \n");
		printf("8. 종료\n");
		printf("입력 : ");
		scanf("%d", &input);

		if (input == 1) {
			if (stdIndex >= 9) 
			{
				printf("학생의 수가 가득찼습니다.\n");
			}
			else {
				printf("학번입력 : ");
				scanf("%d", &std[stdIndex].stdNum);
				printf("이름 : ");
				scanf("%s", std[stdIndex].stdName);
				printf("주소 : ");
				scanf("%s", std[stdIndex].stdAddress);
				printf("성적 : ");
				scanf("%f", &std[stdIndex].stdGrade);

				stdIndex++;
			}
		}

		else if (input == 2) 
		{
			if (stdIndex > 0) 
			{
				int i;

				printf("\n 학번 \t 이름 \t 주소 \t 성적 \n");
				printf("----------------------------------------------\n");
				for (i = 0; i < stdIndex; i++)
				{
					printf(" %d \t %s \t\ %s \t %f \n",
						std[i].stdNum, std[i].stdName, std[i].stdAddress, std[i].stdGrade);
				}
			}
			else 
			{
				printf("학생정보가 없음.\n");
			}
		}

		else if (input == 3)
		{
			printf("정렬방식을 선택하세요. \n");
			printf("1. 학번 2. 이름 3. 주소 4. 성적 : ");
			scanf("%d", &sort);

			//정렬은 버블소트를 이용함
			for (i = 0; i < stdIndex - 1; i++)
			{
				for (j = 1; j < stdIndex; j++)
				{
					if (sort == 1)								//학번으로 정렬
					{
						if (std[j - 1].stdNum > std[j].stdNum)
						{
							tmp = std[j - 1];
							std[j - 1] = std[j];
							std[j] = tmp;
						}
					}

					//이름과 주소순으로 정렬은 myStrCmp함수를 이용함
					else if (sort == 2)						//이름순으로 정렬
					{					
						if (myStrCmp(std[j - 1].stdName, std[j].stdName) > 0)
						{
							tmp = std[j - 1];
							std[j - 1] = std[j];
							std[j] = tmp;
						}
					}

					else if (sort == 3)						//주소순으로 정렬
					{
						if (myStrCmp(std[j - 1].stdAddress, std[j].stdAddress) > 0)
						{
							tmp = std[j - 1];
							std[j - 1] = std[j];
							std[j] = tmp;
						}
					}

					else if (sort == 4)						//성적순으로 정렬
					{	
						if (std[j - 1].stdGrade > std[j].stdGrade)
						{
							tmp = std[j - 1];
							std[j - 1] = std[j];
							std[j] = tmp;
						}
					}
				}
			}
		}

		else if (input == 4)
		{
			printf("학번 입력 : ");
			scanf("%d", &find);

			for (i = 0; i < stdIndex; i++)
			{
				if (std[i].stdNum == find)					//찾았던 학번 모두 출력
				{
					printf("검색된 학번");
					printf("%d\t %s\t %s\t %f\n\n", 
						std[i].stdNum, std[i].stdName, std[i].stdAddress, std[i].stdGrade);
					printf("삭제하시려면 1, 아니면 0 : ");
					scanf("%d", &del);
					if (del == 1)
					{
						// 학생수만큼 검색후 다음배열로 덮어씌움
						for (j = i; j < stdIndex; j++)			
						{
							std[j] = std[j + 1];
							stdIndex--;
						}
					}
				}
			}
		}

		else if (input == 5)								//출석부 저장
		{
			saveData(std, stdIndex);					//함수호출
		}	

		else if (input == 6)								//출석부 불러오기
		{
			loadData(std, &stdIndex);					//함수호출
		}

		else if (input == 7)								//학생 검색
		{
			printf("학번 입력 : ");
			scanf("%d", &find);
			for (i = 0; i < stdIndex; i++)				//저장된 학생수만큼
			{
				if (std[i].stdNum == find)				//찾는 학번이 나올떄까지
				{
					printf("검색된 학번");
					printf("학번 : %d\n 이름 : %s\n 주소 : %s\n 성적 : %f\n\n",
						std[i].stdNum, std[i].stdName, std[i].stdAddress, std[i].stdGrade);			
				}
			}
		}
		else														//메뉴선택오류
		{
			printf("올바른 메뉴를 선택해주세요.");
		}
	 }

	return 0;
}