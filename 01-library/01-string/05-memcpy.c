// void * memcpy(void * destination, const void 8 soure, size_t num)
// copy block of memory
//
#include <stdio.h>
#include <string.h>

struct {
	char name[40];
	int age;
} person, person_copy;

int main(void)
{
	char myname[] = "pierre de fermat";
	memcpy(person.name, myname, strlen(myname)+1);
	person.age = 46;
	memcpy(&person_copy, &person, sizeof(person));

	printf("person_copy: %s,%d \n", person_copy.name, person_copy.age);

	return 0;
}
