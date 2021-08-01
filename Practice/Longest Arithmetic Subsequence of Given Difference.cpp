/*
https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        if(n == 1) return 1;
        
        unordered_map<int, int> inds;
        inds[arr[0]] = 1;
        
        int ans = 1;
        for(int i = 1; i < n; i++) {
            inds[arr[i]] = inds[arr[i]-difference] + 1;
            ans = max(ans, inds[arr[i]]);
        }
        
        return ans;
    }
};