/*
https://leetcode.com/problems/moving-stones-until-consecutive-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        
        int a = stones[n-1]-stones[1] - 1 - (n-3);
        int b = stones[n-2]-stones[0] - 1 - (n-3);
        int maxim = a > b ? a : b;
        
        int minim = n, i = 0, j = 0;
        while(j < n) {
            while(stones[j]-stones[i] + 1 > n)
                i++;
            
            int count = j-i+1;
            if(count == n-1 && stones[j]-stones[i]+1 == n-1)
                minim = min(minim, 2);
            else
                minim = min(minim, n-count);
            j++;
        }
        
        return  {minim, maxim};
    }
};