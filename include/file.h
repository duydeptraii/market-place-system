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
