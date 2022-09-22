#define _CRT_SECURE_NO_WARNINGS	//scanf를 사용하기 위한 정의
#include <stdio.h>
#include <stdlib.h>			//동적할당을 위한 라이브러리 추가

int main(void)
{
	int height = 0, width = 0;	//행 height, 열 width
	int count = 0;			//가는데 걸린횟수
	int i = 0, j = 0;
	int** way;			//동적할당+배열 이중포인터

	printf("행 입력 : ");
	scanf("%d", &height);
	printf("열 입력 : ");
	scanf("%d", &width);

	//2차원 동적할당
	way = (int**)malloc(sizeof(int*) * height+1);

	for (int i = 0; i < height; i++)
	{
		way[i] = (int*)malloc(sizeof(int) * width+1);		//반복문을 이용해 이차원배열 동적할당
	}

	printf("길 입력 (띄어쓰기 포함) :\n");

	//반복문을 통해 사용자로부터 이차원배열을 입력받음
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			scanf(" %d", &(int*)way[i][j]);
	}

	//길찾기
	while (1)
	{
		if (i == width - 1 && j == height-1)		//도착하면 반복문 탈출
		{
			break;
		}

		if (way[i + 1][j] == 1)		//아래길 탐지(1이면 진행)
		{
			way[i][j] = 0;				//지나온 길을 0으로 만들어 돌아가는 것을 방지
			i++;							//위치도 함께 변경
			count++;
		}
		
		else if (way[i][j + 1] == 1)		//오른쪽 길 탐지
		{
			way[i][j] = 0;
			j++;
			count++;
		}
		else if (way[i][j - 1] == 1)		//왼쪽길 탐지
		{
			j--;
			way[i][j] = 0;
			count++;
		}
		else if (way[i - 1][j] == 1)		//위쪽 길 탐지
		{
			way[i][j] = 0;
			i--;
			count++;
		}
	}
	
		
	printf("\n최단경로 : %d", count + 1);		//시작지점도 포함하므로 +1을 해준다

	free(way);					//동적 할당 해제

	return 0;
}