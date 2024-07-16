#ifndef TREE_H
#define TREE_H

#include <stddef.h>

typedef struct Node {
    struct Node *p; //Parent node
    char elem; //element.
    struct Node *c1; //Child node 1
    struct Node *c2; //Child node 2
}Node;

typedef struct QueueNode {
    Node *qelem;
    struct QueueNode *next;
}QueueNode;

typedef struct NodeQueue {
    QueueNode *top;
    size_t size;
}NQueue;

typedef struct Path {
    char *chr_buff;
    size_t depth;
}Path;

void enqueue(NQueue *queue, Node *node);
void traverse(NQueue *queue);
void dequeue(NQueue *queue);

Node *link_nodes_to(Node *child_1, Node *child_2, char parent_elem);

Path BFS(Node *root, char elem);

void display_path(const Path *path);

#endif