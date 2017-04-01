#include <iostream>
#include <vector>
#include "assert.h"
using std::vector;
using std::cin;
using std::cout;

/*
 * return the last number of fibonacci number
 */
long long fibo_naive(int number)
{
    if (number <= 1)
        return (long long)  number;
    else
        return (long long) fibo_naive(number - 1) + fibo_naive(number - 2);
}

/*
 * return the last number of fibonnaci number
 */
long long fibo(int number)
{
    if (number <= 1)
        return (long long) number;

    vector<long long> fibo_arr(number + 1, 0);

    fibo_arr[0] = 0;
    fibo_arr[1] = 1;

    int i;
    for (i = 2; i <= number; i++) {
        fibo_arr[i] = (long long) fibo_arr[i - 1] + (long long) fibo_arr[i - 2];
    }

    return (long long) fibo_arr[i - 1];
}

void tests() {

    assert( fibo_naive(0) == 0);
    assert( fibo_naive(2) == 1);
    assert( fibo_naive(5) == 5);
    assert( fibo_naive(7) == 13);
    assert( fibo_naive(21) == 10946);
    assert( fibo_naive(37) == 24157817);
    /*assert( fibo_naive(75) == 2111485077978050);*/ //Wont run in large numbers

    assert( fibo(0) == 0);
    assert( fibo(2) == 1);
    assert( fibo(5) == 5);
    assert( fibo(7) == 13);
    assert( fibo(21) == 10946);
    assert( fibo(37) == 24157817);
    assert( fibo(75) == 2111485077978050);
}

int main(int argc, char **argv) {

    tests();
    return 0;
}
