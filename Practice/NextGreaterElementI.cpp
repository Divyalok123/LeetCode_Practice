/*
https://leetcode.com/problems/next-greater-element-i/
*/

#include <iostream>
#include <algorithm>
#include <Vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0)
            return {};
        
        unordered_map<int, int> mm;
        stack<int> s;
        
        for(int i = nums2.size()-1; i >= 0; i--)
        {
            while(!s.empty() && (s.top()<=nums2[i]))
                s.pop();
            mm[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < nums1.size(); i++)
            nums1[i] = mm[nums1[i]];
        return nums1;
    }
};