#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
//node create
Node* createNode(char value[])
{
    Node* node = (Node*)malloc(sizeof(Node));

    strcpy(node->value, value);
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preorder(Node* root)
{
    if(root == NULL)
        return;

    printf("%s ", root->value);

    preorder(root->left);
    preorder(root->right);
}
