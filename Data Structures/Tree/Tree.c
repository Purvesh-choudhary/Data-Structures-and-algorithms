#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node* createNode(){
    int data;
    struct node *newnode;
    newnode = (struct node * )malloc(sizeof(struct node));
    printf("\nEnter The data you want to insert : ");
    scanf("%d",&data);
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    printf("Inserted %d\n",data);
    return newnode;
}

void preorder(struct node * root){
    if(root!=NULL){
        printf("%d | ",root->data);
        preorder(root->right);
        preorder(root->left);
    }
}

void postorder(struct node * root){
    if(root!=NULL){
        postorder(root->right);
        postorder(root->left);
        printf("%d | ",root->data);
    }
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->right);
        printf("%d | ",root->data);
        inorder(root->left);
    }
}

void deleteNode(struct node *root) {
    if (root == NULL) {
        return;
    }
    deleteNode(root->left);
    deleteNode(root->right);
    printf("\nDeleted : %d", root->data);
    free(root);
}

int main(){

    struct node* root ;
    root = createNode();
    root->left = createNode();
    root->right = createNode();
    root->left->left = createNode();
    root->left->right = createNode();
    root->right->left = createNode();
    root->right->right = createNode();

    
    printf("\nPre-order  : ");
    preorder(root);
    printf("\nPost-order : ");
    postorder(root);
    printf("\nIn-order   : ");
    inorder(root);

    deleteNode(root->right->left);

    printf("\nPre-order  : ");
    preorder(root);
    printf("\nPost-order : ");
    postorder(root);
    printf("\nIn-order   : ");
    inorder(root);

    return 0;
}
