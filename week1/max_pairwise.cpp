#include <iostream>
#include <vector>
#include "assert.h"
using std::vector;
using std::cin;
using std::cout;

/*
 * Return the maximum product of two numbers in a sequence
 * Input : Integer vector array
 * Output: Number of type long long
 */
long long  MaxPairWiseProduct_naive(const vector<int>& numbers) {
    long long max_product = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        for (int j = i +1 ; j < numbers.size(); ++j) {
            if ((long long)numbers[i] * numbers[j]  > max_product) {
                max_product = (long long) numbers[i] * numbers[j];
            }
        }
    }
    return max_product;
}

/*
 * Return the maximum product of two numbers in a sequence
 * Input : Integer vector array
 * Output: Number of type long long
 */
long long MaxPairWiseProductFast(const vector<int>& numbers) {

    int max_index1 = -1;
    for(int i = 0; i < numbers.size(); ++i) {
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1])) {
            max_index1 = i;
        }
    }

    int max_index2 = -1;
    for (int j = 0; j < numbers.size(); j++) {
        if (((j != max_index1) && (max_index2 == -1)) || ((numbers[j] > numbers[max_index2]) && (j != max_index1)))
            max_index2 = j;
    }

    return  (long long) numbers[max_index1] * (long long) numbers[max_index2];
}

void tests() {
    assert(MaxPairWiseProduct_naive(vector<int> {2, 3, 4, 5}) == 20);
    assert(MaxPairWiseProduct_naive(vector<int> {9, 2, 7, 4, 21}) == 189);
    assert(MaxPairWiseProduct_naive(vector<int> {3, 8}) == 24);
    assert(MaxPairWiseProduct_naive(vector<int> {90000, 100000}) == 9000000000);
    /* Wont work for large inputs
    assert(MaxPairWiseProduct_naive(vector<int> (1000000, 0)) == 0);
    */

    assert(MaxPairWiseProductFast(vector<int> {2, 3, 4, 5}) == 20);
    assert(MaxPairWiseProductFast(vector<int> {9, 2, 7, 4, 21}) == 189);
    assert(MaxPairWiseProductFast(vector<int> {3, 8}) == 24);
    assert(MaxPairWiseProductFast(vector<int> {90000, 100000}) == 9000000000);
    assert(MaxPairWiseProductFast(vector<int> (1000000, 0)) == 0);
}

int main(int argc, char **argv) {

    int n;
    cin>>n;

    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairWiseProductFast(numbers);
    cout<<result<< "\n";

    //tests();

    return 0;
}
