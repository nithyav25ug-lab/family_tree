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

void read_person_info(const char *role, char *name_out, int *age_out)
{
    printf("Enter name and age for %s: ", role);
    scanf(" %99[^\n]", name_out);
    scanf("%d", age_out);
}

int main(void)
{
    Person* members[7];
    char name[100];
    int age;
    char role[7][25] = {"Yourself", 
        "Mother", "Father", 
        "Maternal Grandmother", "Maternal Grandfather", 
        "Paternal Grandmother", "Paternal Grandfather"};
    printf("=== ENTER FAMILY DETAILS ===\n");
    for (int i=0;i<7;i++)
    {
        read_person_info(role[i], name, &age);
        members[i]=create_person(name, age);
    }
    printf("=== MEMBERS ===\n");
    for (int i=0;i<7;i++)
    {
        printf("%d: %s of %d years old\n", i+1, members[i]->name, members[i]->age);
    }
    return 0;
}