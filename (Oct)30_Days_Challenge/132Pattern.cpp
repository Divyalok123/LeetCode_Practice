/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/562/week-4-october-22nd-october-28th/3505/
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/* Solution 2 */


/* Solution 1 O(n^2) */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return false;

        int a = INT_MAX, b, j;
        for(int i = 0; i < n-2; i++) {
            a = min(a, nums[i]);
            if(a == nums[i]) continue;

            for(j = i+1; j < n; j++) {
                if((nums[j] < nums[i]) && (nums[j] > a))
                    return true;
                // b = max(b, nums[j]);
            }
        }
        return false;
    }
};