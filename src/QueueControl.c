#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/logic.h"

void initQueue(PurchaseQueue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isQueueEmpty(PurchaseQueue *queue) {
    return queue->front == NULL;
}

void enqueuePurchase(PurchaseQueue *queue, Purchase purchaseData) {
    PurchaseNode *newNode = createPurchaseNode(purchaseData);
    
    if (newNode == NULL) {
        return; // Exit if memory allocation failed
    }

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeuePurchase(PurchaseQueue *queue) {
    if (isQueueEmpty(queue)) return 0;

    PurchaseNode *tempNode = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(tempNode);
    return 1;
}

int peekQueue(PurchaseQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("There is no game in the list.\n");
        return 0;
    }
    PurchaseNode *tempNode = queue->front;
    printf("ID: %d | Name: %s | Price: $%.2f\n", tempNode->data.gameId, tempNode->data.gameName, tempNode->data.price);
    return 1;
}

void displayQueue(PurchaseQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Purchase history is empty.\n");
        return;
    }
    PurchaseNode *tempNode = queue->front;
    printf("\n--- Purchase History ---\n");
    while (tempNode != NULL) {
        printf("ID: %d | Name: %s | Price: $%.2f\n", tempNode->data.gameId, tempNode->data.gameName, tempNode->data.price);
        tempNode = tempNode->next;
    }
}
