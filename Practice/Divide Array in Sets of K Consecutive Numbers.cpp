/*
https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;

//solution 2 (much faster)
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n%k) return 0;
        
        sort(nums.begin(), nums.end());
        vector<array<int, 2>> vec;
        
        for(int i = 0; i < n; i++) {
            if(i == 0 || vec.back()[0] != nums[i])
                vec.push_back(array<int, 2>{{nums[i], 1}});
            else 
                vec[vec.size()-1][1]++;
        }
        
        int m = vec.size();
        for(int i = 0; i < m; i++) {
            if(vec[i][1] == 0) continue;
            
            int ni = i;
            
            if(ni + k - 1 >= n) 
                return false;
            
            for(int j = ni+1; j < ni + k; j++) {
                if(vec[j][0] != vec[j-1][0]+1)
                    return false;
                
                if(vec[j][1] < vec[j-1][1])
                    return false;
                
                vec[j][1] -= vec[ni][1];
            }
        }
        
        
        return 1;
    }
};

//solution 1 O(nlogn)
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n%k) return 0;
        
        unordered_map<int, int> count;
        for(int& i: nums)
            count[i]++;
        
        sort(nums.begin(), nums.end());
        
        for(int& i: nums) {
            if(count[i]) {
                for(int j = i; j < i+k; j++) {
                    if(count[j] == 0) 
                        return 0;
                    
                    count[j]--;
                }
            }
        }
        
        return 1;
    }
};