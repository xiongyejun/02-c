#include <stdio.h>
#include "02-stack.h"

struct Node
{
	ElementType Element;
	PtrToNode   Next;
};

int main(void)
{
	Stack S;
	int i;
	int num;

	S = CreateStack();
	for (i = 0; i < 10; ++i)
	{
		printf("%d  input a num:", i);
		scanf("%d", &num);
		Push(num, S);
		printf("push %d into stack\n", num);
	}

	while(!IsEmpty(S))
	{
		num = Pop(S);
		printf("pop %d out stack\n", num);
	}

	return 0;
}

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;

	S =(PtrToNode) malloc(sizeof(struct Node));
	if(S == NULL)
		printf("out of space!\n");

	S->Next = NULL;
	MakeEmpty(S);
	return S;
}

void MakeEmpty(Stack S)
{
	if(S == NULL)
		printf("must use createStack first\n");
	else
		while(!IsEmpty(S))
			Pop(S);
}

void Push(ElementType X, Stack S)
{
	PtrToNode TmpCell;

	TmpCell =(PtrToNode) malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("out of space\n");
	else
	{
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

ElementType GetTop(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->Element;

	printf("Empty Stack\n");
	return -1;
}

int Pop(Stack S)
{
	PtrToNode FirstCell;
	int num;

	if(IsEmpty(S))
	{
		printf("Empty Stack\n");
		return -1;
	}
	else
	{
		FirstCell = S->Next;
		num = FirstCell->Element;
		S->Next = S->Next->Next;
		free(FirstCell);
		return num;
	}

}
