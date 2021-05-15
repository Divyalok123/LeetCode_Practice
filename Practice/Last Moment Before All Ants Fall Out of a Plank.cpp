// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l = left.size(), r = right.size();
        if(l == 0 && r == 0) return 0;
        
        if(l == 0) return n-*min_element(right.begin(), right.end());
        if(r == 0) return *max_element(left.begin(), left.end());
        
        int ml = *max_element(left.begin(), left.end());
        int mr = *min_element(right.begin(), right.end());
        
        return ml > n-mr ? ml : n-mr;
    }
};
