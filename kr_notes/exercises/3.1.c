/*
    Exercise 3-1: Our binary search makes two tests inside the loop, when one 
        would suffice (at the price of more tests outside.) Write a version 
        with only one test inside the loop and measure the difference in 
        run-time.

    We can measure the time taken via the functions in time.h. To get a good
        estimate, we run the algorithm many times and take the average run-
        time.

    Note that for smaller n and n_iter, our modification is faster. However,
        if these are made large, the original algorithm becomes faster. This
        must have something to do with the extra comparison we make (the 
        termination condition).
*/

#include <stdio.h>
#include <time.h> // for timing

/* binsearch: find x in v (sorted, increasing) of length n */
int binsearch(int x, int v[], int n)
{
    
    int low, high, mid; // indices
    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low + high)/2; // int division: always rounds down
        // printf("mid: %d\n", mid);
        if (x < v[mid])
            high = mid - 1;
        else if (v[mid] < x)
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

/* binsearch2: find x in v, but use only one test inside the loop. We need
    to make extra tests outside the loop. This can just be for equality. 
    
    A common "solution" to this problem involves just moving the comparisons
    into the condition of the while-loop via &&. This isn't real saving anything
    because the tests still run. In this version, we do only one test in the 
    while condition, one within the loop, and then a single check after the 
    loop.

    Note: taking the average shrinks everything to zero because the times are so
    small.
    */
int binsearch2(int x, int v[], int n)
{
    // printf("inside binsearch2");
    int low, mid, high;
    low = 0;
    high = n - 1;

    // printf("starting loop");
    while( low < high )
    {
        mid = (low + high)/2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (v[low] == x) ? low : -1;
}


int main()
{
    int x = -1; // element to find (unfindable for worst-case)
    int n = 10000; 
    int n_iter = 1000000; // number of runs for timing
    int test_data[n];
    clock_t time_taken;

    for (int i = 0; i < n; i++)
        test_data[i] = i;

    
    int results;
    
    for (int i = 0, time_taken = clock(); i < n_iter; ++i)
        results = binsearch(x, test_data, n);
    time_taken = clock() - time_taken;
    // time_taken = time_taken / n_iter;
    printf("%d clocks per second\n", CLOCKS_PER_SEC);
    printf("K&R binsearch took %6lu clock cycles/%6f seconds.\n",
        (unsigned long)time_taken,
        time_taken / (float)CLOCKS_PER_SEC);

    for (int i = 0, time_taken = clock(); i < n_iter; ++i)
        results = binsearch2(x, test_data, n);
    time_taken = clock() - time_taken;
    // time_taken /= n_iter;
    printf(" My binsearch took %6lu clock cycles/%6f seconds.\n",
        (unsigned long)time_taken,
        time_taken / (float)CLOCKS_PER_SEC);

    return 0;
}