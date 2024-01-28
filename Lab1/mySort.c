void mySort(int d[], unsigned int n)
{

  // if array is empty or has one element, it is already sorted
  if (n <= 1)
  {
    return;
  }

  // set up the left and right side arrays
  int mid = n / 2;
  int leftSize = mid;
  int rightSize = n - mid;
  int left[leftSize];
  int right[rightSize];

  // copy data into these new arrays
  for (int i = 0; i < mid; i++)
  {
    left[i] = d[i];
  }
  for (int i = 0; i < n; i++)
  {
    right[i - mid] = d[i];
  }

  // merge sort both halves
  mySort(left, leftSize);
  mySort(right, rightSize);

  // merge both halves back into one
  int i = 0, j = 0, k = 0;

  while (i < leftSize && j < rightSize)
  {
    if (left[i] <= right[j])
    {
      d[k++] = left[i++];
    }
    else
    {
      d[k++] = right[j++];
    }
  }

  // merge any leftover array elements into data
  while (i < leftSize)
  {
    d[k++] = left[i++];
  }
  while (j < rightSize)
  {
    d[k++] = right[j++];
  }
}
