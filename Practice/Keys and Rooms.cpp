/*
https://leetcode.com/problems/keys-and-rooms/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    
    void dfs(int i, vector<vector<int>>& rooms, int& count, vector<bool>& vis) {
        if(vis[i]) return;
        
        count++;
        vis[i] = 1;
        
        for(auto& nex: rooms[i])
            if(vis[nex] == 0)   
                dfs(nex, rooms, count, vis);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0, n = rooms.size();
        vector<bool> vis(n);
        dfs(0, rooms, count, vis);
        return count == n;
    }
};