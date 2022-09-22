#include <stdio.h>

int decimal(char* str);                                  //문자열을 정수형으로 변환시키는 함수선언

int main(void)
{
    char str[100] = "0";                                 //충분한 크기의 배열선언
    

    

    printf("정수형으로 변환할 문자열 입력: ");
    scanf_s("%s", str, 100);                               //사용자로부터 배열을 입력받음
    printf("int형 숫자 : ");
    printf("%d", decimal(str));

}

int decimal(char* str)                                  //정수형으로 전환하는 함수 정의
{
    int size = 0;                                       //배열의 크기
    int sum = 0;                                        //합계(마지막에 리턴)
    int i, j;                                           //반복문을 위한 변수

    for (i = 0; str[i] != '\0'; i++)                    //배열에 NULL값이 입력될 때까지(배열에 입력된 값까지)
    {
        if (str[i] >= '0' && str[i] <= '9') {      //문자열에 숫자 아닌것 판별
            size++;                                         //배열의 크기 측정
        }
        else {
            return 0;                                       //숫자가 아닐 경우 0반환
        }                         
    }

    int T = size - 1;                                       //거듭제곱
    int time = size - 1;                                //반복횟수  

    for (i = 0; str[i] != '\0'; i++)
    {
        T = 1;                                         //자릿수 초기화
        for (j = 0; j < time; j++)                   //횟수만큼 반복
        {
            T = T * 10;                                 //10의 거듭제곱
        }
       sum = sum + ((str[i] - '0') * T);                 //각 자리의 숫자에 j반복문을 거친 10의 거듭제곱을 한후 합계에 쌓는다.
       time--;                                          //한번 실행 후 횟수 감소
    }
    return sum;                                         //정수형으로 변환된 합계를 반환
}
