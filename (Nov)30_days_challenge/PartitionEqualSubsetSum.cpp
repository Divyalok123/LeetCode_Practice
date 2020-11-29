/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3545/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 3 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0); // calculate sum
        if(sum&1) return 0; //if sum is odd return false;
        sum >>= 1;
        
        bitset<10005> dp = 1;
        for(int& a: nums) dp |= dp << a;
        return dp[sum];
    }
};

/* Improved solution 1 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        int sum = accumulate(nums.begin(), nums.end(), 0); // calculate sum
        if(sum&1) return 0; //if sum is odd return false;
        sum >>= 1;
        
        bool dp[sum+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for(int& a: nums) 
            for(int i = sum; i > 0; i--)
                if(i >= a) dp[i] = dp[i] || dp[i-a];
        
        return dp[sum];
    }
};

/* Solution 1 */
class Solution {
public:
    bool checksum(vector<int>& nums, int& h) {
        int n = nums.size();
        bool dp[n+1][h+1];
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= h; j++) {
                if (j == 0) dp[i][0] = 1;
                else if (i == 0) dp[0][j] = 0;
                else {
                    dp[i][j] = dp[i-1][j] || (j >= nums[i-1] ? dp[i-1][j-nums[i-1]] : 0);
                }
            }
        }
        
        return dp[n][h];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        int sum = 0; // calculate sum
        for(int& a: nums) sum += a;
        
        if(sum&1) return 0; //if sum is odd return false;
        
        int half = sum >> 1;
        
        //now check if there is any subsequence with this sum
        return checksum(nums, half);
    }
};

//[4, 5, 8, 4, 11]
//[11,12,12,17,17,13,100,23,9]