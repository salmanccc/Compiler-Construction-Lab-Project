#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preorder(struct Node* root)
{
    if(root == NULL)
        return;

    printf("%c ", root->data);

    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main()
{
    struct Node* root = createNode('=');

    root->left = createNode('a');
    root->right = createNode('+');

    root->right->left = createNode('b');
    root->right->right = createNode('c');

    printf("Preorder : ");
    preorder(root);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);

    printf("\n");

    return 0;
}
