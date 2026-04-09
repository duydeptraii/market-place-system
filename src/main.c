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
    PurchaseQueue q;
    initQueue(&q);

    // 1. Load data from files at startup
    loadGamesFromFile(&head);
    loadHistoryFromFile(&q);

    int choice;
    do {
        // 2. Display the main menu
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
            while (getchar() != '\n'); // Clear invalid text input
            continue;
        }

        // 3. Handle user actions
        if (choice == 1) {
            Game g;
            printf("Enter Game ID: ");
            scanf("%d", &g.gameId);
            printf("Enter Game Name: ");
            scanf(" %99[^\n]", g.gameName); // Reads a string with spaces
            printf("Enter Game Price: ");
            scanf("%f", &g.price);
            insertGame(&head, g);
            printf("Game added successfully!\n");
        } else if (choice == 2) {
            int id;
            printf("Enter Game ID to delete: ");
            scanf("%d", &id);
            deleteGame(&head, id);
        } else if (choice == 3) {
            displayGames(head);
        } else if (choice == 4) {
            int id;
            printf("Enter Game ID to buy: ");
            scanf("%d", &id);
            GameNode *found = searchGame(head, id);
            
            if (found != NULL) {
                Purchase p;
                p.gameId = found->data.gameId;
                strcpy(p.gameName, found->data.gameName);
                p.price = found->data.price;
                enqueuePurchase(&q, p);
                printf("Successfully purchased: %s\n", p.gameName);
            } else {
                printf("Error: Game ID %d not found in the marketplace.\n", id);
            }
        } else if (choice == 5) {
            displayQueue(&q);
        }
    } while (choice != 6);

    // 4. Save to text files and free memory on exit
    saveGamesToFile(head);
    saveHistoryToFile(&q);
    freeGameList(&head);

    printf("\nExiting Marketplace. Goodbye!\n");
    return 0;
}