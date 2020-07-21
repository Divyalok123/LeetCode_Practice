/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

static int x = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int n, int m, string& word, int si, int s)
    {
        if(i >= n || i < 0 || j < 0 || j >= m || board[i][j] == '-')
            return false;
        
        if(board[i][j] != word[si])
            return false;
        
        if(si == s-1) {
            if(board[i][j] == word[si])
                return true;
            else
                return false;
        }
         
        char c = board[i][j];
        board[i][j] = '-';
        bool ans = dfs(board, i-1, j, n, m, word, si+1, s)
            || dfs(board, i+1, j, n, m, word, si+1, s)
            || dfs(board, i, j-1, n, m, word, si+1, s)
            || dfs(board, i, j+1, n, m, word, si+1, s);
        
        board[i][j] = c;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int s = word.size(), n = board.size(), m = board[0].size();
        vector<pair<int, int>> v;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == word[0])
                    v.push_back({i, j});
        
        for(int i = 0; i < v.size(); i++)
            if(dfs(board, v[i].first, v[i].second, n, m, word, 0, s))
                return true;
        
        return false;
    }
};