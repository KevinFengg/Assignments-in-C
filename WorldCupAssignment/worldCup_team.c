#include "worldCup_team.h"

typedef struct tNode
{
    int teamCode;
    char teamName[MAX_NAME_LEN];
    char teamSeeding[MAX_SEEDING_LEN];
    char colour;

    struct tNode *next;
    struct tNode *first;
} tNode;

void insertTeam(tNode **rootNode)
{
    tNode *newNode = malloc(sizeof(tNode));
    tNode *current = *rootNode;
    int teamCode;
    char teamName[MAX_NAME_LEN], teamSeeding[MAX_SEEDING_LEN], colour;

    newNode->next = NULL;

    // Getting input for team code, seeding, etc. Also checking for error cases and dealing with them accordingly
    printf("Enter team code: ");
    scanf(" %d", &teamCode);
    newNode->teamCode = teamCode;
    if (teamCode < 0) {
        printf("Error. Team code is less than 0. Returned to menu.\n");
        return;
    }
    while (current != NULL)
    {
        if (current->teamCode == teamCode)
        {
            printf("Error. Team with that team code already exists. Returned to menu.\n");
            return;
        }
        current = current->next;
    }

    // Setting current back to rootNode so that I can reuse it
    current = *rootNode;

    // Getting team name and dealing with error case(s)
    printf("Enter team name: ");
    scanf(" %s", teamName);
    for (int i = 0; i < sizeof(teamName); i++)
        newNode->teamName[i] = teamName[i];
    while (current != NULL)
    {
        if (strcmp(current->teamName, teamName) == 0)
        {
            printf("Error. Team with that name already exists. Returned to menu.\n");
            return;
        }
        current = current->next;
    }
    current = *rootNode;

    // Getting team seeding and dealing with error case(s)
    printf("Enter a team seeding: ");
    scanf(" %s", teamSeeding);
    for (int i = 0; i < sizeof(teamSeeding); i++)
        newNode->teamSeeding[i] = teamSeeding[i];
    if (teamSeeding[0] < 'A' || teamSeeding[0] > 'H' || 49 > teamSeeding[1] || 52 < teamSeeding[1])
    {
        printf("Error. Team seeding isn't between letters A-H and/or between numbers 1-4. Returned to menu.\n");
        return;
    }
    while (current != NULL)
    {
        if (strcmp(current->teamSeeding, teamSeeding) == 0)
        {
            printf("Error. Team with that seeding already exists. Returned to menu.\n");
            return;
        }
        current = current->next;
    }
    current = *rootNode;

    // Getting team colour and dealing with error case(s)
    printf("Enter a team colour: ");
    scanf(" %c", &colour);
    newNode->colour = colour;
    if (colour != 'R' && colour != 'O' && colour != 'Y' && colour != 'G' && colour != 'B' && colour != 'I' && colour != 'V')
    {
        printf("\nError. Colour is invalid. Returned to menu.\n");
        return;
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

void searchTeam(tNode **rootNode)
{
    tNode *current = *rootNode;
    int teamCode;

    printf("Enter the team code: ");
    scanf(" %d", &teamCode);

    // Checking the nodes in the linked list
    while (current != NULL)
    {
        if (current->teamCode == teamCode)
        {
            printf("%-30s %-30s %-30s %-30s", "Team code", "Team name", "Group seeding", "Primary kit colour");
            printf("%-30d %-30s %-30s %-30c\n", current->teamCode, current->teamName, current->teamSeeding, current->colour);
            return;
        }
        current = current->next;
    }
    // If all the nodes do not match the team code, then it doesn't exist in the linked list
    printf("Error. Team with inputted team code not found. Returning to menu.\n");
    return;
}

void updateTeam(tNode **rootNode)
{
    tNode *current = *rootNode;
    tNode *current2 = *rootNode;
    int teamCode;
    char teamName[MAX_NAME_LEN], teamSeeding[MAX_SEEDING_LEN], colour;

    printf("Enter the team code: ");
    scanf(" %d", &teamCode);

    // Iterating through linked list to find node. If node is found, get user input to update values of found node.
    // If an error case goes through, the team will not update and the user will be sent back to the main menu.
    while (current != NULL)
    {

        // Updating the team name, seeding and colour.
        if (current->teamCode == teamCode)
        {
            printf("Enter a new team name: ");
            scanf(" %s", teamName);

            while (current2 != NULL)
            {
                if (strcmp(current2->teamName, teamName) == 0)
                {
                    printf("Error. Team with that name already exists. Returned to menu.\n");
                    return;
                }
                current2 = current2->next;
            }
            current2 = *rootNode;

            printf("Enter a new team seeding: ");
            scanf(" %s", teamSeeding);
            if (teamSeeding[0] < 'A' || teamSeeding[0] > 'H' || 49 > teamSeeding[1] || 52 < teamSeeding[1])
            {
                printf("Error. Team seeding isn't between letters A-H and/or between numbers 1-4. Returned to menu.\n");
                return;
            }
            while (current2 != NULL)
            {
                if (strcmp(current2->teamSeeding, teamSeeding) == 0)
                {
                    printf("Error. Team with that seeding already exists. Returned to menu.\n");
                    return;
                }
                current2 = current2->next;
            }
            current2 = *rootNode;

            printf("Enter a new team colour: ");
            scanf(" %c", &colour);
            if (colour != 'R' && colour != 'O' && colour != 'Y' && colour != 'G' && colour != 'B' && colour != 'I' && colour != 'V')
            {
                printf("\nError. Colour is invalid. Returned to menu.\n");
                return;
            }

            //Updating the node in the linked list
            current->teamCode = teamCode;
            for (int i = 0; i < sizeof(teamName); i++)
                current->teamName[i] = teamName[i];
            for (int i = 0; i < sizeof(teamSeeding); i++)
                current->teamSeeding[i] = teamSeeding[i];
            current->colour = colour;
            return;
        }
        current = current->next;
    }
    printf("Error. Team not found. Returning to menu.");
    return;
}

void printTeams(tNode **rootNode)
{
    tNode *current = *rootNode;

    // Printing out the teams contents in the linked list
    printf("%-30s %-30s %-30s %-30s", "Team code", "Team name", "Group seeding", "Primary kit colour");
    while (current != NULL)
    {
        printf("\b%-30d %-30s %-30s %-30c", current->teamCode, current->teamName, current->teamSeeding, current->colour);
        current = current->next;
    }
}

void deleteTeam(tNode **rootNode)
{
    int teamCode;
    tNode *current = *rootNode, *prevNode;

    printf("Enter the team code: ");
    scanf(" %d", &teamCode);

    // If there's only one node in the linked list and it's the specified node to be removed.
    if (current->teamCode == teamCode && current->next == NULL)
    {
        *rootNode = NULL;
        free(current);
        printf("Team removed.\n");
        return;
    }

    // If there's more than one node in the linked list but the root node is the specified node.
    else if (current->teamCode == teamCode)
    {
        *rootNode = current->next;
        free(current);
        printf("Team removed.\n");
        return;
    }

    // Looking for the specified node while keeping track of the node before the current node
    while (current != NULL && current->teamCode != teamCode)
    {
        prevNode = current;
        current = current->next;
    }

    // If the while loop above ends before the specified node is found, it DNE in the linked list.
    if (current == NULL)
    {
        printf("Error. Team not found. Returned to menu.\n");
        return;
    }

    // Else if the specified node is found, free it and set its previous node to the specified node's next node.
    else
    {
        prevNode->next = current->next;
        current->next = NULL;
        free(current);
        printf("Team removed.\n");
        return;
    }
}

/*
int main(void)
{
    node *rootNode = NULL;
    printf("OK\n");

    insertNode(&rootNode);
    // insertNode(&rootNode);
    insertNode(&rootNode);
    insertNode(&rootNode);

    // searchNode(&rootNode);
    // searchNode(&rootNode);
    // searchNode(&rootNode);
    printTeams(&rootNode);
    deleteTeam(&rootNode);
    deleteTeam(&rootNode);
    printTeam(&rootNode);
}
*/