#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age)
{
    Person* ptr=(Person*) malloc(sizeof(Person));
    if (ptr == NULL)
    {
        printf("Memory Allocation Falied\n");
        exit(1);
    }
    strncpy(ptr->name, name, sizeof(ptr->name)-1);
    ptr->name[sizeof(ptr->name)-1]= '\0';
    ptr->age=age;
    ptr->father=NULL;
    ptr->mother=NULL;
    return ptr;
}

int main(void)
{
    char name[100];
    int age;
    printf("Enter name: ");
    scanf("%99s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    Person* ptr=create_person(name, age);
    printf("Name: %s\nAge: %d\n", ptr->name, ptr->age);
    return 0;
}