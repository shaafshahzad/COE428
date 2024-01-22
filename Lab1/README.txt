Shaaf Shahzad, #501172227
Submission date: 01/22/2024

SUMMARY:
For this lab, I implemented the merge sort algorithm in mySort and implemented command line argument handling in sortMain2.
mySort contains the implementation of the merge sort algorithm.
sortMain2 contains the code from sortMain but with argument-dependent if statements to dictate whether to use default values or argument values
Both of the requirements for this lab were met and everything compiles with no issues.

QUESTION 1:
To utilize the betterSort() function within the mySort() function, we would have to pass the array d[] alongside the starting and ending entries.
We can pass them through like so:

mySort(int d[], unsigned int n) {
    betterSort(d, 0, n - 1);
}

0 represents the start of the array while n-1 is the entry corresponding to the last entry in the array, which is the length of the array minus one.
This implementation ensures that the entire array from the start to the end is sorted by the betterSort() function.