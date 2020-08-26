/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3433/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    vector<int> m;
    vector<vector<int>> rects;
    int totalarea;
public:
    
    int area(vector<int>& t)
    {
        return (t[2]-t[0]+1)*(t[3]-t[1]+1);
    }
        
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalarea = 0;
        m.resize(rects.size());
        for(int i = 0; i < this->rects.size(); i++)
        {
            totalarea += area(rects[i]);
            m[i] = totalarea;
        }
    }   
    
    vector<int> pick() {
        int val = rand()%totalarea;
        int r = upper_bound(m.begin(), m.end(), val)-m.begin();
        vector<int> v = rects[r];
        int x = v[0] + rand()%(v[2]-v[0]+1);
        int y = v[1] + rand()%(v[3]-v[1]+1);
        return {x, y};                
    }
};
