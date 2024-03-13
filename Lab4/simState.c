#include <stdlib.h>
#include <stdio.h>
#define MAX_STATES 8

void moveState(char input);
void updateState(char input[]);
void printStateMachine();
void garbageIdentify();
void isReachable(char state, int reachable[]);
void deleteState(char input[]);

char currentState;
char states[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
char nextStates0[] = {'C', 'H', 'G', 'B', 'D', 'F', 'F', 'A'};
char nextStates1[] = {'D', 'A', 'H', 'G', 'B', 'E', 'C', 'F'};
int deletedStates[MAX_STATES] = {0};
int numOfStates;

int main(int argc, char *argv[])
{
    currentState = 'D';
    numOfStates = sizeof(states) / sizeof(states[0]);

    printf("%c\n", currentState);

    char input[4];

    // reading user input to see which command to run
    while (scanf(" %s", input) == 1)
    {
        switch (input[0])
        {
        case '0':
        case '1':
            moveState(input[0]);
            break;
        case 'c':
            updateState(input);
            break;
        case 'p':
            printStateMachine();
            break;
        case 'g':
            garbageIdentify();
            break;
        case 'd':
            deleteState(input);
            break;
        case 'e':
            exit(0);
        default:
            break;
        }
    }
}

void moveState(char input)
{
    // loop through the states and find the current state
    for (int i = 0; i < numOfStates; ++i)
    {
        if (currentState == states[i])
        {
            // depending on input, move to the appropriate next state
            currentState = (input == '0') ? nextStates0[i] : nextStates1[i];
            printf("%c\n", currentState);
            break;
        }
    }
}

void updateState(char input[])
{
    char targetInput = input[1];
    char newState = input[2];

    // loop through the states and find the current state
    for (int i = 0; i < numOfStates; ++i)
    {
        if (currentState == states[i])
        {
            // depending on input, update the appropriate next state
            if (targetInput == '0')
            {
                nextStates0[i] = newState;
            }
            else if (targetInput == '1')
            {
                nextStates1[i] = newState;
            }
            break;
        }
    }
}

void printStateMachine()
{
    // loop through the states and print the state machine
    for (int i = 0; i < numOfStates; ++i)
    {
        if (!deletedStates[i])
        {
            // if the state is not deleted, print the state and its next states
            printf("%c %c %c\n", states[i], nextStates0[i], nextStates1[i]);
        }
    }
}

void garbageIdentify()
{
    int reachable[MAX_STATES] = {0};

    // call to function to find the reachable states
    isReachable(currentState, reachable);

    int countUnreachable = 0;
    char unreachableStates[numOfStates];

    // loop through the states and find the unreachable states
    for (int i = 0; i < numOfStates; i++)
    {
        // if the state is not reachable, add it to the unreachable states array
        if (reachable[i] == 0)
        {
            unreachableStates[countUnreachable++] = states[i];
        }
    }

    // if there are no unreachable states, otherwise print the unreachable states
    if (countUnreachable == 0)
    {
        printf("No garbage\n");
    }
    else
    {
        printf("Garbage:");
        for (int i = 0; i < countUnreachable; i++)
        {
            printf(" %c", unreachableStates[i]);
        }
        printf("\n");
    }
}

void isReachable(char state, int reachable[])
{
    // loop through the states and find the current state
    for (int i = 0; i < numOfStates; i++)
    {
        // if the state matches and is not already marked as 'reachable'
        if (state == states[i] && reachable[i] == 0)
        {
            reachable[i] = 1;                       // mark the state as 'reachable'
            isReachable(nextStates0[i], reachable); // call the function for the next states (input 0)
            isReachable(nextStates1[i], reachable); // call the function for the next states (input 1)
        }
    }
}

void deleteState(char input[])
{
    if (input[1]) // if there is a given state to delete
    {
        char stateToDelete = input[1];
        for (int i = 0; i < numOfStates; i++) // loop through the states
        {
            if (states[i] == stateToDelete && !deletedStates[i]) // if the state matches and is not already deleted
            {
                deletedStates[i] = 1; // mark the state as deleted
                printf("Deleted.\n");
                return;
            }
        }
        printf("Not deleted.\n");
    }
    else // if there is no given state to delete
    {
        int reachable[MAX_STATES] = {0};

        isReachable(currentState, reachable); // call to function to find the reachable states

        int deletedNow = 0;
        for (int i = 0; i < numOfStates; i++) // loop through the states
        {
            if (!reachable[i] && !deletedStates[i]) // if the state is not reachable and is not already deleted
            {
                deletedStates[i] = 1;  // mark the state as deleted
                if (deletedNow++ == 0) // if its the first state being deleted
                {
                    printf("Deleted: %c", states[i]);
                }
                else // if its not the first state being deleted
                {
                    printf(", %c", states[i]);
                }
            }
        }

        if (deletedNow == 0) // if no states were deleted
        {
            printf("No states deleted.\n");
        }
        else
        {
            printf("\n");
        }
    }
}
