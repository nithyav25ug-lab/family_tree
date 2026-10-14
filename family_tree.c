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

void link_parents(Person *child, Person *father, Person *mother)
{
    child->father=father;
    child->mother=mother;
}

void print_family_relationships(const Person *me)
{
    printf("=== FAMILY TREE RELATIONSHIPS ===\n\n");
    printf("1. Yourself\n  -Name: %s | Age:%d\n\n", me->name, me->age);

    printf("2. PARENTS:\n");
    if (me->father) 
    {
        printf("   - Father: %s | Age: %d\n", me->father->name, me->father->age);
    }
    if (me->mother)
    {
        printf("   - Mother: %s | Age: %d\n\n", me->mother->name, me->mother->age);
    }

    printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
    if (me->father && me->father->father) 
    {
        printf("   - Grandfather: %s | Age: %d\n", me->father->father->name, me->father->father->age);
    }
    if (me->father && me->father->mother) 
    {
        printf("   - Grandmother: %s | Age: %d\n\n", me->father->mother->name, me->father->mother->age);
    }

    printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
    if (me->mother && me->mother->father) 
    {
            printf("   - Grandfather: %s | Age: %d\n", me->mother->father->name, me->mother->father->age);
    }
    if (me->mother && me->mother->mother) 
    {
        printf("   - Grandmother: %s | Age: %d\n\n", me->mother->mother->name, me->mother->mother->age);
    }
}

void point_tree_visual(const Person* root, int level)
{
    if (root == NULL) 
    {
        return;
    }
    if (level == 0) 
    {
        printf("%s (Age: %d)\n", root->name, root->age);
        if (root->mother != NULL) 
        {
            printf("  |-- Mother: %s (Age: %d)\n", root->mother->name, root->mother->age);
            point_tree_visual(root->mother, 1);
        }
        if (root->father != NULL) 
        {
            printf("  |-- Father: %s (Age: %d)\n", root->father->name, root->father->age);
            point_tree_visual(root->father, 2);
        }
    }
    else if (level == 1) 
    {
        if (root->mother != NULL) 
        {
            printf("  |   |-- Grandmother: %s (Age: %d)\n", root->mother->name, root->mother->age);
        }
        if (root->father != NULL) 
        {
            printf("  |   |-- Grandfather: %s (Age: %d)\n", root->father->name, root->father->age);
        }
    }
    else if (level == 2) 
    {
        if (root->mother != NULL) 
        {
            printf("      |-- Grandmother: %s (Age: %d)\n", root->mother->name, root->mother->age);
        }
        if (root->father != NULL) 
        {
            printf("      |-- Grandfather: %s (Age: %d)\n", root->father->name, root->father->age);
        }
    }
}

void free_family_tree(Person* people[], int count)
{
    for (int i=0;i<count;i++)
    {
        free(people[i]);
    }
}

int main(void)
{
    Person* members[7];
    char name[100];
    int age;
    static char role[7][25] = {"Yourself", 
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
    link_parents(members[0],members[2],members[1]);
    link_parents(members[1],members[4],members[3]);
    link_parents(members[2],members[6],members[5]);

    print_family_relationships(members[0]);

    printf("=== OPTIONAL BONUS TASK ===\n");
    point_tree_visual(members[0], 0);

    free_family_tree(members,7);
    return 0;
}