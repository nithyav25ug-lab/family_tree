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
    char ame[100];
    int ag;
    printf("Enter name: ");
    scanf("%99s", ame);
    printf("Enter age: ");
    scanf("%d", &ag);
    Person* ptr=create_person(ame, ag);
    printf("Name: %s\nAge: %d\n", ptr->name, ptr->age);
    return 0;
}