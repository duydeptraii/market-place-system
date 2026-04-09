/*
 * logic.c
 *
 * Description:
 * This file implements the core logic of the marketplace system.
 * It uses a singly linked list to manage games and a queue to store
 * purchase history.
 *
 * Responsibilities:
 * - Create and manage linked list of games
 * - Add, delete, update, search, and display games
 * - Implement queue operations (enqueue, display history)
 * - Use dynamic memory allocation (malloc/free)
 *
 * Data Structures:
 * - struct Game (linked list)
 * - struct Purchase (queue)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file.h"
#include "../include/logic.h"

void initQueue(PurchaseQueue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(PurchaseQueue *q){
    if(q->rear ==NULL){
        return 1;
    } else{return 0;}
}

GameNode* createGameNode(Game data){
    GameNode* newNode = (GameNode*)malloc(sizeof(GameNode));

    if(newNode ==NULL){
        printf("fail memory allocation\n");
        return NULL;
    }

    newNode->data = data;

    newNode->next = NULL;

    return newNode;
}

void insertGame(GameNode** head, Game data) {
    GameNode* newNode = createGameNode(data);
    if (newNode == NULL) return;
    newNode->next = *head;
    *head = newNode;
}

int deleteGame(GameNode** head, int gameId) {
    GameNode* curr = *head;
    GameNode* prev = NULL;
    while (curr != NULL) {
        if (curr->data.gameId == gameId) {
            if (prev == NULL) *head = curr->next;
            else              prev->next = curr->next;
            free(curr);   // <-- Part 3 key requirement
            printf("Game %d deleted.\n", gameId);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Game %d not found.\n", gameId);
    return 0;
}

void freeGameList(GameNode** head) {
    GameNode* curr = *head;
    while (curr != NULL) {
        GameNode* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}

void enqueuePurchase(PurchaseQueue *q, Purchase data) {
    PurchaseNode *newNode = (PurchaseNode *)malloc(sizeof(PurchaseNode));
    if (newNode == NULL) {
        printf("Memory allocation failed for queue node.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to new node
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    
    // Otherwise, add to the end and update rear pointer
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeuePurchase(PurchaseQueue *q, Purchase *data) {
    if (isQueueEmpty(q)) return 0;

    PurchaseNode *temp = q->front;
    *data = temp->data; // Extract the data to return
    q->front = q->front->next; // Move front pointer forward

    // If the queue becomes empty, reset rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return 1;
}

int peekQueue(PurchaseQueue *q, Purchase *data) {
    if (isQueueEmpty(q)) return 0;
    *data = q->front->data;
    return 1;
}

void displayQueue(PurchaseQueue *q) {
    if (isQueueEmpty(q)) {
        printf("Purchase history is empty.\n");
        return;
    }
    PurchaseNode *curr = q->front;
    printf("\n--- Purchase History ---\n");
    while (curr != NULL) {
        printf("ID: %d | Name: %s | Price: $%.2f\n", 
               curr->data.gameId, curr->data.gameName, curr->data.price);
        curr = curr->next;
    }
}

void initGameList(GameNode **head) {
    *head = NULL;
}

GameNode* searchGame(GameNode *head, int gameId) {
    GameNode *curr = head;
    while (curr != NULL) {
        if (curr->data.gameId == gameId) return curr;
        curr = curr->next;
    }
    return NULL; // Not found
}

void displayGames(GameNode *head) {
    if (head == NULL) {
        printf("No games available.\n");
        return;
    }
    GameNode *curr = head;
    printf("\n--- Game List ---\n");
    while (curr != NULL) {
        printf("ID: %d | Name: %s | Price: $%.2f\n", 
               curr->data.gameId, curr->data.gameName, curr->data.price);
        curr = curr->next;
    }
}