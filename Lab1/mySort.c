#include <stdio.h>

void merge(int data[], int left[], int right[], int leftSize, int rightSize)
{
    int i = 0, j = 0, k = 0;

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
    if (nDataItems <= 1)
    {
        return; // Array is already sorted
    }

    int mid = nDataItems / 2;
    int left[mid];
    int right[nDataItems - mid];

    for (int i = 0; i < mid; i++)
        left[i] = data[i];

    for (int i = mid; i < nDataItems; i++)
        right[i - mid] = data[i];

    mySort(left, mid);
    mySort(right, nDataItems - mid);

    merge(data, left, right, mid, nDataItems - mid);
}
