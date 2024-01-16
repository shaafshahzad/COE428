#include <stdio.h>

void merge(int data[], int left[], int right[], int leftSize, int rightSize)
{
    int i = 0, j = 0, k = 0;

    // merge left and right arrays into data
    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            data[k++] = left[i++];
        }
        else
        {
            data[k++] = right[j++];
        }
    }

    // merge any remaining elements into data
    while (i < leftSize)
    {
        data[k++] = left[i++];
    }

    while (j < rightSize)
    {
        data[k++] = right[j++];
    }
}

void mySort(int data[], unsigned int nDataItems)
{

    // if array is empty or has one element, it is already sorted
    if (nDataItems <= 1)
        return;

    // set up left and right arrays
    int mid = nDataItems / 2;
    int left[mid];
    int right[nDataItems - mid];

    // copy data into left and right arrays
    for (int i = 0; i < mid; i++)
        left[i] = data[i];

    for (int i = mid; i < nDataItems; i++)
        right[i - mid] = data[i];

    // sort left and right arrays
    mySort(left, mid);
    mySort(right, nDataItems - mid);

    // merge left and right arrays
    merge(data, left, right, mid, nDataItems - mid);
}
