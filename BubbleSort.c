#include <stdio.h>

int bubble(int* arr, int size);				//버블 함수 선언

void main()		
{	
	int arr[10] = { 0, };					//배열 선언
	int i;

	printf("입력\n");
	for (i = 0; i < 10; i++)
	{
		printf("\n%d : ", i);				//사용자로부터 배열에 넣을 수 입력받음
		scanf_s("%d", &arr[i]);
	}

	printf("출력\n");

	bubble(arr, 10);						//버블함수 실행
	
	

	return 0;								//함수 반환
}

	int bubble(int* arr, int size)			//버블함수 정의
	{
		int change;							//값을 서로 교환 후 저장할 변수 선언

		for (int i = size - 1; i > 0; i--)	//배열의 크기-1만큼 반복
		{
			for (int j = 0; j < i; j++)		//1부터 배열의 크기보다 작을 때 까지
			{
				if (arr[j] > arr[j + 1])    //앞의 숫자가 뒤의 숫자보다 클 때
				{
					change = arr[j];        //앞의 값을 change에 저장 후
					arr[j] = arr[j + 1];	//뒤의 값과 교환
					arr[j + 1] = change;	//뒤의 값은 저장한 앞의 값인 change로 대입
			
					for (int k = 0; k < 10; k++) { //배열의 크기만큼 반복
						printf("%d " ,arr[k]);		//배열 출력
					}
					
					printf("\n");
				}
			}
		}
	}