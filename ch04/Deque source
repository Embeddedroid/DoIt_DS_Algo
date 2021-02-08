#include <stdio.h>
#include <stdlib.h>
#include "IntDequeue.h"

/*--- 큐 초기화 ---*/
int Initialize(ArrayIntQueue *s, int max)
{
	s->num =s->front = s->rear = 0;
	if ((s->que = calloc(max, sizeof(int))) == NULL) {
		s->max = 0;								/* 배열의 생성에 실패 */
		return -1;
	}
	
	s->max = max;
	return 0;
}

/*--- 큐에 데이터를 인큐---*/
int EnqueRear(ArrayIntQueue *s, int x)
{
	
	if (s->num >= s->max)						/* 큐가 가득 참 */
		return -1;

	s->num++;
	s->que[s->rear++] = x;

	if (s->rear == s->max)
		s->rear = 0;
	return 0;
}
int EnqueFront(ArrayIntQueue *s, int x)
{
	if (s->num >= s->max)return -1;

	s->num++;
	s->front = (s->front - 1 + s->max) % s->max;
	s->que[s->front] = x; return 0;
}
/*--- 큐에서 데이터를 디큐 ---*/
int DequeFront(ArrayIntQueue *s, int *x)
{
	if (s->num <= 0)							/* 큐가 비어 있음 */
		return -1;
	
	s->num--;
	*x = s->que[s->front++];	

	if (s->front == s->max)
		s->front = 0;
	return 0;
}

/* 팝 */
int DequeRear(ArrayIntQueue *s, int *x)
{
	if (s->num <= 0)return -1;

	s->num--;
	s->rear = (s->rear - 1 + s->max) % s->max;
	*x = s->que[s->rear];
	return 0;
}
/*--- 큐에서 데이터를 피크 ---*/
int PeekFront(const ArrayIntQueue *s, int *x)
{
	if (s->num <= 0)							/* 큐가 비어 있음 */
		return -1;
	*x = s->que[s->front];
	return 0;
}
int PeekRear(const ArrayIntQueue *s, int *x)
{
	if (s->num <= 0)
		return -1;
	*x = s->que[s->rear - 1];
	return 0;
}
/*--- 큐 비우기 ---*/
void Clear(ArrayIntQueue *s)
{
	s->num = 0;
	s->rear = 0;
	s->front = 0;
	return 0;
}

/*--- 큐의 용량 ---*/
int Capacity(const ArrayIntQueue *s)
{
	return s->max;
}

/*--- 큐에 쌓여 있는 데이터 수 ---*/
int Size(const ArrayIntQueue *s)
{
	return s->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const ArrayIntQueue *s)
{
	return s->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const ArrayIntQueue *s)
{
	return s->num >= s->max;
}

/*--- 큐에서 검색 ---*/
int Search(const ArrayIntQueue *s, int x)
{
	int i;

	int idx;
	for (i = 0; i < s->num; i++)
	{
		if (s->que[idx = (i + s->front) % s->max] == x)
			return idx;
	}
	return -1;				/* 검색 실패 */
}

/*--- 모든 데이터 표시 ---*/
void Print(const ArrayIntQueue *s)
{
	int i;

	/*if (s->front >= s->rear)
	{
		for (i = s->front; i < s->max; i++)	 꼭대기(top) → 바닥(bottom)으로 선형 검색
			printf("%d", s->que[i]);
		if (s->rear>0)
			for (i = 0; i<s->rear; i++)
				printf("%d", s->que[i]);
	}
	else
	{
		for (i = s->front; i < s->rear; i++)	 꼭대기(top) → 바닥(bottom)으로 선형 검색 
			printf("%d", s->que[i]);
	}*/
	for (i = 0; i < s->num; i++)
		printf("%d ", s->que[(i + s->front) % s->max]);
	putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(ArrayIntQueue *s)
{
	if (s->que != NULL)
		free(s->que);		/* 배열을 삭제 */
	s->max = s->num = s->front = s->rear = 0;
}

int search2(const ArrayIntQueue *s, int x)
{
	int i;

	for (i = 0; i < s->num; i++)
	{
		if (s->que[(i + s->front) % s->max] == x)
			return i;
	}
	return -1;
}
