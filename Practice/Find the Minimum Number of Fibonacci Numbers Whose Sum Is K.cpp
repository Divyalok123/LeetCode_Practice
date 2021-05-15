/*
https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fibs;

static int getall = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    fibs.push_back(1);
    int a = 0, b = 1;
    while(b < 1000000000) {
        int c = a + b;
        fibs.push_back(c);
        a = b;
        b = c;
    }
    
    return 0;
}();

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        int count = 0;
        while(k) {
            auto ind = upper_bound(fibs.begin(), fibs.end(), k);
            int pre = *(prev(ind));
            
            int c = k/pre;
            int t = c*pre;
            
            k-=t;
            count += c;
        }
        
        return count;
    }
};