#include "library.h"

int main(){
    Node *root = (Node *)malloc(sizeof(Node));
    root = NULL;
    Node *tmp;
    int choice, key, value;
    do{
        choice = Menu();
        switch(choice){
        case 1:
            printf("Enter a number: ");
            scanf("%d",&key);
            insertNode(&root,key);
            break;

        case 2:
            printPreOrder(root);
            break;

        case 3:
            printInOrder(root);
            break;

        case 4:
            printPostOrder(root);
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%d",&value);
            tmp = searchNode(root,value);
            if(tmp)
                printf("Searched node: %d\n",tmp->data);
            else
                printf("Data not found in tree.\n");
            break;

        case 6:
            delTree(&root);
            break;

        case 0:
            break;
        }

    }while(choice);

    return 0;
}
