#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Print(int*, int*, int**);
void arr_ij(int*, int*, int**);

int main(void)
{
	int Row = 0, Col = 0;							//Row는 열, Col은 행
	printf("열의 수를 입력하세요:");
	scanf("%d", &Row);
	printf("행의 수를 입력하세요:");
	scanf("%d", &Col);

	int** arr;										//2차원 이중포인터
	arr = (int**)malloc(sizeof(int*) * Row);		//정적할당

	for (int i = 0; i < Row; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * Col);
	}

	int row = Col;
	int col = Row;

	arr_ij(&Col, &Row, arr);			//배열함수 호출

	Print(&Col, &Row, arr);				//출력함수 호출

	free(arr);							//메모리할당 해제

	return 0;							//함수 반환
}
//배열 그리기 함수
void arr_ij(int* row, int* col, int** str)	//포인터함수를 통해 값을 보내줌
{

	int sub_i = 1;						//반복문을 위한 변수

	int A = 0;							//행렬 왼쪽크기
	int B = (*col) - 1;				//행렬 오른쪽크기 (-1은 0부터 시작하기 때문)
	int C = 0;							//행렬 위쪽
	int D = (*row) - 1;				//행렬 아랫쪽크기

	int i = 0, j = 0;					//반복문 변수

	while (sub_i <= (*row) * (*col))		//행*열 배열의 전체 크기
	{
		for (i = A; i <= B; i++)			//가로 1번째, 5번째... 수 입력(0부터 시작함으로, 가로의 -1만큼만 입력)
		{
			if (sub_i > (*row)* (*col))	//끝에 도달할 경우 바로 빠져나오기 위함.
				break;
			str[j][i] = sub_i++;
		}
		i--;								

		C++;								

		for (j = C; j <= D; j++)			//세로 줄
		{
			if (sub_i > (*row)* (*col))
				break;
			str[j][i] = sub_i++;
		}


		j--;
		B--;

		for (i = B; i >= A; i--)			//가로 줄
		{
			if (sub_i > (*row)* (*col))
				break;
			str[j][i] = sub_i++;
		}


		i++;
		D--;

		for (j = D; j >= C; j--)			//세로 줄
		{
			if (sub_i > (*row)* (*col))
				break;
			str[j][i] = sub_i++;
		}

		j++;
		A++;
	}

}



void Print(int* row, int* col, int** str)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *col; j++)
			printf("%3d", str[i][j]);
		printf("\n");
	}

}