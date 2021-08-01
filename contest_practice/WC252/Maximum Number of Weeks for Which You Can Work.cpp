/*
https://leetcode.com/contest/weekly-contest-252/problems/maximum-number-of-weeks-for-which-you-can-work/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    #define ll long long
    long long numberOfWeeks(vector<int>& milestones) {
        ll sum = 0;
        for(int& i: milestones) sum += i;
        
        int maxx = *max_element(milestones.begin(), milestones.end());
        sum -= maxx;
        
        if(maxx > sum) return 2*sum + 1;
        return sum + maxx;
    }
};