/*
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<array<int, 2>> q;
        q.push({entrance[0], entrance[1]});
        
        auto isfine = [&n, &m] (int& i, int& j) {return i < n && j < m && i >= 0 && j >= 0;};
        auto isend = [&n, &m] (int& i, int& j) {return i == 0 || i == n-1 || j == 0 || j == m-1;};
        
        int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int ans = 0;
        maze[entrance[0]][entrance[1]] = '-';
        
        while(q.size()) {
            int sz = q.size();
            
            while(sz--) {
                auto t = q.front();
                q.pop();
                
                if(ans && isend(t[0], t[1])) return ans;
                
                
                for(int k = 0; k < 4; k++) {
                    int ni = t[0] + moves[k][0];
                    int nj = t[1] + moves[k][1];
                    
                    if(isfine(ni, nj) && maze[ni][nj] == '.') {
                        maze[ni][nj] = '-';
                        q.push(array<int, 2>{ni, nj});
                    }
                }
                
            }
            
            ans++;
        }
        
        return -1;
    }
};