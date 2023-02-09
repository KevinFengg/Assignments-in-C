#include "worldCup_player.h"

typedef struct pNode
{
    int playerCode;
    char playerName[MAX_LEN];
    int playerAge;
    char clubAfffil[MAX_LEN];

    struct pNode *next;
    struct pNode *first;
} pNode; 

void insertPlayer(pNode **rootNode)
{
    pNode *newNode = malloc(sizeof(pNode));
    pNode *current = *rootNode;
    int playerCode, playerAge;
    char playerName[MAX_LEN], clubAffil[MAX_LEN];

    newNode->next = NULL;

    // Getting input for player code, name, etc. Also checking for error cases and dealing with them accordingly
    printf("Enter player code: ");
    scanf(" %d", &playerCode);
    newNode->playerCode = playerCode;
    if (playerCode < 0) {
        printf("Error. Player code is less than 0. Returned to menu.\n");
        return;
    }
    while (current != NULL)
    {
        if (current->playerCode == playerCode)
        {
            printf("Error. Player with that code already exists. Returned to menu.\n");
            return;
        }
        current = current->next;
    }

    // Setting current back to rootNode so that I can reuse it
    current = *rootNode;

    // Getting player name and dealing with error case(s)
    printf("Enter player name: ");
    scanf(" %s", playerName);
    for (int i = 0; i < sizeof(playerName); i++)
        newNode->playerName[i] = playerName[i];
    while (current != NULL)
    {
        if (strcmp(current->playerName, playerName) == 0)
        {
            printf("Error. Player with that name already exists. Returned to menu.\n");
            return;
        }
        current = current->next;
    }
    current = *rootNode;

    // Getting player age and dealing with error case(s)
    printf("Enter the age of the player: ");
    scanf(" %d", &playerAge);
    newNode->playerAge = playerAge;
    if (playerAge < 17 || playerAge > 99) {
        printf("Error. Player age needs to be between 17-99. Returned to menu.\n");
        return;
    }
    current = *rootNode;

    //Getting professional club affilation
    printf("Enter the player's professional club affiliation: ");
    scanf(" %s", clubAffil);
    for (int i = 0; i < sizeof(clubAffil); i ++) {
        newNode->clubAfffil[i] = clubAffil[i];
    }
    current = *rootNode;

    // Checking if the linked list parameter is empty and adding the new node as the root node if true
    if (*rootNode == NULL)
    {
        *rootNode = newNode;
        return;
    }

    // Iterating to the end of the linked list and adding the new node
    while (current->next != NULL) current = current->next;
    current->next = newNode;
}

void searchPlayer(pNode **rootNode)
{
    pNode *current = *rootNode;
    int playerCode;

    printf("Enter the player code: ");
    scanf(" %d", &playerCode);

    // Checking the nodes in the linked list
    while (current != NULL)
    {
        if (current->playerCode == playerCode)
        {
            printf("%-30s %-30s %-30s %-30s", "Player code", "Player name", "Player age", "Professional club affiliation");
            printf("\b%-30d %-30s %-30d %-30s\n", current->playerCode, current->playerName, current->playerAge, current->clubAfffil);
            return;
        }
        current = current->next;
    }
    // If all the nodes do not match the team code, then it doesn't exist in the linked list
    printf("Error. Team with inputted team code not found. Returning to menu.\n");
    return;
}

void updatePlayer(pNode **rootNode)
{
    pNode *current = *rootNode;
    pNode *current2 = *rootNode;
    int playerCode, playerAge;
    char playerName[MAX_LEN], clubAffil[MAX_LEN];

    printf("Enter the player code: ");
    scanf(" %d", &playerCode);

    // Iterating through linked list to find node. If node is found, get user input to update values of found node.
    // If an error case goes through, the player will not update and the user will be sent back to the main menu.
    while (current != NULL)
    {

        // Updating the player name, age, and club affiliation
        if (current->playerCode == playerCode)
        {
            printf("Enter a new player name: ");
            scanf(" %s", playerName);

            while (current2 != NULL)
            {
                if (strcmp(current2->playerName, playerName) == 0)
                {
                    printf("Error. Player with that name already exists. Returned to menu.\n");
                    return;
                }
                current2 = current2->next;
            }
            current2 = *rootNode;

            printf("Enter the new player's age: ");
            scanf(" %d", &playerAge);
            if (playerAge < 17 || playerAge > 99)
            {
                printf("Error. Player age is not between 17-99. Returned to menu.");
                return;
            }

            printf("Enter the player's professional club affiliation: ");
            scanf(" %s", &clubAffil);

            current->playerCode = playerCode;
            for (int i = 0; i < sizeof(playerName); i++)
                current->playerName[i] = playerName[i];
            current->playerAge = playerAge;
            for (int i = 0; i < sizeof(clubAffil); i++)
                current->clubAfffil[i] = clubAffil[i];
            return;
        }
        current = current->next;
    }
    printf("Error. Player not found. Returning to menu.");
    return;
}

void printPlayers(pNode **rootNode)
{
    pNode *current = *rootNode;

    // Printing out the player's contents in the linked list
    printf("%-30s %-30s %-30s %-30s", "Player code", "Player name", "Player age", "Professional club affiliation");
    while (current != NULL)
    {
        printf("\b%-30d %-30s %-30d %-30s", current->playerCode, current->playerName, current->playerAge, current->clubAfffil);
        current = current->next;
    }
}

void deletePlayer(pNode **rootNode)
{
    int playerCode;
    pNode *current = *rootNode, *prevNode;

    printf("Enter the player's code: ");
    scanf(" %d", &playerCode);

    // If there's only one node in the linked list and it's the specified node to be removed.
    if (current->playerCode == playerCode && current->next == NULL)
    {
        *rootNode = NULL;
        free(current);
        printf("Player removed.\n");
        return;
    }

    // If there's more than one node in the linked list but the root node is the specified node.
    else if (current->playerCode == playerCode)
    {
        *rootNode = current->next;
        free(current);
        printf("Player removed.\n");
        return;
    }

    // Looking for the specified node while keeping track of the node before the current node
    while (current != NULL && current->playerCode != playerCode)
    {
        prevNode = current;
        current = current->next;
    }

    // If the while loop above ends before the specified node is found, it DNE in the linked list.
    if (current == NULL)
    {
        printf("Error. Player not found. Returned to menu.\n");
        return;
    }

    // Else if the specified node is found, free it and set its previous node to the specified node's next node.
    else
    {
        prevNode->next = current->next;
        current->next = NULL;
        free(current);
        printf("Player removed.\n");
        return;
    }
}