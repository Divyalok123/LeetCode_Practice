/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3482/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/* Solution 2 ( O(n) ) */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() <= 1)   
            return 0;
        
        unordered_map<int, int> mm;
        
        for(int& a: nums)
            mm[a]++;
        
        int count = 0;
        for(auto& a: mm)
        {
            if(k == 0) {
                if(a.second > 1)
                    count++;
            }
            else 
                if(mm.find(a.first+k) != mm.end())
                    count++;
        }
            
        
        return count;
    }
};

/* Solution 1 ( O(nlogn) but better than 99% )*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() <= 1)   
            return 0;
        
        unordered_set<int> ss;
        sort(nums.begin(), nums.end());
        int count = 0;
        
        for(int& number: nums)
            ss.insert(number);
        int i = 0;
        bool check = false;
        while(i < nums.size())
        {
            if(k != 0 && ss.find(nums[i]+k) != ss.end())
                count++;
            i++;
            check = false;
            while(i < nums.size() && nums[i] == nums[i-1]) {
                if(k == 0 && !check)
                {
                    check = true;
                    count++;
                }
                i++;
            }
        }
        
        return count;
    }
};