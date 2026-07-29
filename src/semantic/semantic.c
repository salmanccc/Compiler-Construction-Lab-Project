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

int search(char name[])
{
    for(int i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, name) == 0)
            return i;
    }
    return -1;
}

void declare(char name[], char type[])
{
    if(search(name) != -1)
    {
        printf("Semantic Error: %s already declared\n", name);
        return;
    }

    strcpy(table[count].name, name);
    strcpy(table[count].type, type);
    count++;

    printf("%s declared successfully\n", name);
}

void use(char name[])
{
    int index = search(name);

    if(index == -1)
    {
        printf("Semantic Error: %s is not declared\n", name);
    }
    else
    {
        printf("%s used successfully (Type: %s)\n",
               table[index].name,
               table[index].type);
    }
}

void display()
{
    printf("\n===== SYMBOL TABLE =====\n");
    printf("%-15s %-10s\n","Name","Type");

    for(int i=0;i<count;i++)
    {
        printf("%-15s %-10s\n",
        table[i].name,
        table[i].type);
    }
}

int main()
{
    declare("age","int");
    declare("cgpa","float");
    declare("name","char");

    declare("age","int");

    use("age");
    use("cgpa");
    use("salary");

    display();

    return 0;
}
