#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    long long A, B, result;
    cin >> A >> B;

    int primeArySize = int(sqrt(B)) + 1;
    vector <bool> isPrime(primeArySize, true);
    vector <long long> primeNums;

    long long num;
    isPrime[0] = false;
    isPrime[1] = false;
    for (num = 2; num <= sqrt(primeArySize - 1); num++) {
        if (isPrime[num]) {
            primeNums.push_back(num);
            for (long long notPN = num * 2; notPN < primeArySize; notPN += num) {
                isPrime[notPN] = false;
            }
        }
    }
    for (num; num < primeArySize; num++) {
        if (isPrime[num]) primeNums.push_back(num);
    }

    result = 0;
    for (long long primeNum : primeNums) {
        long long n = primeNum;
        while (!(A / double(n) <= primeNum)) n *= primeNum;
        while (primeNum <= B / double(n)) {
            n *= primeNum;
            result++;
        }
    }

    cout << result;
    return 0;
}