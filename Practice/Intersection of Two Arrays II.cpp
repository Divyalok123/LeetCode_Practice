/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        ans.reserve(1000);
        
        int i = 0, j = 0, ni = nums1.size(), nj = nums2.size();
        
        while(i < ni && j < nj) {
            if(nums1[i] == nums2[j]) ans.push_back(nums1[i]), i++, j++;
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        return ans;
    }
};