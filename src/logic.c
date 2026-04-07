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