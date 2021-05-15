/*
https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// KMP Optimization
class Solution {
public:
    void formlps(vector<int>& g, vector<int>& lps) {
        int n = g.size(), i = 1, lval = 0;
        lps[0] = 0;
        while(i < n) {
            if(g[i] == g[lval]) {
                lval++;
                lps[i] = lval;
                i++;
            } else {
                if(lval != 0) {
                    lval = lps[lval-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = nums.size(), m = groups.size();
        int j = 0, i = 0;
        while(i < m && j < n) {
            auto& ref = groups[i];
            //form lps
            vector<int> lps(ref.size());
            formlps(ref, lps);
            
            //search
            int ind = j, lpsind = 0;
            while(ind < n && lpsind < ref.size()) {
                if(nums[ind] == ref[lpsind])
                    lpsind++, ind++;
                else if(lpsind > 0)
                    lpsind = lps[lpsind-1];
                else
                    ind++;
            }
            
            //check if this group was found
            if(lpsind == ref.size())
                i++, j = ind;
            else
                return false;
            
        }        
        
        return i == m;
    }
};

// Concise STL - O(n*m)
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int m = groups.size();
        vector<int>::iterator itr = nums.begin();
        for(int i = 0; i < m; i++) {
            auto ind = search(itr, nums.end(), groups[i].begin(), groups[i].end());
            if(ind == nums.end())
                return false;
            
            itr = ind + groups[i].size();
        }
        return true;
    }
};

// simple solution - O(n*m)
class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int gr = 0, gc = 0, i = 0;
        int n = nums.size(), m = groups.size();
        
        while(i < n && gr < m) {
            if(nums[i] == groups[gr][0]) {
                gc = 0;
                int sz = groups[gr].size(), ti = i; 
                while(gc < sz && ti < n && groups[gr][gc] == nums[ti])
                    ti++, gc++;
                
                if(gc == sz) {
                    i = ti;
                    gr += 1;
                } else if(ti == n) {
                    return false;
                } else {
                    i++;
                }
            } else i++;
        }
        
        return gr == m;
    }
};