/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// using sort and median - O(nlogn)
class Solution {
public:
    int abss(int v) {
        return v < 0 ? -v : v;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return nums[0] == nums[1] ? 0 : abss(nums[0]-nums[1]);
        
        sort(nums.begin(), nums.end());
        int med = nums[n/2];
        
        int ans = 0;
        for(int& i: nums)
            ans += abss(i-med);
        
        return ans;
    }
};

// binary search solution - O(nlog(maxv-minv))
class Solution {
public:
    
    long long abss(long long v) {
        return v < 0 ? -v : v;
    }
    
    long long moves(vector<int>& nums, int targ) {
        long long sum = 0;
        for(int& i: nums)
            sum += abss((long long)targ-i);
        return sum;
    }
    
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(n == 2) return abss(nums[0]-nums[1]);
        
        int minv = INT_MAX, maxv = INT_MIN;
        for(int& i: nums) {
            if(minv > i) minv = i;
            if(maxv < i) maxv = i;
        }
        
        if(minv == maxv) return 0;
        
        int ans = INT_MAX;
        long long left, right, cent;
        while(minv < maxv) {
            int mid = minv + (maxv-minv)/2;

            left = moves(nums, mid-1);
            right = moves(nums, mid+1);
            cent = moves(nums, mid);

            if(cent <= left && cent <= right)
                return cent;

            else if(cent <= left)
                minv = mid+1;

            else 
                maxv = mid-1;
        }

        return moves(nums, minv);
    }
};