#include <stdio.h>

#define ALL		100// all people in the ring
#define OUT		3	//	if count to 3, then out
int next[ALL];	// record the next people's next 

void init_ring(void){
	for (int i = 0; i < ALL; i++)
		next[i] = (i + 1) % ALL;
}
void print_ring(void){
	for (int i = 0; i < ALL; i++){
		printf("%d ", next[i]);
	}
	printf("   next\n");

	return;
}
int main(void)
{
	int left;		//how many people in the ring
	int counter;
	int i;
	int prev;

	printf("demo josephus ring proble\n");
	void init_ring(void);
	init_ring();
	void print_ring(void);
	print_ring();
	
	left = ALL;		// left = all people
	counter = 0;	// counter = 1, 2, 3
	i = 0;			// begin from [0]
	prev = ALL - 1; // 0's prev = 5
	
	while (left > 0)//left <= 1) 
	{
		counter++;
		if (OUT == counter)
		{
			left--;	// someone is out	
			printf("%d is out\n", i + 1);
	
			next[prev] = next[i];//set the next[]
		//	print_ring();
			counter = 0;
		}
	
//		printf("i = %d, counter = %d, left = %d\n", i, counter, left);

		prev = i;
		i = next[i];			// get next i
	}

	printf("proble is finished\n");
	
	return 0;
}
