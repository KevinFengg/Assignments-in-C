#include "worldCupDB.h"

void help() {
    printf("To quit the program, enter \"q\"\n");
    printf("To control teams (Insert, delete, update, search, or print teams), enter \"t\"\n");
    printf("To control players (Insert, delete, update, search, or print teams), enter \"p\"\n");
    printf("Returning to menu.\n\n");
}

int main(void) {
    char command;
    char operationCode;

    //Creating an empty linked list with a null root node
    tNode* rootTNode = NULL;
    pNode * rootPNode = NULL;

    while(1) {
        printf("\nEnter a command: ");
        scanf(" %c", &command);

        if (command == 'h') {
            help();
        }
        else if (command == 'q') {
            printf("Program exitted.");
            break;
        }
        else if (command == 't') {
            printf("Enter an operation code: ");
            scanf(" %c", &operationCode);

            if (operationCode == 'i') {
                insertTeam(&rootTNode);
                continue;
            }
            else if (operationCode == 's') {
                searchTeam(&rootTNode);
                continue;
            }
            else if (operationCode == 'u') {
                updateTeam(&rootTNode);
                continue;
            }
            else if (operationCode == 'p') {
                printTeams(&rootTNode);
                continue;
            }
            else if (operationCode == 'd') {
                deleteTeam(&rootTNode);
                continue;
            }
            else {
                printf("Error. Operation code inputted does not exist. Returning to menu.\n");
            }
        }
        else if (command == 'p') {
            printf("Enter an operation code: ");
            scanf(" %c", &operationCode);

            if (operationCode == 'i') {
                insertPlayer(&rootPNode);
                continue;
            }
            else if (operationCode == 's') {
                searchPlayer(&rootPNode);
                continue;
            }
            else if (operationCode == 'u') {
                updatePlayer(&rootPNode);
                continue;
            }
            else if (operationCode == 'p') {
                printPlayers(&rootPNode);
                continue;
            }
            else if (operationCode == 'd') {
                deletePlayer(&rootPNode);
                continue;
            }
            else {
                printf("Error. Operation code inputted does not exist. Returning to menu.\n");
            }
        }
        else printf("Invalid command inputted. Please try again.\n\n");
    }
}