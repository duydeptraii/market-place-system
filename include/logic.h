#ifndef LOGIC_H
#define LOGIC_H

/* ==========================================================
STRUCTS DEFINITION
THIS MODULE DEFINE ALL THE DATA STRUCTURE USED IN THE SYSTEM
========================================================== */

// This is data structure to store the data
typedef struct {
    int gameId;
    char gameName[100];
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
void initQueue(PurchaseQueue *queue);

// Check if queue is empty
int isQueueEmpty(PurchaseQueue *queue);

// Create a new purchase node
PurchaseNode* createPurchaseNode(Purchase newPurchase);

// Add element to queue
void enqueuePurchase(PurchaseQueue *queue, Purchase purchaseData);

// Remove element from queue
int dequeuePurchase(PurchaseQueue *queue);

// View front element without removing
int peekQueue(PurchaseQueue *queue);

// Display all queue elements
void displayQueue(PurchaseQueue *queue);


/* ==========================================================
   LINKED LIST FUNCTIONS FOR GAME
   ========================================================== */

// Initialize game list
void initGameList(GameNode **head);

// Create a new game node
GameNode* createGameNode(Game newGame);

// Add a game to the list
void addGameList(GameNode **head, Game newGame);

// Delete a game by ID
int deleteGame(GameNode **head, int gameId);

// Search game by ID
int searchGame(GameNode *head, int gameId);

// Display all games
void displayGames(GameNode *head);

// Free entire game list
void freeGameList(GameNode **head);
#endif
