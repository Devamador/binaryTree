#include "library.h"

int Menu(){
    int choice;
    printf("\n[1]Insert");
    printf("\n[2]Pre-Order Display");
    printf("\n[3]In order display");
    printf("\n[4]Post order display");
    printf("\n[5]Search");
    printf("\n[6]Delete Tree");
    printf("\n[0]EXIT");
    printf("\n\tChoice: ");
    scanf("%d",&choice);

    return choice;

}
Node* createNewNode(int key){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

void inserirAux(Node **root,int key){
    if((*root)->data > key){
        if((*root)->left == NULL)
            (*root)->left = createNewNode(key);
        else
            inserirAux(&(*root)->left,key);
    }else{
        if((*root)->right == NULL)
            (*root)->right = createNewNode(key);
        else
            inserirAux(&(*root)->right,key);

    }

}

void printPreOrder(Node *root){
    if(root){
        printf("Root: %d\n",root->data);
        printPreOrder(root->left);
        printInOrder(root->right);
    }
}

void printInOrder(Node *root){
    if(root){
        printInOrder(root->left);
        printf("\nRoot: %d",root->data);
        printInOrder(root->right);
    }
}

void printPostOrder(Node *root){
    if(root){
        printPostOrder(root->left);
        printPostOrder(root->right);
        printf("Root: %d\n",root->data);
    }

}

void insertNode(Node **root,int key){
    if(*root == NULL)
        *root = createNewNode(key);
    else
        inserirAux(&(*root),key);


}

Node* searchNode(Node *root,int value){
    if(!root)
        return NULL;
    if(root->data == value)
        return root;
    if(root->data > value)
        return searchNode(root->left,value);
    else
        return searchNode(root->right,value);


    ///!root ? NULL : root->data == value ? root : searchNode(root->data > value ? root->left : root->right,value );

}

void delTree(Node **root){
    delTreeAux(&(*root));
    *root = NULL;
}

void delTreeAux(Node **root){
    if(*root){
        delTreeAux(&(*root)->left);

        delTreeAux(&(*root)->right);
        free(*root);
    }


}

