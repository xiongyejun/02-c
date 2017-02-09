// P60
#ifndef _03_Queue_h
#define ElementType int

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
int Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
int Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif
