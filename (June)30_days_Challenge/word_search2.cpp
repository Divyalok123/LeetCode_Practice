// Given a 2D board and a list of words from the dictionary, find all words in the board.
// Each word must be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    char c;
    bool isEnd;
    TrieNode *children[26];
    string word;

    TrieNode() {}
    TrieNode(char c)
    {
        this->c = c;
        this->isEnd = false;
        for (int i = 0; i < 26; i++)
            this->children[i] = NULL;
        this->word = "";
    }
};

TrieNode *root = new TrieNode('/');

void insert(string s)
{
    if (s.empty())
        return;

    TrieNode *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        int ind = s[i] - 'a';
        TrieNode *node = new TrieNode(s[i]);
        if (curr->children[ind] == NULL)
            curr->children[ind] = node;

        curr = curr->children[ind];
    }

    curr->isEnd = true;
    curr->word = s;
}

void build(vector<string> &v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        insert(v[i]);
    }
}

void dfs(vector<vector<char>> &b, int i, int j, int n, int m, vector<string> &output, TrieNode *curr)
{

    if (i >= n || i < 0 || j >= m || j < 0)
    {
        return;
    }

    int ind = b[i][j] - 'a';
    if (b[i][j] == '#' || curr->children[ind] == NULL)
        return;

    curr = curr->children[ind];
    if (curr->isEnd)
    {
        output.push_back(curr->word);
        curr->isEnd = false;
    }

    char c = b[i][j];
    b[i][j] = '#';

    dfs(b, i + 1, j, n, m, output, curr);
    dfs(b, i - 1, j, n, m, output, curr);
    dfs(b, i, j - 1, n, m, output, curr);
    dfs(b, i, j + 1, n, m, output, curr);

    b[i][j] = c;
}

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = board.size();
        int m = board[0].size();

        root = new TrieNode('/');
        build(words);
        vector<string> output;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                dfs(board, i, j, n, m, output, root);
        }

        return output;
    }
};