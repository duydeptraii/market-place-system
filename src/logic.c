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

GameNode* createGameNode(char name[],int id, float price ){
    GameNode* newNode = (GameNode*)malloc(sizeof(GameNode));

    if(newNode ==NULL){
        printf("fail memory allocation\n");
        return NULL;
    }

    strcpy(newNode->data.gameName,name);
    newNode->data.game_Id = id;
    newNode->data.price = price;

    newNode->next = NULL;

    return newNode;
}

int main(){
    return 0;
}