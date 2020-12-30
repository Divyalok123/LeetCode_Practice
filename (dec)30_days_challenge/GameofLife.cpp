/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/573/week-5-december-29th-december-31st/3586/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n, m;
    int arr[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {1, 0}, {0, -1}, {0, 1}};
    
    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(),m = board[0].size();
        int x, y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int c = 0;
                for(int k = 0; k < 8; k++) {
                    x = i+arr[k][0], y = j+arr[k][1];
                    if(check(x, y)) {
                        int point = board[x][y];
                        if((point == 1 || point == 3))
                            c++;
                    }
                }
                
                if(board[i][j] == 1 && (c < 2 || c > 3))
                    board[i][j] = 3;
                if(board[i][j] == 0 && c == 3)
                    board[i][j] = 2;
                    
            }
        }
        
        for(auto& v: board)
            for(auto& i: v)
            {
                if(i == 3) i = 0;
                if(i == 2) i = 1;
            }
        
    }
};