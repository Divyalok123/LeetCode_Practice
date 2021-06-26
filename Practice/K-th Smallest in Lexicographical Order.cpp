/*
https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
*/

#include <iostream>
#include <algorithm>
using namespace std;



// jumping to nextposition : O(log^2 (n))
class Solution {
public:
    
    int getSteps(long long currpos, long long nextpos, long long lim) {
        int steps = 0;
        while(currpos <= lim) {
            steps += min(nextpos, lim + 1) - currpos;
            nextpos *= 10;
            currpos *= 10;
        }
        
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int currnum = 1;
        k -= 1;
        while(k) {
            int stepsneeded = getSteps(currnum, currnum + 1, n);
            if(stepsneeded <= k) { 
                currnum++;
                k -= stepsneeded;
            } else {
                currnum *= 10;
                k--;
            }
        }
        
        return currnum;
    }
};