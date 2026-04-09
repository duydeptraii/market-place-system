#include<math.h>
#include <stdlib.h>
#include <string.h>
#include"logic.h"
#include <stdio.h>
void initGameList(GameNode **head){
    *head=NULL;
}
void addGameList(GameNode **head, Game data){
    GameNode *temp=malloc(sizeof(GameNode));
    temp->data=data;
    temp->next=*head;
    *head=temp;
}
int deleteGame(GameNode **head, int ID){
    GameNode *temp=*head;
    if (temp != NULL && temp->data.game_Id==ID){
        *head=temp->next;
        free(temp);
        return 1;
    }
    GameNode *prvtemp=temp;
    temp=temp->next;

    while (temp != NULL){
        if (temp->data.game_Id == ID){

            prvtemp->next=temp->next;
            free(temp);
            return 1;
        }
        prvtemp=temp;
        temp=temp->next;

    }
    printf("Can't find ID: %d\n",ID);
    free(temp);
    return 0;
}
int searchGame(GameNode *head, int ID){
    GameNode *temp=head;
    while (temp != NULL){
    if (temp->data.game_Id == ID ){
        printf("GameID: %d, Name: %s, Price: %f\n",temp->data.game_Id,temp->data.gameName,temp->data.price);
        return 1;
        }
    temp=temp->next;
    }
    printf("Can't find ID: %d\n",ID);
    return 0;
}

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

void freeGameList(GameNode **head){
    GameNode *temp;
    while (*head != NULL){
        temp=*head;
        *head=temp->next;
        free(temp);
    }
}
