/*
 *
 * Description:
 * This file handles all file input and output operations for the system.
 * It reads data from files into linked lists and writes updated data
 * back to files.
 *
 * Responsibilities:
 * - Load game data from file into linked list
 * - Save game data to file
 * - Save and load purchase history
 * - Ensure data persistence between program runs
 *
 * Files Used:
 * - data/games.txt
 * - data/history.txt
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file.h"
#include "../include/logic.h"

void saveGamesToFile(GameNode *head) {
    FILE *filePtr = fopen("data/games.txt", "w");
    if (filePtr == NULL) {
        printf("Error: can't open games.txt for writing\n");
        return;
    }

    GameNode *currentNode = head;
    while (currentNode != NULL) {
        fprintf(filePtr, "%d|%s|%.2f\n",
                currentNode->data.gameId,
                currentNode->data.gameName,
                currentNode->data.price);
        currentNode = currentNode->next;
    }

    fclose(filePtr);
    printf("Games saved successfully. \n");
}

void loadGamesFromFile(GameNode **head) {
    FILE *filePtr = fopen("data/games.txt", "r");
    if (filePtr == NULL) {
        printf("no existing game file \n");
        return;
    }

    int gameId;
    float gamePrice;
    char gameName[100];

    while (fscanf(filePtr, "%d|%99[^|]|%f\n", &gameId, gameName, &gamePrice) == 3) {
        Game newGame;
        newGame.gameId = gameId;
        strcpy(newGame.gameName, gameName);
        newGame.price = gamePrice;
        addGameList(head, newGame);
    }

    fclose(filePtr);
    printf("games loaded successfully.\n");
}

void saveHistoryToFile(PurchaseQueue *queue) {
    FILE *filePtr = fopen("data/history.txt", "w");
    if (filePtr == NULL) {
        printf("error: cannot open history.txt for writing\n");
        return;
    }

    PurchaseNode *currentNode = queue->front;
    while (currentNode != NULL) {
        fprintf(filePtr, "%d|%s|%.2f\n",
                currentNode->data.gameId,
                currentNode->data.gameName,
                currentNode->data.price);
        currentNode = currentNode->next;
    }

    fclose(filePtr);
    printf("History saved successfully.\n");
}

void loadHistoryFromFile(PurchaseQueue *queue) {
    FILE *filePtr = fopen("data/history.txt", "r");
    if (filePtr == NULL) {
        printf("No existing history file\n");
        return;
    }

    int gameId;
    float gamePrice;
    char gameName[100];

    while (fscanf(filePtr, "%d|%99[^|]|%f\n", &gameId, gameName, &gamePrice) == 3) {
        Purchase newPurchase;
        newPurchase.gameId = gameId;
        strcpy(newPurchase.gameName, gameName);
        newPurchase.price = gamePrice;
        enqueuePurchase(queue, newPurchase);
    }

    fclose(filePtr);
    printf("History loaded successfully.\n");
}