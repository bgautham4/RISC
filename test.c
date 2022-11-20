#include<stdio.h>
#include "trees.h"
#include<stdlib.h>
int main(){
    Node *n = link_nodes_to(NULL,NULL,'N');
    Node *j = link_nodes_to(n,NULL,'J');
    Node *i = link_nodes_to(NULL,NULL,'I');
    Node *d = link_nodes_to(i,j,'D');
    Node *c = link_nodes_to(d,NULL,'C');
    Node *o = link_nodes_to(NULL,NULL,'O');
    Node *m = link_nodes_to(NULL,NULL,'M');
    Node *h = link_nodes_to(o,m,'H');
    Node *g = link_nodes_to(NULL,NULL,'G');
    Node *e = link_nodes_to(g,h,'E');
    Node *k = link_nodes_to(NULL,NULL,'K');
    Node *l = link_nodes_to(NULL,NULL,'L');
    Node *f = link_nodes_to(k,l,'F');
    Node *b = link_nodes_to(f,NULL,'B');
    Node *a = link_nodes_to(b,e,'A');
    Node *root = link_nodes_to(a,c,'S'); //Source Node
    char *path;
    path = BFS(root,'N');
    display_path(path);
    return 0;
}
