#include <stdio.h>
#include <string.h>

char symbolTable[100][50];
int count = 0;

int exists(char id[])
{
    for(int i=0;i<count;i++)
    {
        if(strcmp(symbolTable[i],id)==0)
            return 1;
    }
    return 0;
}

void insert(char id[])
{
    if(!exists(id))
    {
        strcpy(symbolTable[count],id);
        count++;
        printf("%s declared successfully\n",id);
    }
    else
    {
        printf("Semantic Error: %s already declared\n",id);
    }
}

int main()
{
    insert("age");
    insert("cgpa");
    insert("age");

    return 0;
}
