/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3528/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* Solution 3 */
class Solution {
public:
    unordered_map<int, int> umap;
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int curr, vector<int>& vec) {
        if(curr == nums.size()) {
            ans.push_back(vec);
            return;
        }
        
        for(auto& [j, count]: umap) {
            if(count) {
                vec[curr] = j;
                count--;
                helper(nums, curr+1, vec);
                count++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        for(int& i: nums) umap[i]++;
        helper(nums, 0, vec);
        return ans;
    }
};

/* Solution 2 */
class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int curr, vector<int>& vec, vector<bool>& vis) {
        if(curr == nums.size()) {
            ans.push_back(vec);
            return;
        }
        
        for(int j = 0; j < nums.size(); j++) {
            if(!vis[j]) {
                vec[curr] = nums[j];
                vis[j] = 1;
                helper(nums, curr+1, vec, vis);
                vis[j] = 0;
                while(j+1 < nums.size() && nums[j] == nums[j+1])
                    j++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n);
        vector<bool> vis(n);
        sort(nums.begin(), nums.end());
        helper(nums, 0, vec, vis);
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do
        {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};