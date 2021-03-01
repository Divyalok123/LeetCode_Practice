/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3652/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 3 (O(1) - Space)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0, r = n-1;
        while(l < n-1 && nums[l] <= nums[l+1]) l++;
        if(l == n-1) return 0;
        
        while(r >= 1 && nums[r] >= nums[r-1]) r--;
        
        // cout << "l: " << l << " r: " << r << endl;
        
        int minv = INT_MAX, maxv = INT_MIN;
        for(int i = l; i <= r; i++) {
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
        }
        
        // cout << "minv: " << minv << " maxv: " << maxv << endl;
        l++, r--;
        while(l > 0 && nums[l-1] > minv) l--;
        while(r < n-1 && nums[r+1] < maxv) r++;
        
        // cout << "l: " << l << " r: " << r << endl;
        
        return r-l+1;
    }
};

// Solution 2 (space - O(N), time - O(N))
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n), r(n);
        
        int maxval = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(maxval < nums[i]) maxval = nums[i];
            l[i] = maxval;
        }
        
        int minval = INT_MAX;
        for(int i = n-1; i >= 0; i--) {
            if(minval > nums[i]) minval = nums[i];
            r[i] = minval;
        }
        
        int i = 0, j = n-1;
        while(i < n && nums[i] == r[i]) i++;
        
        if(i == n) return 0;
        
        while(j >= i && nums[j] == l[j]) j--;
        
        return j-i+1;
    }
};

// Solution 1 (Space-O(N), Time-O(NlogN))
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int i = 0, n = temp.size(), j = n-1;
        while(i < n && temp[i] == nums[i]) i++;
        
        if(i == n) return 0;
        
        while(j >= 0 && temp[j] == nums[j]) j--;
        
        return j-i+1;
    }
};