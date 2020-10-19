/*
https://leetcode.com/problems/combinations/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 2 (faster) */
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, int k, int n, vector<int>& curr) {
        if(k == 0) {
            ans.push_back(curr);
            return;
        }
        
        if(i == n+1)
            return;
        
        for(int j = i; j <= (n-k+1); j++) {
            curr.push_back(j);
            dfs(j+1, k-1, n, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        dfs(1, k, n, curr);
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    vector<vector<int>> ans;
    void dfs(int i, int k, int n, vector<int> &curr)
    {
        if (k == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j <= n; j++)
        {
            curr.push_back(j);
            dfs(j + 1, k - 1, n, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> curr;
        dfs(1, k, n, curr);
        return ans;
    }
};