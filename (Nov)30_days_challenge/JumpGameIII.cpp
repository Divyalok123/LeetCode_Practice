/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/568/week-5-november-29th-november-30th/3548/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& arr, int i, vector<bool>& v) {
        if(i < 0 || i >= arr.size())
            return false;

        if(v[i])
            return false;
        
        v[i] = 1;
        if(arr[i] == 0)
            return true;
        
        return helper(arr, i + arr[i], v) || helper(arr, i-arr[i], v);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> v(arr.size());
        return helper(arr, start, v);
    }
};