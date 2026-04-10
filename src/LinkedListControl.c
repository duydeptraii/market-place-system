#include <stdlib.h>
#include <string.h>
#include "../include/logic.h"
#include <stdio.h>

void initGameList(GameNode **head) {
    *head = NULL;
}

void addGameList(GameNode **head, Game newGame) {
    GameNode *newNode = createGameNode(newGame);
    if (newNode == NULL) {
        return; // Exit if memory allocation failed
    }
    newNode->next = *head;
    *head = newNode;
}

int deleteGame(GameNode **head, int gameId) {
    GameNode *currentNode = *head;
    
    if (currentNode != NULL && currentNode->data.gameId == gameId) {
        *head = currentNode->next;
        free(currentNode);
        return 1;
    }
    if (currentNode == NULL) {
        printf("Can't find ID: %d\n", gameId);
        return 0;
    }

    GameNode *previousNode = currentNode;
    currentNode = currentNode->next;

    while (currentNode != NULL) {
        if (currentNode->data.gameId == gameId) {
            previousNode->next = currentNode->next;
            free(currentNode);
            return 1;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    printf("Can't find ID: %d\n", gameId);
    return 0;
}

int searchGame(GameNode *head, int gameId) {
    GameNode *currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->data.gameId == gameId) {
            printf("GameID: %d, Name: %s, Price: %f\n", currentNode->data.gameId, currentNode->data.gameName, currentNode->data.price);
            return 1;
        }
        currentNode = currentNode->next;
    }
    printf("Can't find ID: %d\n", gameId);
    return 0;
}

void displayGames(GameNode *head) {
    GameNode *currentNode = head;
    while (currentNode != NULL) {
        printf("GameID: %d, Name: %s, Price: %.2f\n",
               currentNode->data.gameId,
               currentNode->data.gameName,
               currentNode->data.price);
        currentNode = currentNode->next;
    }
}

void freeGameList(GameNode **head) {
    GameNode *currentNode;
    while (*head != NULL) {
        currentNode = *head;
        *head = currentNode->next;
        free(currentNode);
    }
}
