/*
https://leetcode.com/contest/weekly-contest-245/problems/merge-triplets-to-form-target-triplet/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> tri({0,0,0});
        
        for(auto& t: triplets) {
            vector<int> newv(3);
            for(int i = 0; i < 3; i++)
                newv[i] = max(t[i], tri[i]);
            
            bool check = true;
            for(int i = 0; i < 3; i++)
                if(newv[i] > target[i])
                    check = false;
            
            if(check)
                tri = newv;
        }
        
        return tri == target;
    }
};