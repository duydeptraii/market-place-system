#ifndef VAR_H
#define VAR_H

/* ==========================================================
STRUCTS DEFINITION
THIS MODULE DEFINE ALL THE DATA STRUCTURE USED IN THE SYSTEM
========================================================== */

// This is data structure to store the data
typedef struct {
    char gameName[100];
    int game_Id;
    float price;
} Game;

typedef struct {
    char gameName[100];
    int game_Id;
    float price;
} Purchase;


// This is data structure to implement linked list and queue

typedef struct GameNode{
    Game data;
    struct GameNode *next;
} GameNode;

typedef struct PurchaseNode{
    Purchase data;
    struct PurchaseNode *front;
    struct PurchaseNode *rear;
} PurchaseNode;

#endif
