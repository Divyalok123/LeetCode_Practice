// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int n = nums.size();
        
        int majority = -1;
        for(int i = 0; i < n; i++)
        {
            mymap[nums[i]]++;
            if(mymap[nums[i]] > floor(n/2))
            {
                majority = nums[i];
                break;
            }
        }
        
//         unordered_map<int, int>::iterator it = mymap.begin();
//         // int ans;
//         int majority = -1;
//         while(it != mymap.end())
//         {
//             if(it->second > floor(n/2))
//             {
//                 majority = it->first;
//                 break;
//             }
//             it++;
            
//         }
        
        return majority;
    }
};