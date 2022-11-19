#include<stdio.h>
#include "trees.h"
#include<stdlib.h>

void enqueue(Nqueue *head,Node node){
    Nqueue *next = head->next;
    Nqueue *new = (Nqueue *)malloc(sizeof(Nqueue));
    //printf("New location @ %p\n",new);
    if (new==NULL){
        printf("An error in mem allocation occured! Exiting..");
        return;
    }
    else{
        new->node = node;
        new->next = NULL;
    }
    while (next!=NULL){
        head = next;
        next = head->next;
    }
    head->next = new;
    return;
}

void dequeue(Nqueue **head_ptr){
   if(*(head_ptr)==NULL){
    printf("Queue is already empty!");
    return;
   }

   else{
    //Nqueue **head_ptr = (Nqueue **)malloc(sizeof(Nqueue*));
    Nqueue *temp = (*head_ptr)->next;
    *head_ptr = temp;
    return;
   } 
}

void traverse(Nqueue *head){
    while (head!=NULL){
        //printf("current addr: %p value: %d next_elements addr: %p \n",head,head->elem,head->next);
        printf("Node elem = %c\n",head->node.elem);
        head = head->next;
    }
    printf("\n");
    return;
}

Node * link_nodes_to(Node *child1,Node *child2,char parent_val){
    Node *parent_node = (Node *)malloc(sizeof(Node));
    parent_node->c1 = child1;
    parent_node->c2 = child2;
    parent_node->elem = parent_val;
    if(child1!=NULL){
        child1->p = parent_node;
    }
    if(child2!=NULL){
        child2->p = parent_node;
    }
    return parent_node;
}