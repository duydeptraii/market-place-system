/*
 * file.c
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
    FILE *f = fopen("data/games.txt","w");
    if (f == NULL) {
        printf("Error: can't open games.txt for writing\n");
        return;
    }

    GameNode *curr = head;
    while (curr != NULL){
        fprintf(f,"%d|%s|%.2f\n",
        curr->data.gameId,
        curr->data.gameName,
        curr->data.price);
    curr = curr->next;
    }

    fclose(f);
    printf("Games saved successfully. \n");
}

void loadGamesFromFile(GameNode **head) {
    FILE *f = fopen("data/games.txt", "r");
    if (f == NULL){
        printf("no existing game file \n");
        return;
    }

    int id;
    float price;
    char name[100];

    while (fscanf(f,"%d|%99[^|]|%f\n", &id, name, &price) == 3) {
        Game g;
        g.gameId =id;
        strcpy(g.gameName, name);
        g.price = price;
        insertGame(head,g);
    }

    fclose(f);
    printf("games loaded successfully.\n");
}

void saveHistoryToFile(PurchaseQueue *q){
    FILE *f = fopen("data/history.txt", "w");
    if(f == NULL){
        printf("error: cannot open history.txt for writing\n");
        return;
    }

    PurchaseNode  *curr = q->front;
    while(curr!=NULL){
        fprintf(f, "%d|%s|%.2f\n",
                curr->data.gameId,
                curr->data.gameName,
                curr->data.price);
        curr = curr->next;
    }

    fclose(f);
    printf("History saved successfully.\n");
}

void loadHistoryFromFile(PurchaseQueue *q){
    FILE *f = fopen("data/history.txt","r");
    if (f==NULL){
        printf("No existing history file\n");
        return;
    }

    int id;
    float price;
    char name[100];

    while (fscanf(f,"%d|%99[^|]|%f\n", &id, name, &price) == 3) {
        Purchase p;
        p.gameId = id;
        strcpy(p.gameName, name);
        p.price = price;
        enqueuePurchase(q,p);
    }

    fclose(f);
    printf("History loaded successfully.\n");
}