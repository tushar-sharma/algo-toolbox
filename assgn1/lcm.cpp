#include <iostream>
#include "assert.h"
using std::cout;
using std::cin;

/*
 *Using Euclid Algorithm
 * gcd(a,b) = gcd(a', b) = gcd (b, a')
*/
long long gcd_euclid(long long num1, long long num2)
{
    if(num2 == 0)
        return num1;
    long long rem = num1 % num2;
    return gcd_euclid(num2, rem);
}

/*Least Common Multiple
*/
long long lcm(long long num1, long long num2)
{
    return ((num1 * num2) / gcd_euclid(num1, num2));
}

void test_function() {
    assert( lcm(6,8) == 24);
    assert( lcm(28851538, 1183019)  == 1933053046 );
}

int main(int argc, char **argv){
    test_function();
    cout<<"Success\n";
}
