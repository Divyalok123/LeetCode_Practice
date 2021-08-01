/*
https://leetcode.com/contest/weekly-contest-252/problems/three-divisors/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static vector<bool> getprime() {
        static vector<bool> prime;
        prime.assign(10001, true);
        prime[1] = false;
        for(int i = 2; i <= 10000; i++) {
            if(prime[i]) {
                for(int j = i*i; j <= 10000; j += i)
                    prime[j] = 0;
            }
        }
        return prime;
    }
    
    bool isThree(int n) {
        static auto prime = getprime();
        double val = (double)sqrt(n);
        return val == (int)val && prime[val];
    }
};