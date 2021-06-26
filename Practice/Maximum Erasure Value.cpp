/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/601/week-4-may-22nd-may-28th/3758/
*/

#include <iostream>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        int ans = 0, sum = 0;
        int count[10001] = {0};
        
        while(j < n) {
            count[nums[j]]++;
            sum += nums[j];
            
            if(count[nums[j]] > 1) {
                while(count[nums[j]] > 1) {
                    sum -= nums[i];
                    count[nums[i]]--;
                    i++;
                }
            }
            
            if(sum > ans)
                ans = sum;
            j++;
        }
        
        return ans;
    }
};