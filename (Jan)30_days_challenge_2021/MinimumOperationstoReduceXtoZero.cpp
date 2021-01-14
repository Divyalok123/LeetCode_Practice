/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3603/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 10000000

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        if(n == 1) return nums[0] == x ? 1 : -1;
        
        int total = 0;
        for(int& i: nums) total+= i;
        
        int sum = total-x, i = 0, j = 0;
        int ans = MAX;
        
        if(sum < 0) return -1;
        else if(sum == 0) return n;
        
        int curr = 0;
        while(j < n) {
            curr += nums[j];

            if(curr >= sum) {
                while(i < j && curr > sum) {
                    curr -= nums[i];
                    i++;
                }    
                
                if(curr == sum) 
                    ans = min(ans, n-(j-i+1));
            }
            j++;
        }
        
        return ans == MAX ? -1 : ans;
        
    }
};