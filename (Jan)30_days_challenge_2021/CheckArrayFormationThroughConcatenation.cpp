/*
https://leetcode.com/explore/featured/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3589/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> umap;
        for(int i = 1; i <= arr.size(); i++)
            umap[arr[i-1]] = i;
        
        for(auto& v: pieces) {
            int ind = umap[v[0]];
            if(ind == 0) return 0;
            for(int j = 1; j < v.size(); j++) 
                if(!umap[v[j]] || umap[v[j]] != ind+j) return false;
        }
        
        return true;
    }
};