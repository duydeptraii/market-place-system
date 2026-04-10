#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/logic.h"


/*
 * initQueue:
 * This function initializes a queue data structure by assigning both
 * the front pointer and the rear pointer to NULL.
 * In technical terms, this establishes an empty-state condition for
 * the linked-list-based queue before any insertion operation is performed.
 */
void initQueue(PurchaseQueue *q){
    q->front = NULL;
    q->rear = NULL;
}

/*
 * isQueueEmpty:
 * This function evaluates whether the queue contains any nodes.
 * If the front pointer is NULL, the queue is considered empty.
 * The function returns 1 for an empty queue and 0 otherwise.
 */
int isQueueEmpty(PurchaseQueue *q){
    if(q->front == NULL){
        return 1;
    }
    return 0;
}

/*
 * enqueuePurchase:
 * This function performs the enqueue operation, which inserts a new
 * element at the rear of the queue following the FIFO (First-In, First-Out) principle.
 * A new node is dynamically allocated in memory, its data field is assigned,
 * and its next pointer is initialized to NULL.
 * If the queue is initially empty, both front and rear point to the new node.
 * Otherwise, the new node is linked after the current rear node,
 * and the rear pointer is updated accordingly.
 */
void enqueuePurchase(PurchaseQueue *q, Purchase data){
    PurchaseNode *newnode = malloc(sizeof(PurchaseNode));
    newnode->data = data;
    newnode->next = NULL;

    if(q->rear == NULL){
        q->front = newnode;
        q->rear = newnode;
    }
    else{
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

/*
 * dequeuePurchase:
 * This function performs the dequeue operation, which removes the node
 * located at the front of the queue.
 * If the queue is empty, the function returns 0 to indicate failure.
 * Otherwise, the front pointer is advanced to the next node,
 * the removed node is deallocated from memory using free(),
 * and 1 is returned to indicate successful deletion.
 * If the deletion causes the queue to become empty, the rear pointer is also reset to NULL.
 */
int dequeuePurchase(PurchaseQueue *q){
    if(q->front == NULL) return 0;

    PurchaseNode *temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL){
        q->rear = NULL;
    }

    free(temp);
    return 1;
}

/*
 * peekQueue:
 * This function accesses the element at the front of the queue
 * without removing it from the data structure.
 * This operation is commonly referred to as a "peek" operation.
 * If the queue is empty, an informative message is displayed
 * and the function returns 0.
 * Otherwise, the information stored in the front node is printed,
 * and the function returns 1.
 */
int peekQueue(PurchaseQueue *q){
    if(q->front == NULL){
        printf("There is no game in the list.\n");
        return 0;
    }

    PurchaseNode *temp = q->front;
    printf("GameID: %d, Name: %s, Price: %f\n",
           temp->data.game_Id,
           temp->data.gameName,
           temp->data.price);
    return 1;
}

/*
 * displayQueue:
 * This function traverses the queue from the front node to the rear node
 * and displays the data stored in each node.
 * In technical terms, this is a linear traversal of a singly linked list.
 * The traversal continues until the temporary pointer reaches NULL,
 * which indicates the end of the queue.
 */
void displayQueue(PurchaseQueue *q){
    PurchaseNode *temp = q->front;

    while(temp != NULL){
        printf("GameID: %d, Name: %s, Price: %f\n",
               temp->data.game_Id,
               temp->data.gameName,
               temp->data.price);
        temp = temp->next;
    }
}
