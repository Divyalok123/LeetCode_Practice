/*
https://leetcode.com/problems/maximal-rectangle/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

/* Solution 3 (SPACE OPTIMISED - O(N*M)) */
class Solution {
public:
    int hist(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        
        vector<int> l(n), h(n);
        l[0] = -1, h[n-1] = n;
        for(int i = 1; i < n; i++)
        {
            int j = i-1;
            while(j >= 0 && v[j] >= v[i])
                j = l[j];
            l[i] = j;
        }
        
        for(int i = n-2; i >= 0; i--) {
            int j = i+1;
            while(j < n && v[j] >= v[i])
                j = h[j];
            h[i] = j;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int val = v[i]*(h[i]-l[i]-1);
            if(val > ans) ans = val;
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        
        vector<int> v(m);
        for(int i = 0; i < m; i++)
            v[i] = matrix[0][i] == '1';
        int ans = hist(v);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') v[j]++;
                else v[j] = 0;
            }
            
            int val = hist(v);
            if(val > ans)
                ans = val;
        }
        
        return ans;
    }
}; 

/* Solution 2 (TIME OPTIMISED) (O(N*M) - time) (O(N*M*N) - space) */
class Solution {
public:
    int hist(vector<int>& v) {
        int n = v.size();
        if(n == 1) return v[0];
        
        vector<int> l(n), h(n);
        l[0] = -1, h[n-1] = n;
        for(int i = 1; i < n; i++)
        {
            int j = i-1;
            while(j >= 0 && v[j] >= v[i])
                j = l[j];
            l[i] = j;
        }
        
        for(int i = n-2; i >= 0; i--) {
            int j = i+1;
            while(j < n && v[j] >= v[i])
                j = h[j];
            h[i] = j;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int val = v[i]*(h[i]-l[i]-1);
            if(val > ans) ans = val;
        }
        
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n==0) return 0;
        int m = matrix[0].size();
        
        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i < m; i++)
            v[0][i] = matrix[0][i] == '1';
        int ans = hist(v[0]);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') 
                    v[i][j] = v[i-1][j] + 1;
            }
            int val = hist(v[i]);
            if(val > ans)
                ans = val;
        }
        
        return ans;
    }
};

/* Solution 1 O(N*M*N) */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));
        int ans = 0;
        
        if(matrix[0][0] == '1') dp[0][0] = {1, 1}, ans++;
        
        for(int i = 1; i < n; i++)
        {
            if(matrix[i][0] == '1') {
                auto& val = dp[i][0];
                val.first = dp[i-1][0].first + 1;
                val.second = 1;
                if(val.first > ans) ans = val.first;
            }
        }
        
        for(int j = 1; j < m; j++) {
            if(matrix[0][j] == '1') {
                auto& val = dp[0][j];
                val.second = dp[0][j-1].second + 1;
                val.first = 1;
                if(val.second > ans) ans = val.second;
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == '1') {
                    auto& val = dp[i][j];
                    val.first = dp[i-1][j].first + 1;
                    val.second = dp[i][j-1].second + 1;
                    
                    if(val.first > ans) ans = val.first;
                    if(val.second > ans) ans = val.second;
                    
                    int minv = val.second;
                    for(int k = i-1; k >= 0; k--) {
                        auto& val2 = dp[k][j];
                        minv = min(minv, val2.second);
                        int diff = i-k+1;
                        if(diff*minv > ans) ans = diff*minv;
                    }
                }
            }
        }
        
//         cout << "DP" << endl;
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 cout << "[" << dp[i][j].first << "," << dp[i][j].second << "] ";
//             }
//             cout << endl;
//         }
        
        return ans;
    }
};