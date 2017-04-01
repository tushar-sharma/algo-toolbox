#include <iostream>
#include "assert.h"
using std::cout;
using std::cin;

long long gcd_naive(long long num1, long long num2)
{
    long long best = 0;
    for (long long i = 1; i < (num1 + num2); ++i) {
        if ((num1 % i == 0) && (num2 % i == 0)) {
            best = i;
        }
    }
    return best;
}

/* Using Euclid ALgorithm
 * gcd(a, b) = gcd(a', b) = gcd(b, a')
 */
long long gcd_euclid(long long num1, long long num2)
{
    if(num2 == 0)
        return num1;
    long long rem = num1 % num2;
    return gcd_euclid(num2, rem);
}

int main(int argc, char **argv) {

    assert( gcd_naive(4, 10) == 2);
    assert( gcd_naive(72, 100) == 4);
    assert( gcd_naive(1024, 7824) == 16);
    assert( gcd_naive(2, 1) == 1);
    assert( gcd_naive(1, 1) == 1);
    assert( gcd_naive(3918848, 1653264) == 61232);

    assert( gcd_euclid(4, 10) == 2);
    assert( gcd_euclid(72, 100) == 4);
    assert( gcd_euclid(1024, 7824) == 16);
    assert( gcd_euclid(1, 1) == 1);
    assert( gcd_euclid(1, 1) == 1);
    assert( gcd_euclid(3918848, 1653264) == 61232);

    cout<<"Success\n";
}
