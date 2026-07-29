#include <stdio.h>

int temp = 1;

void generateTAC(char result, char op1, char op, char op2)
{
    printf("t%d = %c %c %c\n", temp, op1, op, op2);
    printf("%c = t%d\n", result, temp);
    temp++;
}

int main()
{
    printf("Three Address Code (TAC)\n");
    printf("------------------------\n");

    generateTAC('a', 'b', '+', 'c');
    generateTAC('x', 'a', '*', 'd');
    generateTAC('y', 'x', '-', 'e');

    return 0;
}
