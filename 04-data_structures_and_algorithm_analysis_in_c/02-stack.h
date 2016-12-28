#ifndef _02_STACK_H

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
int Top(Stack S);
void GetPop(Stack S);

#endif
