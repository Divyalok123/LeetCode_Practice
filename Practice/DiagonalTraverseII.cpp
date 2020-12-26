/*
https://leetcode.com/problems/diagonal-traverse-ii/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/* Solution 2 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), sz = 0;
        int maxsz = 0;
        for(int i = 0; i < n; i++) {
            sz += nums[i].size();
            if(i+nums[i].size() > maxsz) maxsz = i + nums[i].size();
        }
        
        vector<int> ans(sz);
        vector<vector<int>> umap(maxsz+10);
        
        int k = 0;
        for(int i = n-1; i >= 0; i--) 
            for(int j = 0; j < nums[i].size(); j++) {
                cout << "i: " << i << " j: " << j << endl;
                umap[i+j].push_back(nums[i][j]);
            }
        
        for(int i = 0; i < maxsz+10; i++)
            if(umap[i].size())
                for(int j = 0; j < umap[i].size(); j++)
                    ans[k++] = umap[i][j];

        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size(), sz = 0;
        for(auto& i: nums) sz += i.size();
        
        using ppi = pair<int, pair<int, int>>;
        vector<int> ans(sz);
        vector<ppi> temp(sz);
        
        int k = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < nums[i].size(); j++)
                temp[k++] = {i+j, {-i, j}};
        sort(temp.begin(), temp.end());
        
        for(int i = 0; i < sz; i++) 
            ans[i] = nums[-temp[i].second.first][temp[i].second.second];
        return ans;
    }
};