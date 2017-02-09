#include <stdio.h>
#include "03-queue.h"

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int main(void)
{
	Queue Q;
	int i;

	Q = CreateQueue(10);
	for(i = 0; i < 12; ++i)
	{
		if( Enqueue(i, Q) == 1)
			printf("num %2d into queue.\n", Q->Size);
	}
	return 0;
}

Queue CreateQueue(int MaxElements)
{
	Queue Q;
	ElementType Arr[10];

	Q = (Queue)malloc(sizeof(struct QueueRecord));
	MakeEmpty(Q);
	Q->Capacity = MaxElements;
	Q->Array = &Arr[0];

	return Q;
}	

int IsEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

void MakeEmpty(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
	if(++Value == Q->Capacity)
		Value = 0;

	return Value;
}

int Enqueue(ElementType X, Queue Q)
{
	if(IsFull(Q))
	{
		printf("Full Queue\n");
		return 0;
	}
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
		return 1;
	}
}
