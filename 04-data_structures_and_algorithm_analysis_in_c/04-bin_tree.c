#include <stdio.h>
#include "04-bin_tree.h"

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
};

SearchTree Delete(ElementType X, SearchTree T)
{
	Position TmpCell;

	if(NULL == T)
		printf("Element not found\n");
	else
	if(X < T->Element)
		T->Left = Delete(X, T->Left);
	else
	if(X > T->Element)
		T->Right = Delete(X, T->Right);
	else
	if(T->Left && T->Right)
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if(T->Left == NULL)
			T = T->Right;
		else if(T->Right == NULL)
			T = T->Left;

		free(TmpCell);
	}

	return T;
}

SearchTree Insert(ElementType X, SearchTree T, SearchTree T_parent, int left_right)
{
	if(NULL == T)
	{
		T =(SearchTree) malloc(sizeof(struct TreeNode));
		T->Element = X;
		T->Left = T->Right = NULL;

		if(T_parent != NULL)
		{
			if(left_right == 0)
				T_parent->Left = T;
			else
				T_parent->Right = T;
		}
	}
	else if(X < T->Element)
		return Insert(X, T->Left, T, 0);
	else if(X > T->Element)
		return Insert(X, T->Right, T, 1);
//	else
//		;	//x is already in T, do nothing
	
	return T;		
}

Position FindMin(SearchTree T)
{
	if(T == NULL)
		return NULL;
	if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if(T == NULL)
		return NULL;

	while(T->Right != NULL)
		T = T->Right;	
	
	return T;
}

SearchTree InitTree()
{
	SearchTree T;
	SearchTree T_root;
	int i;
	ElementType X;

	T_root = NULL;
	T = NULL;
	for(i = 0; i < 6; ++i)
	{
		printf("input a num:");
		scanf("%d", &X);
		if(i == 0)
			T_root = Insert(X, T_root, NULL, 0);
		else
			T = Insert(X, T_root, T_root, 0);
	}
	return T_root;
}

void PrintTree(SearchTree T)
{
	if(T != NULL)
	{
		printf("%6d position = %p\n", T->Element, T);
		PrintTree(T->Left);
		PrintTree(T->Right);
	}
}

SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		printf("%6d position %p is free\n", T->Element, T);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if(T == NULL)
		return NULL;

	if(X < T->Element)
		return Find(X, T->Left);
	else if(X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}

int main()
{
	SearchTree T;
	Position p;
	ElementType X = 4;

	printf("tree\n");
	T = InitTree();
	PrintTree(T);
	p = Find(X, T);
	printf("\nFind %6d Position = %p\n", X, p);
	p = FindMin(T);
	printf("Min = %6d position = %p\n", p->Element, p);
	p = FindMax(T);
	printf("Max = %6d position = %p\n", p->Element, p);

	Delete(10, T);
	printf("After Delete 10 :\n");
	PrintTree(T);

	MakeEmpty(T);
	return 0;
}
