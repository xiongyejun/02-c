#include <stdio.h>
#include "01-list.h"

struct Node
{
	ElementType Element;
	Position     Next;
};

int main()
{
	List L;
	Position P;
	int X;

	L = (Position) malloc(sizeof(struct Node));
	L->Next = NULL;
	L->Element = -1;

	printf("hehe\n");
	
	initList(L);
	printf("input a num:");
	scanf("%d", &X);

	P = FindPrevious(X, L);
	if(P == NULL)
		printf("can't find the num:%d previous num\n", X);
	else
		printf("Previous num is:%d, address is :0x%p\n", P->Element, P->Next);

	DeleteList(L);

	return 0;
}

void initList(List L)
{
	int i;
	Position P, Tmp;
	P = L;

	for(i = 0; i < 10; ++i)
	{
		Tmp = (Position) malloc(sizeof(struct Node));
		Tmp->Element = i * 8;
		Tmp->Next = NULL;
		P->Next = Tmp;
		P = Tmp;
	}
}

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
	Position P;

	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;

	return P;
}


void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);
	
	if(!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	if(P->Next != NULL)
		return P;
	else
		return NULL;
}

void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell =(Position)malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of space.");
		//FatalError("Out of space!!!");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P, Tmp;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
