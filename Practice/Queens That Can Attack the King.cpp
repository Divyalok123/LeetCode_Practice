/*
https://leetcode.com/problems/queens-that-can-attack-the-king/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<int> check(65, 0);
        for(auto& i: queens)
            check[i[0]*8+i[1]] = 1;
        
        vector<vector<int>> ans;
        
        int x = king[0]-1, y = king[1]-1;
        while(x >= 0 && y >= 0) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            x--, y--;
        }
        
        x = king[0]+1, y = king[1]+1;
        while(x <= 7 && y <= 7) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            x++, y++;
        }
        
        x = king[0]+1, y = king[1]-1;
        while(x <= 7 && y >= 0) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            x++, y--;
        }
        
        x = king[0]-1, y = king[1]+1;
        while(x >= 0 && y <= 7) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            x--, y++;
        }
        
        x = king[0]-1, y = king[1];
        while(x >= 0) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            x--;
        }
        
        x = king[0]+1, y = king[1];
        while(x <= 7) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            x++;
        }
        
        x = king[0], y = king[1]-1;
        while(y >= 0) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            y--;
        }
        
        x = king[0], y = king[1]+1;
        while(y <= 7) {
            int val = 8*x+y;
            if(check[val]) {
                ans.push_back({x, y});
                break;
            }
            y++;
        }
        
        return ans;
    }
};