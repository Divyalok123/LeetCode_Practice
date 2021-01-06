/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3594/
*/

#include <iostream>
#include <vector>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int m, n = arr.size()-1, i = 0;
        while(i <= n) {
            m = (i+n) >> 1;
            if(arr[m]-(m+1) < k)
                i = m+1;
            else
                n = m-1;
        }
        
        return n+1+k;
    }
};

/* Solution 1 */
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), count = 0, v;
        
        count += arr[0]-1;
        if(k <= count) return k;
        
        for(int i = 1; i < n; i++) {
            count += v = (arr[i]-arr[i-1]-1);
            if(count >= k) 
                return arr[i-1] + (v-(count-k));
        }

        return arr.back() + (k-count);
    }
};