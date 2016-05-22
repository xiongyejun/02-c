// void * realloc(void * ptr, size_t size)
// reallocate memory block
// changs the size of the memory block pointed to by ptr
//
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int input, n;
	int count = 0;
	int * numbers = NULL;
	int * more_numbers = NULL;

	do
	{
		printf("enter an integer value (0 to end):");
		scanf("%d", &input);
		count++;

		more_numbers = (int *) realloc(numbers, count * sizeof(int));
		
		if(NULL != more_numbers)
		{
			numbers = more_numbers;
			numbers[count - 1] = input;
		}
		else
		{
			free(numbers);
			puts("error (re)allocating memory");
			exit(1);
		}
	} while(0 != input);

	printf("numbers enterd:");
	for(n = 0; n < count; n++)
		printf("%d ", numbers[n]);
	free(numbers);


	return 0;
}
