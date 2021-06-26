/*
https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    #define MOD 1000000007
    vector<vector<int>> cache;
    int dfs(unordered_map<int, vector<int>>& people, vector<int>& aval, int j, int choosen, int n) {
        if(__builtin_popcount(choosen) == n)
            return 1;

        if(j == aval.size())
            return 0;

        int& ans = cache[choosen][j];
        if(ans != -1)
            return ans;
        
        ans = dfs(people, aval, j+1, choosen, n);
        for(int& nex: people[aval[j]]) {
            int curr = 1 << nex;
            if(choosen & curr)
                continue;
            int newMask = choosen | curr;
            ans = (ans + 0ll + dfs(people, aval, j+1, newMask, n))%MOD;
        }
        
        return ans;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        unordered_map<int, vector<int>> people;
        vector<int> available;
        for(int i = 0; i < n; i++)
            for(int& j: hats[i]) {
                auto& vec = people[j];
                if(vec.size() == 0)
                    available.push_back(j);
                vec.push_back(i);
            }
        
        cache.assign(1 << n, vector<int>(available.size(), -1));
        return dfs(people, available, 0, 0, n);
    }
};