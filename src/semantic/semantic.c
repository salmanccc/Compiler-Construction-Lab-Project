#include <stdio.h>
#include <string.h>

#define MAX 100

struct Symbol
{
    char name[50];
    char type[20];
    int scope;
};

struct Symbol table[MAX];
int count = 0;

int currentScope = 0;

int search(char name[])
{
    for(int i = count - 1; i >= 0; i--)
    {
        if(strcmp(table[i].name, name) == 0)
            return i;
    }
    return -1;
}

void enterScope()
{
    currentScope++;
    printf("\nEntered Scope %d\n", currentScope);
}

void exitScope()
{
    printf("Exited Scope %d\n", currentScope);

    while(count > 0 && table[count-1].scope == currentScope)
    {
        count--;
    }

    currentScope--;
}

void declare(char name[], char type[])
{
    for(int i=0;i<count;i++)
    {
        if(strcmp(table[i].name,name)==0 &&
           table[i].scope==currentScope)
        {
            printf("Semantic Error: %s already declared\n",name);
            return;
        }
    }

    strcpy(table[count].name,name);
    strcpy(table[count].type,type);
    table[count].scope=currentScope;
    count++;

    printf("%s declared successfully\n",name);
}

void use(char name[])
{
    int index=search(name);

    if(index==-1)
    {
        printf("Semantic Error: %s is not declared\n",name);
        return;
    }

    printf("%s used successfully (Type: %s)\n",
           table[index].name,
           table[index].type);
}

void assign(char variable[],char valueType[])
{
    int index=search(variable);

    if(index==-1)
    {
        printf("Semantic Error: %s is not declared\n",variable);
        return;
    }

    if(strcmp(table[index].type,valueType)!=0)
    {
        printf("Semantic Error: Type Mismatch (%s is %s but assigned %s)\n",
               variable,
               table[index].type,
               valueType);
    }
    else
    {
        printf("Assignment successful.\n");
    }
}

void display()
{
    printf("\n===== SYMBOL TABLE =====\n");
    printf("%-15s %-10s %-5s\n","Name","Type","Scope");

    for(int i=0;i<count;i++)
    {
        printf("%-15s %-10s %-5d\n",
               table[i].name,
               table[i].type,
               table[i].scope);
    }
}

int main()
{
    declare("age","int");
    declare("cgpa","float");

    declare("age","int");

    use("age");
    use("salary");

    assign("age","float");
    assign("cgpa","float");

    enterScope();

    declare("x","int");
    use("x");

    exitScope();

    use("x");

    display();

    return 0;
}
