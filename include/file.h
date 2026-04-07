#ifndef VAR_H
#define VAR_H

/* ==========================================================
STRUCTS DEFINITION
THIS MODULE DEFINE ALL THE DATA STRUCTURE USED IN THE SYSTEM
========================================================== */

// This is data structure to store the data
typedef struct {
    char gameName[100];
    int gameId;
    float price;
} Game;

typedef struct {
    char gameName[100];
    int gameId;
    float price;
} Purchase;


// This is data structure to implement linked list and queue

typedef struct GameNode{
    Game data;
    struct GameNode *next;
} GameNode;

typedef struct PurchaseNode{
    Purchase data;
    struct PurchaseNode *next;
} PurchaseNode;
typedef struct  {
    PurchaseNode *front;
    PurchaseNode *rear;
} PurchaseQueue;

/* ==========================================================
   FILE I/O FUNCTION DECLARATIONS
   ========================================================== */

// Load games from file
void loadGamesFromFile(GameNode **head);

// Save games to file
void saveGamesToFile(GameNode *head);

// Load and save purchase history
void loadHistoryFromFile(PurchaseQueue *q);
void saveHistoryToFile(PurchaseQueue *q);

#endif
