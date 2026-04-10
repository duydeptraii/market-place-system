#ifndef VAR_H
#define VAR_H

#include "logic.h"

/* ==========================================================
   FILE I/O FUNCTION DECLARATIONS
   ========================================================== */

// Load games from file
void loadGamesFromFile(GameNode **head);

// Save games to file
void saveGamesToFile(GameNode *head);

// Load and save purchase history
void loadHistoryFromFile(PurchaseQueue *queue);
void saveHistoryToFile(PurchaseQueue *queue);

#endif
