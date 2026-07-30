#ifndef AST_H
#define AST_H

typedef struct Node
{
    char value[20];
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(char value[]);
void preorder(Node *root);

#endif
