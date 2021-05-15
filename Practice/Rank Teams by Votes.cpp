/*
https://leetcode.com/problems/rank-teams-by-votes/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//solution 1
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        if(votes.size() == 1 || votes[0].size()==1)
            return votes[0];
        
        int n = votes.size(), m = votes[0].size();
        string ans;
        
        vector<vector<int>> store(m, vector<int>(26));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                store[j][votes[i][j]-'A']++;
            }
        }
        
        vector<vector<int>> nextstore;
        for(int i = 0; i < 26; i++) {
            vector<int> v;
            bool check = 0;
            for(int j = 0; j < m; j++) {
                v.push_back(store[j][i]);
                if(store[j][i])
                    check = 1;
            }
            
            if(check)
            {
                v.push_back(-i);
                nextstore.push_back(v);
            }
        }
        
        sort(nextstore.begin(), nextstore.end(), greater<vector<int>>());
        
        for(auto& i: nextstore)
            ans.push_back(-1*i.back() + 'A');
        return ans;
    }
};