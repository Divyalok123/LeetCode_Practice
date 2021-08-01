/*
https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// smarter solution with stack - O(n)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if(n == 2) return arr[0] * arr[1];
        stack<int> s;
        int ans = 0;
        for(int& i: arr) {
            while(s.size() && s.top() <= i) {
                int t = s.top(); s.pop();
                int m = s.size() ? s.top() : INT_MAX;
                ans += t * min(m, i);
            }
            
            s.push(i);
        }
        
        while(s.size() > 1) {
            int ele = s.top(); s.pop();
            ans += ele * s.top();
        }
        
        return ans;
    }
};

// removing neighbours - O(n^2)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if(n == 2) return arr[0] * arr[1];
        int ans = 0;
        while(n > 1) {
            int minv = INT_MAX;
            int minind = -1;
            for(int i = 0; i < n; i++) 
                if(minv > arr[i])
                    minv = arr[i], minind = i;
            
            int smin = INT_MAX;
            if(minind == 0) smin = arr[minind + 1];
            else if(minind == n-1) smin = arr[minind-1];
            else smin = min(arr[minind + 1], arr[minind - 1]);
            ans += minv * smin;
            arr.erase(arr.begin() + minind);
            n--;
        }
        
        return ans;
    }
};

// bottom-dp - O(n^3)
class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if(n == 2) return arr[0] * arr[1];
        
        int dp[n][n];
        int maxinrange[n][n];
        
        for(int i = 0; i < n; i++) {
            int maxx = arr[i];
            for(int j = i; j < n; j++) {
                if(arr[j] > maxx)
                    maxx = arr[j];
                maxinrange[i][j] = maxx;
            }
        }
        
        for(int i = 0; i < n-1; i++) {
            dp[i][i] = 0;
            dp[i][i+1] = arr[i] * arr[i+1];
        }
        
        dp[n-1][n-1] = 0;
        
        for(int l = 3; l <= n; l++) {
            for(int i = 0; i <= n-l; i++) {
                int j = i + l - 1;

                dp[i][j] = INT_MAX;
                for(int k = 0; k < l-1; k++)
                    dp[i][j] = min(dp[i][j], dp[i][i+k] + dp[i+k+1][j] + maxinrange[i][i+k] * maxinrange[i+k+1][j]);
            }
        }
            
        
        return dp[0][n-1];
    }
};

// dfs + memo - O(n^3)
class Solution {
public:
    
    vector<vector<pair<int, int>>> cache;
    pair<int, int> dfs(vector<int>& arr, int i, int j) {
        if(i == j) return {0, arr[i]};
        
        if(i == j+1)
            return {arr[i] * arr[j], max(arr[i], arr[j])};
        
        if(cache[i][j] != make_pair(-1, -1))
            return cache[i][j];
        
        int thislarge = INT_MAX;
        int fans = INT_MAX;
        for(int k = i+1; k <= j; k++) {

            pair<int, int> a = dfs(arr, i, k-1);
            pair<int, int> b = dfs(arr, k, j);
            
            int alarge = a.second;
            int blarge = b.second;
            
            int asum = a.first;
            int bsum = b.first;
            
            if(asum + bsum + alarge*blarge < fans) {
                fans = asum + bsum + alarge*blarge;
                thislarge = max(alarge, blarge);
            }
        }
        
        return cache[i][j] = {fans, thislarge};
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if(n == 2) return arr[0] * arr[1];
        cache.resize(n, vector<pair<int, int>>(n, {-1, -1}));
        pair<int, int> ans = dfs(arr, 0, n-1);
        return ans.first;
    }
};