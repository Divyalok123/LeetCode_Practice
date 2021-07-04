/*
https://leetcode.com/contest/weekly-contest-247/problems/count-ways-to-build-rooms-in-an-ant-colony/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

if there are n children of x
    ans for x: ans[child1] * ans[child2] * .. * ans[childn] * (sum of number of children of this child (including it))/(fact[number of children of child[i]])

    all this finally converges to:
        n! / (multiple of sizeof every child)

*/

// solution 1 
class Solution {
public:
    #define MOD 1000000007
    int power(int x, int y) {
        int ans = 1;
        while(y) {
            if(y&1)
                ans = (ans * 1ll * x) % MOD;
            x = (x * 1ll * x) % MOD;
            y >>= 1;
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& graph, int i, vector<int>& sizes) {
        int sz = 1;
        for(int& nex: graph[i])
            sz += dfs(graph, nex, sizes);
        
        return sizes[i] = sz;
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<vector<int>> graph(n);
        
        for(int i = 1; i < n; i++)
            graph[prevRoom[i]].push_back(i);
        
        vector<int> sizes(n);
        dfs(graph, 0, sizes);
        
        int ans = 1;
        for(int i = 2; i < n; i++) 
            ans = (ans * 1ll * i) % MOD;
        
        for(int i = 1; i < n; i++)
            ans = (ans * 1ll * power(sizes[i], MOD-2)) % MOD;
        
        return ans;
    }
};