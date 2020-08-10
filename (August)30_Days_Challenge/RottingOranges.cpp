/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/550/week-2-august-8th-august-14th/3418/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static int x = [](){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);return 0;}();
#define ff first;
#define ss second;
class Solution {
    int isfine(int i, int j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }
public:
    using pii = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ones = 0, count = 0;
        queue<pii> q;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    ones++;
            }
        int i, j;
        while(!q.empty()) {
            int s = q.size();
            while(s--) {
                pii f = q.front(); q.pop();
                i = f.ff; j = f.ss;
                
                if(isfine(i-1, j, n, m) && grid[i-1][j] == 1){grid[i-1][j] = 2; ones--; q.push({i-1, j});}
                if(isfine(i, j-1, n, m) && grid[i][j-1] == 1){grid[i][j-1] = 2; ones--; q.push({i, j-1});}
                if(isfine(i+1, j, n, m) && grid[i+1][j] == 1){grid[i+1][j] = 2; ones--; q.push({i+1, j});}
                if(isfine(i, j+1, n, m) && grid[i][j+1] == 1){grid[i][j+1] = 2; ones--; q.push({i, j+1});}
            }
            count++;
        }
        
        if(ones > 0) return -1;
        if(count == 0) return 0;
        return count-1;
    }
};