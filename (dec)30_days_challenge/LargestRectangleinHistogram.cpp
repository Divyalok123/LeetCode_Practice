/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/573/week-5-december-29th-december-31st/3587/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        vector<int> left(n), right(n);
        left[0] = -1;
        right[n-1] = n;
        
        int k;
        for(int i = 1; i < n; i++) {
            k = i-1;
            while(k >= 0 && heights[k] >= heights[i]) k = left[k];
            left[i] = k;
        }
        
        for(int i = n-2; i >= 0; i--) {
            k = i+1;
            while(k < n && heights[k] >= heights[i]) k = right[k];
            right[i] = k;
        }
        
//         cout << "LEFT" << endl;
//         for(int& i: left) cout << i << " ";
//         cout << endl;
        
//         cout << "RIGHT" << endl;
//         for(int& i: right) cout << i << " ";
//         cout << endl;
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, (right[i]-left[i]-1)*heights[i]);
        
        return ans;
    }
};