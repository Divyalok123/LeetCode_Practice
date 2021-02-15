/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/585/week-2-february-8th-february-14th/3638/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define mp make_pair
#define ff first
#define ss second

// Solution 2 (A* Search)


// Solution 1 (Dijkstra)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        using ppi = pair<int, pair<int, int>>;

        if(grid[0][0] == 1) return -1;
        
        class cmp {
            public:
                bool operator()(ppi& a, ppi& b){
                    return a.first > b.first;
                }
        };
        
        
        priority_queue<ppi, vector<ppi>, cmp> pq; 
        int moves[8][2] = {{0,1}, {0,-1}, {1,0}, {1,1}, {1,-1}, {-1,-1},{-1, 0}, {-1,1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        
        pq.push(mp(1, mp(0, 0)));
        while(pq.size()) {
            auto top = pq.top();pq.pop();
            
            for(int i = 0; i < 8; i++) {
                int newi = top.ss.ff + moves[i][0];
                int newj = top.ss.ss + moves[i][1];
                
                if(newi >= 0 && newi < n && newj >= 0 && newj < n && grid[newi][newj] == 0 && dist[newi][newj] > top.ff+1) {
                    dist[newi][newj] = top.ff + 1;
                    pq.push(mp(top.ff+1, mp(newi, newj)));
                }
            }
        }
        
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
    
};