#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
    // if array is empty or has one element, it is already sorted
    if (first >= last)
    {
        return;
    }

    // find the middle of the array
    unsigned int middle = (first + last) / 2;

    // recursively divide and sort the left and right arrays
    mySort(array, first, middle);
    mySort(array, middle + 1, last);

    unsigned int leftSize = middle - first + 1;
    unsigned int rightSize = last - middle;
    int left[leftSize], right[rightSize];

    // copy the left and right halves of the array into temporary arrays
    for (unsigned int i = 0; i < leftSize; i++)
    {
        myCopy(&array[first + i], &left[i]);
    }

    for (unsigned int j = 0; j < rightSize; j++)
    {
        myCopy(&array[middle + 1 + j], &right[j]);
    }

    unsigned int i = 0, j = 0;
    unsigned int k = first;

    // merge the left and right halves of the array
    while (i < leftSize && j < rightSize)
    {
        if (myCompare(left[i], right[j]) <= 0)
        {
            myCopy(&left[i], &array[k]);
            i++;
        }
        else
        {
            myCopy(&right[j], &array[k]);
            j++;
        }
        k++;
    }

    // copy the remaining elements of the left and right halves of the array
    while (i < leftSize)
    {
        myCopy(&left[i], &array[k]);
        i++;
        k++;
    }

    while (j < rightSize)
    {
        myCopy(&right[j], &array[k]);
        j++;
        k++;
    }
}
