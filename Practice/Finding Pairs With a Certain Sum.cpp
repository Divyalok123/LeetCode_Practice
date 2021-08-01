/*
https://leetcode.com/problems/finding-pairs-with-a-certain-sum/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

static int fio = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
class FindSumPairs {
    unordered_map<int, int> count1, count2;
    vector<int> nums;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int& i: nums1)
            count1[i]++;
        
        this->nums = nums2;
        
        for(int& i: nums2)
            count2[i]++;
    }
    
    void add(int index, int val) {
        count2[nums[index]]--;
        nums[index] += val;
        count2[nums[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto [i, count]: count1) {
            if(tot-i > 0) {
                ans += count2[tot-i] * count;
            }
        }
        
        return ans;
    }
};