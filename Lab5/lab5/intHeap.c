/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int heap[100];
static int size = 0;

void printHeap(int index)
{
  if (index >= size) // if value is greater than or equal to size, return
  {
    return;
  }

  int left = 2 * index + 1;  // left child
  int right = 2 * index + 2; // right child

  printf("<node id=\"%d\">", heap[index]);

  if (left < size) // if left is less than size, print left
  {
    printHeap(left);
  }

  if (right < size) // if right is less than size, print right
  {
    printHeap(right);
  }

  printf("</node>");
}

void swap(int *a, int *b)
{
  int temp = *a; // swap a and b
  *a = *b;
  *b = temp;
}

void heapify(int value)
{
  int max = value;
  int left = 2 * value + 1;
  int right = 2 * value + 2;

  if (left < size && heap[left] > heap[max]) // if left is less than size and left is greater than max
  {
    max = left; // max is left
  }

  if (right < size && heap[right] > heap[max]) // if right is less than size and right is greater than max
  {
    max = right; // max is right
  }

  if (max != value) // if max is not equal to value
  {
    int temp = heap[value]; // swap value and max
    heap[value] = heap[max];
    heap[max] = temp;
    heapify(max); // heapify max
  }
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
  if (size == 0)
  {
    fprintf(stderr, "error, cannot delete from heap because it is empty\n");
    return -1;
  }

  int rootValue = heap[0]; // root value is heap[0]
  heap[0] = heap[--size];  // heap[0] is heap[size - 1]
  heapify(0);              // heapify 0
  return rootValue;
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  if (size >= 100)
  {
    fprintf(stderr, "error, cannot add to heap because it is full\n");
    return;
  }

  int i = size;
  heap[size++] = thing2add; // add thing2add to heap and increment size

  while (i != 0 && heap[(i - 1) / 2] < heap[i])
  {
    swap(&heap[i], &heap[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;
}