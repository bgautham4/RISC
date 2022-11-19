#include<stdio.h>
#include "trees.h"
#include<stdlib.h>
int main(){
    Node *c1 = (Node *)malloc(sizeof(Node));
    c1->elem = 'B';
    Node *c2 = (Node *)malloc(sizeof(Node));
    c2->elem = 'C';
    Node *root = (Node *)malloc(sizeof(Node));
    root = link_nodes_to(c1,c2,'A'); //Link 2 children node c1 and c2 to A.
    printf("Root node %c has children %c and %c \n",root->elem,root->c1->elem,root->c2->elem);
    printf("c1's parent is %c\n",c1->p->elem);
    return 0;
}
