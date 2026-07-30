#include <stdio.h>
#include <string.h>

char symbolTable[100][50];
int count = 0;

int exists(char id[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(symbolTable[i], id) == 0)
            return 1;
    }
    return 0;
}

void declare(char id[])
{
    if (!exists(id))
    {
        strcpy(symbolTable[count], id);
        count++;
        printf("%s declared successfully\n", id);
    }
    else
    {
        printf("Semantic Error: %s already declared\n", id);
    }
}

void use(char id[])
{
    if (exists(id))
    {
        printf("%s used successfully\n", id);
    }
    else
    {
        printf("Semantic Error: %s is not declared\n", id);
    }
}

int main()
{
    declare("age");
    declare("cgpa");

    use("age");
    use("salary");

    return 0;
}