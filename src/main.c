/*
 * main.c
 *
 * Description:
 * This file contains the main function and handles all user interaction.
 * It displays the menu, takes user input, and calls appropriate functions
 * from logic.c and file.c.
 *
 * Responsibilities:
 * - Display menu options
 * - Handle user input
 * - Call functions such as addGame, deleteGame, buyGame, etc.
 * - Coordinate between logic and file modules
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file.h"
#include "../include/logic.h"

int main(){
    GameNode *head = NULL;
    PurchaseQueue purchaseQueue;
    initQueue(&purchaseQueue);

    
    loadGamesFromFile(&head);
    loadHistoryFromFile(&purchaseQueue);

    int choice;
    do {
        
        printf("\n============================\n");
        printf("   Marketplace Main Menu\n");
        printf("============================\n");
        printf("1. Add a Game\n");
        printf("2. Delete a Game\n");
        printf("3. Display All Games\n");
        printf("4. Buy a Game\n");
        printf("5. View Purchase History\n");
        printf("6. Save & Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            int inputChar;
            while ((inputChar = getchar()) != '\n' && inputChar != EOF);    
            if (inputChar == EOF) {
                break; 
            }
            continue;
        }

        // 3. Handle user actions
        if (choice == 1) {
            Game newGame;
            printf("Enter Game ID: ");
            scanf("%d", &newGame.gameId);
            printf("Enter Game Name: ");
            scanf(" %99[^\n]", newGame.gameName); // Reads a string with spaces
            printf("Enter Game Price: ");
            scanf("%f", &newGame.price);
            addGameList(&head, newGame);
            printf("Game added successfully!\n");
        } else if (choice == 2) {
            int deleteId;
            printf("Enter Game ID to delete: ");
            scanf("%d", &deleteId);
            deleteGame(&head, deleteId);
        } else if (choice == 3) {
            displayGames(head);
        } else if (choice == 4) {
            int searchId;
            printf("Enter Game ID to buy: ");
            scanf("%d", &searchId);
            int isFound = searchGame(head, searchId);
            
            if (isFound) {
                GameNode *currentNode = head;
                // Retrieve the node manually since searchGame only returns 1 or 0
                while (currentNode != NULL && currentNode->data.gameId != searchId) {
                    currentNode = currentNode->next;
                }
                if (currentNode != NULL) {
                    Purchase newPurchase;
                    newPurchase.gameId = currentNode->data.gameId;
                    strcpy(newPurchase.gameName, currentNode->data.gameName);
                    newPurchase.price = currentNode->data.price;
                    enqueuePurchase(&purchaseQueue, newPurchase);
                    printf("Successfully purchased: %s\n", newPurchase.gameName);
                }
            } else {
                printf("Error: Game ID %d not found in the marketplace.\n", searchId);
            }
        } else if (choice == 5) {
            displayQueue(&purchaseQueue);
        }
    } while (choice != 6);

    // 4. Save to text files and free memory on exit
    saveGamesToFile(head);
    saveHistoryToFile(&purchaseQueue);
    freeGameList(&head);

    printf("\nExiting Marketplace. Goodbye!\n");
    return 0;
}