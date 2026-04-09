#include<math.h>
#include <stdlib.h>
#include <string.h>
#include"logic.h"
#include <stdio.h>


void initQueue(PurchaseQueue *q){
        q->front=NULL;
        q->rear=NULL;

}
int isQueueEmpty(PurchaseQueue *q){
    if(q->front==NULL){
        return 1;
    }
    return 0;
    }
void enqueuePurchase(PurchaseQueue *q, Purchase data){
    PurchaseNode *newnode=malloc(sizeof(PurchaseNode));
    newnode->data=data;
    newnode->next=NULL;

    if(q->rear==NULL){
        q->front=newnode;
        q->rear=newnode;
    }
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
int dequeuePurchase(PurchaseQueue *q){
    if (q->front==NULL) return 0;
    PurchaseNode *temp=q->front;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(temp);
    return 1;
}
int peekQueue(PurchaseQueue *q){
    if (q->front==NULL){
        printf("There is no game in the list.\n");
        return 0;
    }
    PurchaseNode *temp=q->front;
    printf("GameID: %d, Name: %s, Price: %f\n",temp->data.game_Id,temp->data.gameName,temp->data.price);
    return 1;
}
void displayQueue(PurchaseQueue*q){
    PurchaseNode *temp=q->front;
    while (temp != NULL){
        printf("GameID: %d, Name: %s, Price: %f\n",temp->data.game_Id,temp->data.gameName,temp->data.price);
        temp=temp->next;
    }
}
