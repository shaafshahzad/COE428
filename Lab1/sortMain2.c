#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

int main(int argc, char *argv[])
{

      int data[100000]; /* Array of ints to sort */
      int nDataItems;   /* number of actual items in the array */
      int i;

      // if the only argument is the call to run the program, then just use default test values
      if (argc == 1)
      {
            /* Test data */
            nDataItems = 4;
            data[0] = 10;
            data[1] = 20;
            data[2] = 30;
            data[3] = 40;

            mySort(data, nDataItems);

            for (i = 0; i < nDataItems; i++)
            {
                  printf("%d\n", data[i]);
            }
      }
      // if there is more than one argument, then use the arguments as values
      else if (argc > 1)
      {
            // set the number of data items to the number of arguments minus the call to run the program
            nDataItems = argc - 1;

            // convert the arguments to integers and store them in the data array
            for (i = 1; i < argc; i++)
            {
                  data[i - 1] = atoi(argv[i]);
            }

            mySort(data, nDataItems);

            for (i = 0; i < nDataItems; i++)
            {
                  printf("%d\n", data[i]);
            }
      }

      exit(0);
}
