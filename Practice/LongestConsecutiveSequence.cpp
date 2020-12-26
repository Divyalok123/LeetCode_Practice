/*
https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

/* Solution 3 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0, left, right, sum;
        for(int i: nums) {
            if(umap.count(i)) continue;
            umap.insert({i, 1});
            
            left = 0, right = 0;
            if(umap.count(i-1))
                left = umap[i-1];
            if(umap.count(i+1))
                right = umap[i+1];
            
            sum = left+right+1;
            ans = max(ans, sum);
            umap[i-left] = sum;
            umap[i+right] = sum;
        }
        
        return ans;
    }
};

/* Solution 2 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        sort(nums.begin(), nums.end());
        
        int count = 1, ans = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]+1) count++;
            else if(nums[i] == nums[i-1]);
            else count = 1;
            
            ans = max(ans, count);
        }
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> umap;
        for(int i: nums)
            umap[i] = 1;
        int count = 0, ans = 0;
        for(int i: nums) {
            count = 1;
            for(int j = i-1; umap[j]; j--)
                umap[j] = 0, count++;
            for(int j = i+1; umap[j]; j++)
                umap[j] = 0, count++;
            ans = max(ans, count);
        }
        
        return ans;
    }
};