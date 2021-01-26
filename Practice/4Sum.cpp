/*
https://leetcode.com/problems/4sum/
*/

#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 1 (naive, N^3)*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        
        unordered_map<int, vector<pair<pair<int,int>, pair<int, int>>>> m;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        int i = 0, j;
        while(i < n) {
            j = i+1;
            while(j < n) {
                int val = nums[i] + nums[j];
                if(m.count(target-val)) {
                    for(auto& el: m[target-val]) {
                        set<int> ss;
                        ss.insert(i);ss.insert(j);ss.insert(el.second.first);ss.insert(el.second.second);
                        if(ss.size() == 4) {
                            vector<int> temp = {nums[i], nums[j], el.first.first, el.first.second};
                            sort(temp.begin(), temp.end());
                            s.insert(temp);
                        }
                    }
                }
                m[val].push_back({{nums[i], nums[j]},{i,j}});
                while(j < n-1 && nums[j] == nums[j+1])
                    j++;
                j++;
            }
            while(i < n-3 && nums[i] == nums[i+3]) 
                i++;
            i++;
        }
        
        ans.resize(s.size());
        i = 0;
        for(auto& el: s)
            ans[i++] = el;

        return ans;
    }
};