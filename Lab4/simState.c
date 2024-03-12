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
        default:
            break;
        }
    }

    exit(0);
}

void moveState(char input)
{
    for (int i = 0; i < numOfStates; ++i)
    {
        if (currentState == states[i])
        {
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

    for (int i = 0; i < numOfStates; ++i)
    {
        if (currentState == states[i])
        {
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
    for (int i = 0; i < numOfStates; ++i)
    {
        if (!deletedStates[i])
        {
            printf("%c %c %c\n", states[i], nextStates0[i], nextStates1[i]);
        }
    }
}

void garbageIdentify()
{
    int reachable[MAX_STATES] = {0};

    isReachable(currentState, reachable);

    int countUnreachable = 0;
    char unreachableStates[numOfStates];

    for (int i = 0; i < numOfStates; i++)
    {
        if (reachable[i] == 0)
        {
            unreachableStates[countUnreachable++] = states[i];
        }
    }

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
    for (int i = 0; i < numOfStates; i++)
    {
        if (state == states[i] && reachable[i] == 0)
        {
            reachable[i] = 1;
            isReachable(nextStates0[i], reachable);
            isReachable(nextStates1[i], reachable);
        }
    }
}

void deleteState(char input[])
{
    if (input[1])
    {
        char stateToDelete = input[1];
        for (int i = 0; i < numOfStates; i++)
        {
            if (states[i] == stateToDelete && !deletedStates[i])
            {
                deletedStates[i] = 1;
                printf("Deleted.\n");
                return;
            }
        }
        printf("Not deleted.\n");
    }
    else
    {
        int reachable[MAX_STATES] = {0};

        isReachable(currentState, reachable);

        int deletedNow = 0;
        for (int i = 0; i < numOfStates; i++)
        {
            if (!reachable[i] && !deletedStates[i])
            {
                deletedStates[i] = 1;
                if (deletedNow++ == 0)
                {
                    printf("Deleted: %c", states[i]);
                }
                else
                {
                    printf(", %c", states[i]);
                }
            }
        }

        if (deletedNow == 0)
        {
            printf("No states deleted.\n");
        }
        else
        {
            printf("\n");
        }
    }
}
