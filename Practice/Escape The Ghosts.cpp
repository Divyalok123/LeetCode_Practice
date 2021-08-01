/*
https://leetcode.com/problems/escape-the-ghosts/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int abss(int x) {
        return x < 0 ? -x : x;
    }
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abss(target[0]) + abss(target[1]);
        
        for(auto& g: ghosts) {
            int thisdist = abss(g[0]-target[0]) + abss(g[1]-target[1]);
            if(thisdist <= dist)
                return false;
        }
        
        return true;
    }
};