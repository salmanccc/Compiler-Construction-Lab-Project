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
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%s ", root->value);
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%s ", root->value);
}

int main()
{
    Node *assign = createNode("=");
    Node *a = createNode("a");
    Node *plus = createNode("+");
    Node *b = createNode("b");
    Node *c = createNode("c");

    assign->left = a;
    assign->right = plus;
    plus->left = b;
    plus->right = c;

    printf("Preorder : ");
    preorder(assign);

    printf("\nInorder : ");
    inorder(assign);

    printf("\nPostorder : ");
    postorder(assign);

    printf("\n");

    return 0;
}
