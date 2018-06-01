#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* createNewNode(int key);
void inserirAux(Node **root, int key);
void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);
void insertNode(Node **root, int key);
int Menu();
Node* searchNode(Node *root,int value);
void delTree(Node **root);
void delTreeAux(Node **root);
//void opcao(Node *root,int op);
#endif // LIBRARY_H_INCLUDED
