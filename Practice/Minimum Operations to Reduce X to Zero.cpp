/*
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using sliding window - O(n) time and O(1) space
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int sum = 0;
        for(int i: nums) sum += i;
        sum -= x;
        
        if(sum < 0) return -1;
        
        int ans = INT_MAX;
        
        int l = 0, r = 0, t = 0;
        while(r < n) {
            t += nums[r];
            if(t == sum) ans = min(ans, n-(r-l+1));
            else if(t > sum) {
                while(l <= r && t > sum)
                    t -= nums[l++];
                
                if(t == sum)
                    ans = min(ans, n-(r-l+1));
            }
            
            if(ans == 1) break;
            r++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

// using hashmap - O(n) time and O(n) space
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        unordered_map<int, int> um;
        int sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum += nums[i];
            if(sum > x)
                break;    
            um[sum] = i+1;
        }
        
        int ans = INT_MAX;
        if(um[x])
            ans = min(ans, n-um[x]+1);
        
        if(ans == 1) return ans;
        
        for(int i = 0; i < n-1; i++) {
            x -= nums[i];
            if(x < 0) break;
            else if(x == 0) ans = min(ans, i + 1);
            else {
                int ind = um[x];

                if(ind-1 > i) 
                    ans = min(ans, i+1 + n-ind+1);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};

// using suffix and binary search - O(nlogn) time and O(n) space  
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        vector<int> suffix(n);
        suffix[0] = nums[n-1];
        for(int i = n-2; i >= 0; i--)
            suffix[n-i-1] = suffix[n-i-2] + nums[i];
        
        int ans = INT_MAX;
        auto ind = lower_bound(suffix.begin(), suffix.end(), x);
        
        if(ind != suffix.end() && *ind == x)
            ans = ind - suffix.begin() + 1;
        
        for(int i = 0; i < n-1; i++) {
            x -= nums[i];

            if(x < 0) break;
            
            if(x == 0) ans = min(ans, i + 1);
            else {
                int ii = lower_bound(suffix.begin(), suffix.begin() + n-i-1, x) - suffix.begin();

                if(ii < n-i-1 && suffix[ii] == x)
                    ans = min(ans, i + 1 + ii + 1);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};