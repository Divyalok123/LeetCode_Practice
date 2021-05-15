/*
https://leetcode.com/problems/filling-bookcase-shelves/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 2 (DP)
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            int thiswidth = books[i][0];
            int height = dp[i] + books[i][1];
            int maxheight = books[i][1];
            
            for(int j = i-1; j >= 0; j--) {
                thiswidth += books[j][0];
                maxheight = max(maxheight, books[j][1]);
                
                if(thiswidth > shelf_width) break; 
                height = min(height, maxheight + dp[j]);        
            }   
            
            dp[i+1] = height;
        }
        
        return dp[n];
    }
};

// Solution 1  (memo)
class Solution {
public:
    int helper(int i, int currwidth, vector<vector<int>>& books, int width, int currmax, vector<vector<int>>& dp, int row) {
        if(i == books.size()) 
            return currmax;
        
        if(dp[i][currwidth] != -1)
            return dp[i][currwidth];
        
        int ans1 = INT_MAX, ans2 = INT_MAX;
        if(currwidth + books[i][0] <= width)
            ans1 = helper(i+1, currwidth + books[i][0], books, width, max(currmax, books[i][1]), dp, row);
        
        ans2 = currmax + helper(i+1, books[i][0], books, width, books[i][1], dp, row+1);
        return dp[i][currwidth] = min(ans1, ans2);
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<vector<int>> dp(n+1, vector<int>(1010, -1));
        return helper(0, 0, books, shelf_width, 0, dp, 0);
    }
};