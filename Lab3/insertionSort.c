#include "mySort.h"
#include "metrics.h"

void mySort(int array[], unsigned int first, unsigned int last)
{
	int i, j, key;

	// iterate through the array starting from the second element
	for (i = 1; i <= last; i++)
	{
		// copy the value of the current element to the key
		myCopy(&array[i], &key);
		j = i - 1;

		// move the current element until it is in the correct position
		while (j >= 0 && myCompare(array[j], key) > 0)
		{
			// shift the element to the right
			mySwap(&array[j], &array[j + 1]);
			j--;
		}
	}
}
