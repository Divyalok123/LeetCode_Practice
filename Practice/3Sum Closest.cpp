/*
https://leetcode.com/problems/3sum-closest/
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//two-pointers
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), ans = -100000, curr = 100000;
        for(int i = 2; i < n; i++) {
            int newt = target-nums[i];
            int l = 0, r = i-1;
            
            while(l < r) {
                int newval = nums[l] + nums[r];
                int currval = abs(newval + nums[i] - target); 
                if(currval < curr) {
                    curr = currval;
                    ans = newval + nums[i];
                    
                    if(currval == 0)
                        return ans;
                }
                
                if(newval > newt)
                    r--;
                else 
                    l++;
            }
            
        }
        
        return ans;
    }
};

//naive O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        set<int> s;
        s.insert(nums[0] + nums[1]);
        
        int n = nums.size(), ans = -100000, curr = 100000;
        for(int i = 2; i < n; i++) {
            int newt = target-nums[i];
            auto ind = upper_bound(s.begin(), s.end(), newt);
            
            if(ind != s.end())
            {
                int newdiff = nums[i] + *ind;
                if(abs(target - newdiff) < curr) {
                    curr = abs(target-newdiff);
                    ans = newdiff;
                }
            }
            
            auto pre = prev(ind);
            int newdiff = nums[i] + *pre;
            if(abs(target-newdiff) < curr) {
                curr = abs(target-newdiff);
                ans = newdiff;
            }
            
            for(int j = i-1; j >= 0; j--)
                s.insert(nums[i] + nums[j]);
        }
        
        return ans;
    }
};
