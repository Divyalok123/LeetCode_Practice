/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3608/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1) return 0;
        
        unordered_map<int, int> umap;
        for(int& i: nums)
            umap[i]++;
            
        int ans = 0;
        for(auto& i: umap) {
            int v = k-i.first;
            if(k-v == 0) {
                continue;
            } else if(v == k-v) {
                ans += i.second/2;
                i.second = 0;
            } else {
                auto r = umap.find(v);
                if(r == umap.end()) continue;
                int minv = min(i.second, r->second);
                ans += minv;
                i.second -= minv;
                r->second -= minv;
            }
        }
        
        return ans;
    }
};