/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/566/week-3-november-15th-november-21st/3535/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 1 */
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        if(n <= 1)
            return inter;
        
        vector<vector<int>> ans;
        sort(inter.begin(), inter.end(), [&](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        
        int s = inter[0][0], e = inter[0][1];
        for(auto& i: inter) {
            if(i[0] <= e)
                e = max(e, i[1]);
            else {
                ans.push_back({s, e});
                s = i[0], e = i[1];
            }
        }
        
        ans.push_back({s, e});
        return ans;
    }
};
