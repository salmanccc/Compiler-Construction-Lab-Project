#include <stdio.h>
#include <string.h>

#define MAX 100

struct Symbol
{
    char name[50];
    char type[20];
};

struct Symbol table[MAX];
int count = 0;

void insert(char name[], char type[])
{
    for(int i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, name) == 0)
        {
            printf("Error: %s already declared\n", name);
            return;
        }
    }

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    count++;
}

void display()
{
    printf("\n========== SYMBOL TABLE ==========\n");
    printf("%-15s %-10s\n", "Name", "Type");
    printf("----------------------------------\n");

    for(int i = 0; i < count; i++)
    {
        printf("%-15s %-10s\n", table[i].name, table[i].type);
    }
}

int main()
{
    insert("age", "int");
    insert("cgpa", "float");
    insert("name", "char");
    insert("age", "int");

    display();

    return 0;
}
