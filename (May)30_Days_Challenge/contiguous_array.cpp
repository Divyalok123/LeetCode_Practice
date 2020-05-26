// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//Solution 3(array) (faster)
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int v[100002] = {};
        int max_len = 0;
        int sum = n;
        for(int i = 0; i < n; i++)
        {
            sum += (nums[i] == 0) ? -1 : 1;
            if(sum == n)
            { 
                max_len = i + 1;
                continue;
            }
            if(v[sum] != 0) max_len = max(max_len, i - v[sum]+1);
            else v[sum] = i+1;
        }
        return max_len;   
    }
};

//Solution 2 (hashmap) (passed)
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mapp;
        int max_len = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += (nums[i] == 0) ? -1 : 1;
            if(sum == 0)
            { 
                max_len = i + 1;
                continue;
            }
            if(mapp.find(sum) != mapp.end()) max_len = max(max_len, i - mapp[sum]);
            else mapp[sum] = i;
        }
        return max_len;   
    }
};

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