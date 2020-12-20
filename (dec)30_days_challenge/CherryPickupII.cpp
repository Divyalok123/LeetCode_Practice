/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3571/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 4 (solution 3 backwards) */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[n][m][m];
        memset(dp, 0, sizeof(dp));
        for(int i = n-1; i >= 0; i--) 
            for(int j = 0; j < m; j++) 
                for(int k = 0; k < m; k++) {
                    int value = (j == k) ? grid[i][j] : (grid[i][j] + grid[i][k]);
                    if(i != n-1) {
                        int l1 = j-1 >= 0 ? j-1 : 0, l2 = k-1 >= 0 ? k-1 : 0;
                        int r1 = j+1 < m ? j+1 : m-1, r2 = k+1 < m ? k+1 : m-1;
                        int val = 0;
                        for(int fj = l1; fj <= r1; fj++)
                            for(int fk = l2; fk <= r2; fk++)
                                val = max(val, dp[i+1][fj][fk]);
                        value += val;
                    }
                    dp[i][j][k] = value;
                }
        return dp[0][0][m-1];        
    }
};

/* Solution 3 */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dp[n][m][m];
        memset(dp, -1, sizeof(dp));
        dp[0][0][m-1] = grid[0][m-1] + grid[0][0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < m; k++) {
                    int value = (j == k) ? grid[i][j] : (grid[i][j] + grid[i][k]);
                    int l1 = (j-1 >= 0 ? j-1 : 0), l2 = (k-1 >= 0 ? k-1 : 0);
                    int r1 = (j+1 < m ? j+1 : m-1), r2 = (k+1 < m ? k+1 : m-1);
                    for(int fj = l1; fj <= r1; fj++)
                        for(int fk = l2; fk <= r2; fk++)
                            if(dp[i-1][fj][fk] != -1) {
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][fj][fk] + value);
                                ans = max(ans, dp[i][j][k]);
                            }
                }
            }
        }
        
        return ans;        
    }
};

/* Solution 2 */
class Solution {
    int n, m;
    int moves[3] = {-1, 0, 1};
public:
    int dp[75][75][75];
    int helper(vector<vector<int>>& grid, int r, int j1, int j2) {
        if(r == n || j1 == m || j2 == m || j1 < 0 || j2 < 0 || r < 0)
            return 0;
        
        int& val = dp[r][j1][j2];
        if(val != -1)
            return val;
        
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                val = max(val, helper(grid, r+1, j1+moves[i], j2+moves[j]));
        
        val += (j1 == j2) ? grid[r][j1] : (grid[r][j1] + grid[r][j2]);
        return val;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return helper(grid, 0, 0, m-1);
    }
};

/* Solution 1 */
class Solution {
    using pii = pair<int, int>;
    // using viiii = vector<vector<vector<vector<int>>>>;
    
    int dp[71][71][71];
    int n, m;
    pii moves[3] = {{1, -1}, {1, 0}, {1, 1}};
    bool isfine(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
public:
    
    int helper(vector<vector<int>>& grid, pii p1, pii p2, int& ans) {
        if(p1.second == m || p2.second == m) 
            return 0;
        
        if(!isfine(p1.first, p1.second) || !isfine(p2.first, p2.second))
            return -1e9;
        
        pii new1, new2;
        int a = grid[p1.first][p1.second], b = grid[p2.first][p2.second];

        int& vall = dp[p1.first][p1.second][p2.second]; 
        if(vall != -1)
            return vall;
        
        grid[p1.first][p1.second] = 0;
        grid[p2.first][p2.second] = 0;
        
        int sum;
        if(p1 == p2)
            sum = a;
        else
            sum = a + b;
        
        int fans = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                
                new1.first = p1.first + moves[i].first;
                new1.second = p1.second + moves[i].second;
                new2.first = p2.first + moves[j].first;
                new2.second = p2.second + moves[j].second;
                
                int val = helper(grid, new1, new2, ans);
                fans = max(fans, val);
            }
        }
        
        grid[p1.first][p1.second] = a;
        grid[p2.first][p2.second] = b;
        return vall = fans + sum;;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        pii p1 = {0, 0}, p2 = {0, m-1};
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        return helper(grid, p1, p2, ans);
    }
};