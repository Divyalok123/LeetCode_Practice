/*
https://leetcode.com/contest/weekly-contest-247/problems/cyclically-rotating-a-grid/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//smarter solution
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int count = min(n, m)/2;
        
        for(int i = 0; i < count; i++) {
            int total = (m-2*i) * 2 + (n-2*i) * 2 - 4;
            
            int rots = k % total;
            
            if(rots == 0) continue;
            
            vector<int> vec;
            for(int j = i; j < m-i; j++)
                vec.push_back(grid[i][j]);
            for(int j = i+1; j < n-i; j++)
                vec.push_back(grid[j][m-i-1]);
            for(int j = m-i-2; j >= i; j--)
                vec.push_back(grid[n-i-1][j]);
            for(int j = n-i-2; j > i; j--)
                vec.push_back(grid[j][i]);
            
            for(int j = i; j < m-i; j++) {
                grid[i][j] = vec[rots++];
                if(rots == total) rots = 0;
            }
            
            for(int j = i+1; j < n-i; j++) {
                grid[j][m-i-1] = vec[rots++];
                if(rots == total) rots = 0;
            }
            
            for(int j = m-i-2; j >= i; j--) {
                grid[n-i-1][j] = vec[rots++];
                if(rots == total) rots = 0;
            }
            
            for(int j = n-i-2; j > i; j--) {
                grid[j][i] = vec[rots++];
                if(rots == total) rots = 0;
            }
            
        }
        
        return grid;
    }
};

//naive rotations
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int count = min(n, m)/2;
        
        for(int i = 0; i < count; i++) {
            int total = (m-2*i) * 2 + (n-2*i) * 2 - 4;
            
            int rots = k % total;
            
            if(rots == 0) continue;
            
            // cout << "rots: " << rots << endl; 
            while(rots--) {
                int curr = grid[i][i];
                for(int j = i; j < m-i-1; j++) {
                    grid[i][j] = grid[i][j+1];
                }

                for(int j = i; j < n-i-1; j++) {
                    grid[j][m-i-1] = grid[j+1][m-i-1];
                }

                for(int j = m-i-1; j > i; j--) {
                    grid[n-i-1][j] = grid[n-i-1][j-1];
                }

                for(int j = n-i-1; j > i; j--) {
                    grid[j][i] = grid[j-1][i];
                }

                grid[i+1][i] = curr;

                // cout << "GRID" << endl;
                // for(auto& k: grid){
                //     for(int& l: k)
                //         cout << l << " ";
                //     cout << endl;
                // }
            }
        }
        
        return grid;
    }
};