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

/*
Allocate dynamic memory for a new game node
Assign the value, data to the node and make it points to NULL
 */
GameNode* createGameNode(Game newGame) {
    GameNode* newNode = (GameNode*)malloc(sizeof(GameNode));

    if (newNode == NULL) {
        printf("fail memory allocation\n");
        return NULL;
    }

    newNode->data = newGame;
    newNode->next = NULL;

    return newNode;
}

/*
Allocate dynamic memory for a new purchase node
Assign the data to the node and make it points to NULL
*/
PurchaseNode* createPurchaseNode(Purchase newPurchase) {
    PurchaseNode* newNode = (PurchaseNode*)malloc(sizeof(PurchaseNode));

    if (newNode == NULL) {
        printf("fail memory allocation\n");
        return NULL;
    }

    newNode->data = newPurchase;
    newNode->next = NULL;

    return newNode;
}
