/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        heights.push_back(0);
        stack<int> s;
        int ans = 0, back, ele;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!s.empty() && (heights[s.top()] >= heights[i]))
            {
                ele = heights[s.top()];
                s.pop();
                if(s.empty()) back = -1;
                else back = s.top();
                
                ans = max(ans, (i-back-1)*ele);
            }
            s.push(i);
        }
        return ans;
    }
};