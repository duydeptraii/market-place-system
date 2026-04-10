#include <stdlib.h>
#include <string.h>
#include "../include/logic.h"
#include <stdio.h>

/*
 * initGameList:
 * This function initializes the singly linked list by assigning
 * the head pointer to NULL.
 * In technical terms, this establishes an empty list state,
 * indicating that no game nodes are currently stored in memory.
 */
void initGameList(GameNode **head){
    *head = NULL;
}

/*
 * addGameList:
 * This function inserts a new node at the beginning of the linked list.
 * A new GameNode is dynamically allocated using malloc(),
 * the game data is copied into the node, and the node is linked
 * to the current head of the list.
 * Finally, the head pointer is updated to point to the new node.
 * This insertion method is efficient because it operates in constant time, O(1).
 */
void addGameList(GameNode **head, Game data){
    GameNode *temp = malloc(sizeof(GameNode));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

/*
 * deleteGame:
 * This function removes a node from the linked list based on the specified game ID.
 * The function first checks whether the target node is located at the head.
 * If so, the head pointer is updated and the node is deallocated.
 * Otherwise, the function traverses the list using two pointers:
 * one pointer tracks the current node, and the other tracks the previous node.
 * Once the target node is found, the previous node is linked directly
 * to the next node, thereby removing the target node from the list.
 * The removed node is then freed from memory.
 * The function returns 1 if deletion is successful and 0 if the ID is not found.
 */
int deleteGame(GameNode **head, int ID){
    GameNode *temp = *head;

    if (temp != NULL && temp->data.game_Id == ID){
        *head = temp->next;
        free(temp);
        return 1;
    }

    GameNode *prvtemp = temp;
    temp = temp->next;

    while (temp != NULL){
        if (temp->data.game_Id == ID){
            prvtemp->next = temp->next;
            free(temp);
            return 1;
        }
        prvtemp = temp;
        temp = temp->next;
    }

    printf("Can't find ID: %d\n", ID);
    free(temp);
    return 0;
}

/*
 * searchGame:
 * This function performs a linear search on the linked list
 * to locate a game node with the specified ID.
 * The traversal begins at the head node and continues sequentially
 * until either the target node is found or the end of the list is reached.
 * If a matching node is found, its data is displayed and the function returns 1.
 * Otherwise, the function reports that the ID was not found and returns 0.
 */
int searchGame(GameNode *head, int ID){
    GameNode *temp = head;

    while (temp != NULL){
        if (temp->data.game_Id == ID){
            printf("GameID: %d, Name: %s, Price: %f\n",
                   temp->data.game_Id,
                   temp->data.gameName,
                   temp->data.price);
            return 1;
        }
        temp = temp->next;
    }

    printf("Can't find ID: %d\n", ID);
    return 0;
}

/*
 * displayGames:
 * This function traverses the linked list from the head node to the final node
 * and prints the data stored in each element.
 * In technical terms, this is a full sequential traversal of a singly linked list.
 * The loop terminates when the temporary pointer becomes NULL,
 * indicating that the end of the list has been reached.
 */
void displayGames(GameNode *head) {
    GameNode *temp = head;

    while (temp != NULL) {
        printf("GameID: %d, Name: %s, Price: %.2f\n",
               temp->data.game_Id,
               temp->data.gameName,
               temp->data.price);
        temp = temp->next;
    }
}

/*
 * freeGameList:
 * This function releases all nodes in the linked list from dynamically allocated memory.
 * It repeatedly removes the head node, advances the head pointer to the next node,
 * and deallocates the removed node using free().
 * This process continues until the list becomes empty.
 * The function is essential for preventing memory leaks in programs
 * that use dynamic memory allocation.
 */
void freeGameList(GameNode **head){
    GameNode *temp;

    while (*head != NULL){
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

