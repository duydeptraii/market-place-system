/*
 * logic.h
 *
 * Description:
 * Header file for logic.c. Contains structure definitions and
 * function prototypes for managing the game list and purchase queue.
 *
 * Responsibilities:
 * - Define struct Game and struct Purchase
 * - Declare all functions used in logic.c
 * - Allow other files (main.c, file.c) to access logic functions
 *
 */

#ifndef LOGIC_H
#define LOGIC_H

#include "file.h"

/* ==========================================================
   QUEUE FUNCTION DECLARATIONS
   ========================================================== */

// Initialize queue
void initQueue(PurchaseQueue *q);

// Check if queue is empty
int isQueueEmpty(PurchaseQueue *q);

// Add element to queue
void enqueuePurchase(PurchaseQueue *q, Purchase data);

// Remove element from queue
int dequeuePurchase(PurchaseQueue *q, Purchase *data);

// View front element without removing
int peekQueue(PurchaseQueue *q, Purchase *data);

// Display all queue elements
void displayQueue(PurchaseQueue *q);

/* ==========================================================
   LINKED LIST FUNCTIONS FOR GAME
   ========================================================== */

// Initialize game list
void initGameList(GameNode **head);

// Add a game to the list
void insertGame(GameNode **head, Game data);

// Delete a game by ID
int deleteGame(GameNode **head, int gameId);

// Search game by ID
GameNode* searchGame(GameNode *head, int gameId);

// Display all games
void displayGames(GameNode *head);

// Free entire game list
void freeGameList(GameNode **head);

#endif