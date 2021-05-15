/*
https://leetcode.com/problems/max-value-of-equation/
*/

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <climits>
using namespace std;

// O(NLogN) - Priority Queue
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        priority_queue<pair<int, int>> pq;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            while(pq.size() && x-pq.top().second > k)
                pq.pop();
            
            if(pq.size())
                ans = max(ans, x+y + pq.top().first);
            
            while(pq.size() && pq.top().first <= y-x)
                pq.pop();
            
            pq.push({y-x, x});
        }
        
        return ans;
    }
};

// O(N) - Deque solution
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        
        deque<array<int, 2>> dq;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            while(dq.size() && x-dq.front()[0] > k)
                dq.pop_front();
            
            while(dq.size() && x-dq.back()[0] < y-dq.back()[1]) {
                if(x-dq.back()[0] + y + dq.back()[1] > ans) 
                    ans = x-dq.back()[0] + y + dq.back()[1];
                dq.pop_back();
            }
            
            if(dq.size() && x - dq.front()[0] + y + dq.front()[1] > ans) 
                ans = x-dq.front()[0] + y + dq.front()[1];
               
            dq.push_back({x, y});
        }
        
        return (int)ans;
    }
};