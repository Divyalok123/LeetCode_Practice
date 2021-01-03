/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/568/week-5-november-29th-november-30th/3549/
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        int n = b.size();
        vector<pair<int, int>> v(2*n);
        
        int k = 0;
        for(auto& i: b) {
            v[k++] = {i[0], -i[2]};
            v[k++] = {i[1], i[2]};
        }
        
        sort(v.begin(), v.end()); 
        int currmaxh = 0;
        
        vector<vector<int>> ans;
        ans.reserve(2*n);
        
        multiset<int> mset;
        mset.insert(0);

        k = 0;
        while(k < 2*n) {
            pair<int, int> p = v[k++];
            int h = p.second;
            
            bool check = 0;
            if(p.second < 0) {
                mset.insert(-h);
            } else {
                auto val = mset.find(h);
                mset.erase(val);
                if(currmaxh == h) {
                    currmaxh = *mset.rbegin();
                    if(currmaxh != h) {
                        check = 1;
                        ans.push_back({p.first, currmaxh});
                    }
                }
            }   
            
            if(!check && -h > currmaxh) {
                currmaxh = -h;
                ans.push_back({p.first, currmaxh});
            }
        }
        
        return ans;
    }
};