/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3617/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define p pair<int, int>
#define pp pair<int, p>
#define ff first
#define ss second

//Solution 2
class Solution {
public:
    int n, m;
    int moves[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    
    bool check(int i, int j) { 
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    vector<vector<bool>> vis;
    
    bool dfs(int i, int j, int lim, vector<vector<int>>& v) {
        if(i == n-1 && j == m-1)
            return 1;
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int ni = i + moves[k][0];
            int nj = j + moves[k][1];
            
            if(check(ni, nj) && vis[ni][nj]==0 && abs(v[i][j]-v[ni][nj]) <= lim)
               if(dfs(ni, nj, lim, v))
                   return 1;
        }
        
        return 0;
    }    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        int i = 0, j = 999999, mid;
        int ans = 999999;
        while(i <= j) {
            mid = i + (j-i)/2;
            vis.assign(n, vector<bool>(m, 0));
            if(dfs(0, 0, mid, heights)) {
                ans = mid;
                j = mid-1;
            } else
                i = mid+1;
        }
        
        return ans;
    }
};

//Solution 1
class Solution {
public:
    class cmp {
      public:
        bool operator()(pp& a, pp& b){
            return a.ff > b.ff;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        p dest = {n-1, m-1};
        
        auto check = [&n, &m](int i, int j) {return i >= 0 && i < n && j >= 0 && j < m;};
        p moves[4] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<pp, vector<pp>, cmp> pq;
        pq.push({0, {0, 0}});
        
        while(pq.size()) {
            pp f = pq.top();
            pq.pop();
            
            int val = f.ff;
            p ind = f.ss;
            
            if(ind == dest) return val;
            
            if(dp[ind.ff][ind.ss] < val) continue;
            
            int h = heights[ind.ff][ind.ss];
            for(int k = 0; k < 4; k++) {
                int i = ind.ff + moves[k].ff;
                int j = ind.ss + moves[k].ss;
                
                if(check(i, j)) {
                    int m = max(val, abs(h-heights[i][j]));
                    if(m < dp[i][j]) {
                        dp[i][j] = m;
                        pq.push({m, {i, j}});
                    }
                }
            }            
        }
        
        return 0;
    }
};