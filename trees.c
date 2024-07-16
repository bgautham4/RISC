#include<stdio.h>
#include<stdlib.h>
#include "trees.h"

void enqueue(NQueue *queue, Node *node) {
    //Make new queue node and <node> into element
    QueueNode *qnode = (QueueNode*)malloc(sizeof(QueueNode));
    if (qnode == NULL) {
        printf("Failed to allocate memory in enque()\n");
        exit(EXIT_FAILURE);
    }    
    qnode->qelem = node;
    qnode->next = NULL;
    if (queue->size == 0) {
        queue->top = qnode;
        queue->size += 1;
        return;
    }
    QueueNode *qn_ptr = queue->top;
    for (size_t i = 1; i<queue->size; ++i) {
        qn_ptr = qn_ptr->next;
    }
    qn_ptr->next = qnode;
    queue->size += 1;
}

void dequeue(NQueue *queue) {
    if (queue->size == 0) {
        printf("Queue is already empty!!\n");
        return;
    }
    QueueNode *prev_top = queue->top;
    queue->top = prev_top->next;
    queue->size -= 1;
    free(prev_top);
}

void traverse(NQueue *queue) {
    QueueNode *qn_ptr = queue->top;
    for (size_t i = 1; i<queue->size; ++i) {
        printf("Node elem = %c\n",qn_ptr->qelem->elem);
        qn_ptr = qn_ptr->next;
    }
    printf("\n");
    return;
}

Node *link_nodes_to(Node *child_1,Node *child_2,char parent_elem){
    Node *parent_node = (Node *)malloc(sizeof(Node));
    if (parent_node == NULL) {
        printf("Failed to allocate memory in link_nodes_to()\n");
        exit(EXIT_FAILURE);
    }
    parent_node->c1 = child_1;
    parent_node->c2 = child_2;
    parent_node->elem = parent_elem;
    if(child_1!=NULL){
        child_1->p = parent_node;
    }
    if(child_2!=NULL){
        child_2->p = parent_node;
    }
    return parent_node;
}

Path BFS(Node *root,char elem){
    NQueue queue = {NULL, 0};
    Node *child_1 = root->c1;
    Node *child_2 = root->c2;
    char check = root->elem;
    enqueue(&queue, root);
    while (check != elem){
        if (child_1 != NULL){
            enqueue(&queue,child_1);
        }
        if (child_2 != NULL){
            enqueue(&queue, child_2);
        }
        dequeue(&queue);
        check = queue.top->qelem->elem;
        child_1 = queue.top->qelem->c1;
        child_2 = queue.top->qelem->c2;
    }
    
    Node *backtrack_node = queue.top->qelem; //To trace back upto parent
    char *path_chr_buff = (char*)malloc(100); //str buffer for Path struct
    if (path_chr_buff == NULL) {
        printf("Failed to allocate memory for chr_buff in BFS()\n");
        exit(EXIT_FAILURE);
    }
    size_t depth = 0;
    while (backtrack_node != NULL) {
        path_chr_buff[depth] = backtrack_node->elem;
        backtrack_node = backtrack_node->p;
        ++depth;
    }
    path_chr_buff[depth] = '\0';    
    Path path = {path_chr_buff, depth - 1};

    //Clean up queue
    while (queue.size > 0) {
        dequeue(&queue);
    }

    return path;
}

void display_path(const Path *path) {
    for (size_t i = 0; i <= path->depth; ++i) {
        printf("%c ", path->chr_buff[path->depth - i]);
    }
    printf("\n");
}
