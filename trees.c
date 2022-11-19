#include<stdio.h>
#include "trees.h"
#include<stdlib.h>

int enqueue(Nqueue *head,Node node){
    Nqueue *next = head->next;
    Nqueue *new = (Nqueue *)malloc(sizeof(Nqueue));
    //printf("New location @ %p\n",new);
    if (new==NULL){
        printf("An error in mem allocation occured! Exiting..");
        return 1;
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
    return 0;
}

void dequeue(Nqueue **head_ptr){
   if(*(head_ptr)==NULL){
    printf("Queue is already empty!");
    return 1;
   }

   else{
    //Nqueue **head_ptr = (Nqueue **)malloc(sizeof(Nqueue*));
    Nqueue *temp = (*head_ptr)->next;
    *head_ptr = temp;
    return 0;
   } 
}

void traverse(Nqueue *head){
    while (head!=NULL){
        printf("current addr: %p value: %d next_elements addr: %p \n",head,head->elem,head->next);
        head = head->next;
    }
    printf("\n");
    return;
}