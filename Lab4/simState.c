#include <stdlib.h>
#include <stdio.h>
#define MAX_STATES 8

void isReachable(char state, char states[], char nextStates0[], char nextStates1[], int reachable[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (state == states[i] && reachable[i] == 0)
        {
            reachable[i] = 1;
            isReachable(nextStates0[i], states, nextStates0, nextStates1, reachable, size);
            isReachable(nextStates1[i], states, nextStates0, nextStates1, reachable, size);
        }
    }
}

int main(int argc, char *argv[])
{
    char currentState = 'C';
    printf("%c\n", currentState);

    char states[] = {'A', 'B', 'C', 'D'};
    char nextStates0[] = {'B', 'A', 'A', 'D'};
    char nextStates1[] = {'C', 'A', 'D', 'C'};
    int numStates = sizeof(states) / sizeof(states[0]);
    int deleted[MAX_STATES] = {0};

    char input[4];
    while (scanf(" %s", input) == 1)
    {
        if (input[0] == '0' || input[0] == '1')
        {
            for (int i = 0; i < numStates; ++i)
            {
                if (currentState == states[i])
                {
                    currentState = (input[0] == '0') ? nextStates0[i] : nextStates1[i];
                    printf("%c\n", currentState);
                    break;
                }
            }
        }
        else if (input[0] == 'c')
        {
            char newInput = input[1];
            char newState = input[2];

            for (int i = 0; i < numStates; ++i)
            {
                if (currentState == states[i])
                {
                    if (newInput == '0')
                    {
                        nextStates0[i] = newState;
                    }
                    else if (newInput == '1')
                    {
                        nextStates1[i] = newState;
                    }
                    break;
                }
            }
        }
        else if (input[0] == 'p')
        {
            for (int i = 0; i < numStates; ++i)
            {
                if (!deleted[i])
                {
                    printf("%c %c %c\n", states[i], nextStates0[i], nextStates1[i]);
                }
            }
        }
        else if (input[0] == 'g')
        {
            int reachable[MAX_STATES] = {0};

            isReachable(currentState, states, nextStates0, nextStates1, reachable, numStates);

            int countUnreachable = 0;
            char unreachableStates[numStates];

            for (int i = 0; i < numStates; i++)
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
        else if (input[0] == 'd')
        {
            if (input[1])
            {
                char stateToDelete = input[1];
                int isDeleted = 0;
                for (int i = 0; i < numStates; i++)
                {
                    if (states[i] == stateToDelete && !deleted[i])
                    {
                        deleted[i] = 1;
                        printf("Deleted: %c\n", stateToDelete);
                        isDeleted = 1;
                        break;
                    }
                }
                if (!isDeleted)
                {
                    printf("Not deleted\n");
                }
            }
            else
            {
                int reachable[MAX_STATES] = {0};
                isReachable(currentState, states, nextStates0, nextStates1, reachable, numStates);

                int countDeleted = 0;
                for (int i = 0; i < numStates; i++)
                {
                    if (!reachable[i] && !deleted[i])
                    {
                        deleted[i] = 1;
                        countDeleted++;
                    }
                }

                if (countDeleted == 0)
                {
                    printf("No states deleted\n");
                }
                else
                {
                    printf("Deleted:");
                    for (int i = 0; i < numStates; i++)
                    {
                        if (deleted[i])
                        {
                            printf(" %c", states[i]);
                        }
                    }
                    printf("\n");
                }
            }
        }
    }

    exit(0);
}