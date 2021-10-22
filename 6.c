/*
Work 06: The Old Switcheroo

Oct 1, 2021
Due: Monday 10/04 10:00am
GitHub Submission Link: git@github.com:mks65/06_switcheroo.git
Do the following in a C program.

    Create an array large enough to store 10 ints.
    Set the first value in the array to 0.
    Populate the rest of the array with random values.
        See below for notes on random numbers
    Print out the values in this array
    Create a separate array large enough to store 10 ints.
    Create pointer variables that will point to each array.
    USING ONLY POINTER VARIABLES (that is, do not use the array variables) do the following:
        Populate the second array with the values in the first but in reverse order
        Print out the values in the second array
        Try this using both [] and *.

For this assignment, do not create helper functions, put everything inside main (it won’t be too long). We will talk about passing arrays and pointers are function arguments next week.
Random Numbers

    Note: On some systems, you may be able to use other functions than the ones described below, but they are not standard for linux, so you should stay away from them for now.
    Generating a random number in C requires 2 steps
        Seeding the random number generator
        srand( time(NULL) );
            srand(<SEED>) seeds the random number generator with the provided argument.
            If you use the same argument to srand() multiple times, you will get the exact same sequence of random numbers.
            time(NULL) will return the current EPOCH time, it is commonly used with srand() to get new random sequences.
                Getting a random number
        int x = rand();
        Returns the next random number in the sequence seeded by srand().
        Returns an int.
    srand() and rand() are both in <stdlib.h>
    time() is in <time.h>
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(NULL));
	int my_array[11];
	my_array[0] = 0;
	for (int i = 1; i < 11; i++) {
		my_array[i] = rand();
	}
	for (int j = 0; j < 11; j++) {
		printf("my_array[%d] = %d\n",j,my_array[j]);
	}
	int my_brray[11];
	long my_arrpy = *my_array;
	long my_brrpy = *my_brray;
	for (int k = 0; k < 11; k++) {
		// (my_brrpy + 9 - k) = (my_arrpy + k);
		my_brray[10 - k] = my_array[k];
	}
	printf("My array b: ");
	for (int l = 0; l < 10; l++)
		printf("%d, ",my_brray[l]);
	printf("%d\n",my_brray[10]);
	return 0;
}
