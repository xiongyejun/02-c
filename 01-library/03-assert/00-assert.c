// void assert (int expression);
// evaluate assertion
//
#include <stdio.h>
#include <assert.h>

void print_number(int * my_int)
{
  assert(my_int != NULL);
  printf("%d\n", *my_int);
}

int main()
{
  int a = 10;
  int * b = NULL;
  int * c = NULL;

  b = &a;

  print_number(b);
  print_number(c);

  return 0;
}
