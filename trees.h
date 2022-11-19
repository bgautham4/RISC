typedef struct Node{
    struct Node *p; //Parent node
    char elem; //element.
    struct Node *c1; //Child node 1
    struct Node *c2; //Child node 2
}Node;

typedef struct Node_queue{
    struct Node node; 
    struct Node_queue *next;
}Nqueue;

int enqueue(Nqueue *,Node);
void traverse(Nqueue *);
int dequeue(Nqueue **);

