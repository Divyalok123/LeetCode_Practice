#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int res = 1;
        for(int& i: coins) {
            if(res-1 < i-1) return res;
            res += i;
        }
        
        return res;
    }
};