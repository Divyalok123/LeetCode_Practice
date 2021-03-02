/*
https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3658/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int mix = 0, j = 1;
        for(int& i: nums) {
            mix ^= i;
            mix ^= j;
            j++;
        }
        
        mix = (mix & -mix);
        
        j = 1;
        int a = 0, b = 0;
        for(int& i: nums) {
            if(i&mix) a ^= i;
            else b ^= i;
            
            if(j&mix) a ^= j;
            else b ^= j;
            
            j++;
        }
        
        int count = 0;
        for(int& i: nums)
            if(i == a) count++;
        
        return count == 2 ? vector<int>{a, b} : vector<int>{b, a};
    }
};