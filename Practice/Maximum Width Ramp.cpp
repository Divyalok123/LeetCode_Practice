/*
https://leetcode.com/problems/maximum-width-ramp/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2-pointers - O(n)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
    public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        int maxx[n+1];  
        maxx[n] = 0;
        
        for(int i = n-1; i >= 0; i--)
            maxx[i] = (nums[i] > maxx[i+1]) ? nums[i] : maxx[i+1];
        
        int ans = 0, l = 0, r = 0;
            
        while(r < n) {
            while(l < r && nums[l] > maxx[r])
                l++;
            
            ans = max(ans, r-l);
            r++;
        }
        
        return ans;
    }
};

// stack - O(n)
class Solution {
    public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> store(1, 0);
        
        for(int i = 1; i < n; i++)
            if(nums[i] < nums[store.back()])
                store.push_back(i);
        
        int ans = 0;
        for(int i = n-1; i > ans; i--) {
            while(store.size() && nums[store.back()] <= nums[i]) {
                ans = max(ans, i-store.back());
                store.pop_back();
            }
        }
            
        return ans;
    }
};

// Binary Search - O(nlogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    int search(vector<int>& nums, vector<int>& store, int val) {
        int l = 0, r = store.size()-1;
        // cout << "val: " << val << endl;
        int ans = -1;
        while(l <= r) {
            int m = l + (r-l)/2;
            // cout << "m: " << m << endl;
            if(nums[store[m]] > val)
                l = m + 1;
            else {
                ans = store[m];
                r = m - 1;
            }
        }
        
        return ans;
    }
    
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> store(1, 0);
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            
            int val = search(nums, store, nums[i]);
            
            if(val != -1 && i - val > ans)
                ans = i-val;
            
            if(nums[i] < nums[store.back()])
                store.push_back(i);
        }
        
        return ans;
    }
};