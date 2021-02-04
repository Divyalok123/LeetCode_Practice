/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/584/week-1-february-1st-february-7th/3628/
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 3
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        if(nums[0] == nums.back()) return 0;
        
        int n = nums.size();
        vector<int>::iterator pre, ne;
        
        int prei = 0;
        pre = upper_bound(nums.begin(), nums.end(), nums[0]);
        if(pre == nums.end()) return 0;;
        int i = pre-nums.begin();
        
        while(i < n) {
            ne = upper_bound(nums.begin(), nums.end(), nums[i]);
            if(nums[i]-nums[prei] == 1) {
                int val = ne-nums.begin() - prei;
                if(val > ans) ans = val;
            }
            prei = i;
            i = ne-nums.begin();
        }
        
        return ans;
    }
};

// Solution 2
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        
        for(int& i: nums)
            m[i]++;
        
        int ans = 0;
        map<int, int>::iterator itr, itr2;
        itr = m.begin();
        while(itr != prev(m.end())) {
            itr2 = itr;
            itr2++;
            if(itr2->first-itr->first == 1) {
                int val = itr2->second+itr->second;
                if(val > ans) ans = val;
            }
            itr = itr2;
        }
        return ans;
    }
};

// Solution 1
class Solution {
public:
    int findLHS(vector<int>& nums) {
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for(int& i: nums) m[i]++;
        int n = m.size();
        v.resize(n);
        int i = 0;
        for(auto& j: m)
            v[i++] = j;
        
        sort(v.begin(), v.end());
        int ans = 0;
        
        for(i = 0; i < n-1; i++) {
            if(v[i+1].first-v[i].first == 1) {
                int val = v[i+1].second + v[i].second;
                if(val > ans) ans = val;
            }
        }
        return ans;
    }
};