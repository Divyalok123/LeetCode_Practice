#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> ans(n);
        stack<int> s;
        ans[n-1] = 0;
        s.push(n-1);
        
        for(int i = n-2; i >= 0; i--) {
            int c = 0;
            while(s.size() && heights[s.top()] < heights[i])
                s.pop(), c++;   
            
            ans[i] = c + (s.size() > 0);
            s.push(i);
        }
        
        return ans;
    }
};