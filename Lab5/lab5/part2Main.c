#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();
extern void addHeap(int value);
extern int heapDelete();
extern void printHeap(int index);
extern int heapSize();

int main(int argc, char *argv[])
{
  int value;
  while (scanf("%d\n", &value) != EOF)
  {
    fprintf(stderr, "READING INPUT: %d\n", value);
    //
    addHeap(value); // add value to heap
  }

  // print the heap
  printHeap(0);
  printf("\n");

  // delete the heap and add to stack
  while (heapSize() > 0)
  {
    int max = heapDelete(); // get the max element
    printf("%d\n", max);
    push(max);
  }

  // pop the stack
  while (!isEmpty())
  {
    printf("%d\n", pop());
  }

  exit(0);
}
