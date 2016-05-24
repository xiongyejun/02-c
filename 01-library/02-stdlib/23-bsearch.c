// void * bsearch(const void * key, const void 8 base, size_t num, size_t size, int(*compar)(const void *, const void *));
// binary search in array
// key: pointer to the object that serves as key for the search, type_casted to a void*
// base: pointr to the first object of the array where the search is performed, type_casted to a void*
// num: number of elements in the array pointed to by base.
// size: size in bytes of each element in the array
// compar: pointer to function that compares two elements
// return value: a pointer to an entry in the array that matches the search key. if there are more than one matching elements(i.e., elements for which compar would return 0), this may point to any of them(not necessarily the first one).
// if key is not found, a null pointer is returned
//
#include <stdio.h>
#include <stdlib.h>

int compareints(const void * a, const void * b)
{
	return ( *(int *)a - *(int *)b);
}

int main(void)
{
	int * p_item;
	int key = 40;
	int values[] = {50, 20, 60, 40, 10, 30};
	qsort(values, 6, sizeof(int), compareints);
	p_item = (int*) bsearch(&key, values, 6, sizeof(int), compareints);
	if(NULL != p_item)
		printf("%d is in the array.\n", *p_item);
	else
		printf("%d is not in the array.\n", key);

	return 0;
}
