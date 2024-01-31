#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc == 2)
    {
        // number of disks
        n = atoi(argv[1]);
    }
    else if (argc == 4)
    {
        // number of disks, to, and from
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        dest = atoi(argv[3]);

        if (from == dest)
        {
            // from and dest cannot be the same, print error and exit
            fprintf(stderr, "Error: from and dest cannot be the same");
            exit(0);
        }
    }

    // call the towers function with the given arguments
    towers(n, from, dest);
    exit(0);
}