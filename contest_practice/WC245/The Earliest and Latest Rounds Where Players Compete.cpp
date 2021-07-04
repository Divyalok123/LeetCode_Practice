/*
https://leetcode.com/contest/weekly-contest-245/problems/the-earliest-and-latest-rounds-where-players-compete/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//dfs
class Solution {
public:
    
    void dfs(int MASK, int i, int j, int fp, int sp, int& e, int& l, int n, int r) {
        if(r > n) return;
        if(i >= j) {
            dfs(MASK, 0, n-1, fp, sp, e, l, n, r + 1);
        } else if(MASK & (1 << i)) {
            dfs(MASK, i+1, j, fp, sp, e, l, n, r);
        } else if(MASK & (1 << j)) {
            dfs(MASK, i, j-1, fp, sp, e, l, n, r);
        } else if(i == fp && j == sp) {
            e = min(e, r);
            l = max(l, r);
        } else {
            if(i != fp && i != sp)
                dfs(MASK | (1 << i), i + 1, j - 1, fp, sp, e, l, n, r);
            if(j != fp && j != sp)
                dfs(MASK | (1 << j), i + 1, j - 1, fp, sp, e, l, n, r);
        }
    }
    
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if(firstPlayer == 1 && secondPlayer == n) return {1, 1};
        
        int e = n, l = 1;

        dfs(0, 0, n-1, firstPlayer-1, secondPlayer-1, e, l, n, 1);
        
        return {e, l};
    }
};