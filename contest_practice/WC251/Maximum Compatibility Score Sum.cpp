/*
https://leetcode.com/contest/weekly-contest-251/problems/maximum-compatibility-score-sum/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cache[1050];
    int N, M;
    int dfs(vector<vector<int>>& stud, int i, vector<vector<int>>& ment, int mask) {
        if(i == M) return 0;
        
        int& ans = cache[mask];
        if(ans != -1) return ans;
        
        ans = 0;
        for(int j = 0; j < M; j++) {
            if(mask & (1 << j)) continue;
            
            mask |= (1 << j);
            int val = 0;
            for(int k = 0; k < N; k++)
                if(ment[j][k] == stud[i][k])
                    val++;
            ans = max(ans, val + dfs(stud, i + 1, ment, mask));
            mask ^= (1 << j);
        }
        
        return ans;
    } 
    
    int maxCompatibilitySum(vector<vector<int>>& stud, vector<vector<int>>& ment) {
        M = stud.size();
        N = stud[0].size();
        memset(cache, -1, sizeof cache);
        return dfs(stud, 0, ment, 0);
    }
};