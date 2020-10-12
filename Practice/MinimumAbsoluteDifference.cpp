/*
https://leetcode.com/problems/minimum-absolute-difference/
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if(arr.size() <= 1)
            return {};
        
        sort(arr.begin(), arr.end());
        
        int minval = INT_MAX;
        
        for(int i = 1; i < arr.size(); i++)
            if((arr[i]-arr[i-1]) < minval)
                minval = arr[i]-arr[i-1];
        
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); i++)
            if((arr[i]-arr[i-1]) == minval)
                ans.push_back({arr[i-1], arr[i]});
        
        return ans;
    }
};