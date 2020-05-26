// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Solution 2 (hashmap) (passed)


//Solution 1 (brute) (TLE)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    
        int size = nums.size();
        if(size == 0 || size == 1) return 0;
        vector<pair<int, int>> v(size);
        if(nums[0] == 0) v[0].first = 1;
        else v[0].second = 1;
        for(int i = 1; i < size; i++)
        {
            if(nums[i] == 0)
            {
                v[i].first = v[i-1].first + 1;
                v[i].second = v[i-1].second;
            }
            else
            {
                v[i].second = v[i-1].second + 1;
                v[i].first = v[i-1].first;
            }
            
        }
        
        int max = INT_MIN;
        for(int i = 0; i < size; i++)
        {
            for(int j = i; j < size; j++)
            {
                if((v[j].first - (i > 0 ? v[i-1].first : 0)) == (v[j].second - (i > 0 ? v[i-1].second : 0)))
                {
                    if(max < (j-i+1))
                    {
                        max = j-i+1;
                    }
                }
            }
        }      
        
        return max == INT_MIN ? 0 : max;
    }
};