/* https://leetcode.com/problems/two-sum/ */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int > _m;
        for(int i = 0; i < nums.size(); i++) {
            int val = _m[target-nums[i]];
            _m[nums[i]] = i;
            if(i != 0 && val != i) {
                if(val == 0 && nums[0] != target-nums[i]) continue;
                _m.clear();
                return {val, i};
            }
        }
        _m.clear();
        return {};
    }
};