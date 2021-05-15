/*
https://leetcode.com/problems/construct-target-array-with-multiple-sums/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Heap - O(nlogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0] == 1;
        
        make_heap(nums.begin(), nums.end());

        long long sum = 0;
        for(int& i: nums)
            sum += i;
        
        while(nums.size() && nums.front() != 1) {
            int maxx = nums.front();
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            
            int rem = sum - maxx;
            if(rem >= maxx || rem < 1) return false;
            if(rem == 1) return true;
            
            maxx %= rem;
            if(maxx == 0) return false;
            
            sum = rem + maxx;
            if(maxx > 1) {
                nums.push_back(maxx);
                push_heap(nums.begin(), nums.end());
            }
        }
        
        return true;
    }
};

// recursion - O(n^2)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0] == 1;
        
        int maxval = INT_MIN, n = nums.size(), ind = -1;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(maxval < nums[i]) {
                maxval = nums[i];
                ind = i;
            }
        }
        
        sum -= maxval;
        if(maxval == 1 || sum == 1)
            return true;
        
        if(sum >= nums[ind])
            return false;
        
        nums[ind] %= sum;
        if(nums[ind] == 0) 
            return false;
        
        return isPossible(nums);
    }
};