/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/586/week-3-february-15th-february-21st/3643/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 2 O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1, ans = 0;
        
        while(i < j) {
            int val = (j-i)*(height[j] > height[i] ? height[i] : height[j]);
            if(val > ans) ans = val;
            
            if(height[i] < height[j])
                i++;
            else 
                j--;
        }
        
        return ans;
    }
};

// Solution 1 O(nlogn)
static int x = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> maxvall(n), maxvalr(n);
        
        int maxval = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            if(maxval < height[i]) maxval = height[i];
            maxvall[i] = maxval;
        }
        
        maxval = INT_MIN;
        for(int i = n-1; i >= 0; i--) {
            if(maxval < height[i]) maxval = height[i];
            maxvalr[i] = maxval;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int curr = height[i];
            auto itr1 = lower_bound(maxvall.begin(), maxvall.begin() + i, curr);
            int val1 = maxvall.begin()-itr1 + i;
            if(val1*curr > ans) ans = val1*curr;
            
            int dis = n-i-1;
            auto itr2 = lower_bound(maxvalr.rbegin(), maxvalr.rbegin() + dis, curr);
            int val2 = maxvalr.rbegin()+dis-itr2;
            if(val2*curr > ans) ans = val2*curr;
        }
        
        return ans;
    }
};