//updated
#include <stdio.h>

void generateAssignment(char var[], int value)
{
    printf("MOV %s, %d\n", var, value);
}

void generatePrint(char var[])
{
    printf("PRINT %s\n", var);
}

int main()
{
    printf("===== CODE GENERATION =====\n\n");

    generateAssignment("age", 20);
    generateAssignment("marks", 95);

    generatePrint("age");
    generatePrint("marks");

    return 0;
}
