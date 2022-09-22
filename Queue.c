/*2020741067 홍윤교*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

//Queue정의
typedef struct queue {
    int data;
    struct queue* next;
}QUEUE;


//함수 선언
int empty(QUEUE*);
void enqueue(QUEUE**, QUEUE**, int);
int dequeue(QUEUE**);
int rear(QUEUE**);
int front(QUEUE**);

int main(void)
{
    QUEUE* Head;            //처음값을 기억하기위해 Head와 Tail을 따로 설정
    QUEUE* Tail;

    int kind, cnt = 0;              //카운트와 메뉴선택을 저장할 변수
    int value[] = { 0, };           //값을 저장할 배열

    Head = NULL;
    Tail = NULL;

    //0을 누를 때 까지 반복
    do {
        printf("----------------\n");
        printf("\n0을 누르면 종료\n");
        printf("1. Enqueue, 2. Dequeue, 3. Size, 4.Front, 5. Rear, 6. Empty, 7.Print\n");
        scanf("%d", &kind);
        switch (kind) {
        case 1:
            printf("입력할 값 : ");
            scanf("%d", &value[cnt]);
            enqueue(&Head, &Tail, value[cnt]);       //push
            cnt++;
            break;
        case 2:
            dequeue(&Tail);                           //pop
            cnt--;
            break;
        case 3:
            printf("Queue의 크기 : %d\n", cnt);            //cnt = Queue의 크기
            break;
        case 4:
            front(&Head);                                //가장 앞에있는 값
            break;
        case 5:
            rear(&Tail);                                //가장 뒤에있는 값
            break;
        case 6:
            printf("Queue에 데이터가 없으면 1, 있으면 0반환 : %d\n", empty(Head));
            break;
        case 7:
            printf("\n");

            //cnt만큼 반복하여 출력
            for (int i = 0; i < cnt; i++)
            {
                printf("%d ", value[i]);
            }
            printf("\n");
            break;
        }
    } while (kind != 0);
    return 0;
}

//비었으면 1 있으면 0을 반환
int empty(QUEUE* s)
{
    if (s == NULL)
    {
        return 1;
    }
    return 0;
}


void enqueue(QUEUE** Head, QUEUE** Tail, int data)
{
    //동적할당
    QUEUE* new_node = (QUEUE*)malloc(sizeof(QUEUE));

    //데이터 저장
    new_node->next = NULL;
    new_node->data = data;

    if (*Tail == NULL)
    {
        *Tail = new_node;
        *Head = new_node;

        return;
    }

    new_node->next = *Tail;
    *Tail = new_node;
}


int dequeue(QUEUE** s)
{
    QUEUE* temp = *s;
    int data;

    if (empty(temp))          //비어있을 경우
    {
        printf("Queue이 비어있음. \n");

        return -1;
    }

    //처음부터 하나씩 꺼냄(cnt는 -1)
    data = temp->data;

    printf("Dequeue : %d\n", data);

    *s = temp->next;

    free(temp);             //필요없는 메모리 할당 해제

    return data;
}


int rear(QUEUE** s)
{
    QUEUE* temp = *s;
    int data;

    if (empty(temp))      //비었을 경우
    {
        printf("rear이 비어있음. \n");

        return -1;
    }

    //가장 뒤에 값을 출력(cnt는 감소되지 않음)
    data = temp->data;

    printf("Rear : %d\n", data);

    return data;
}

int front(QUEUE** s)
{
    QUEUE* temp = *s;
    int data;

    if (empty(temp))      //비었을 경우
    {
        printf("front이 비어있음. \n");

        return -1;
    }

    //가장 처음 값을 출력(cnt는 감소되지 않음)
    data = temp->data;

    printf("Front : %d\n", data);

    return data;
}