/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3446/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

//solution 2


//solution 1
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(k == 0 || n <= 1) return false;
        
        set<long> s;
        for(int i = 0; i < n; i++)
        {
            auto bot = s.lower_bound((long)nums[i]-t);
            auto top = s.upper_bound((long)nums[i]+t);
            
            if(bot != s.end() && (*bot <= (long)nums[i])) return true;
            if(top != s.begin())
            {
                top = prev(top);
                if(*top >= (long)nums[i]) return true;
            }
            
            s.insert((long)nums[i]);
            if(i >= k) s.erase((long)nums[i-k]);
        }
        
        return false;
    }
};