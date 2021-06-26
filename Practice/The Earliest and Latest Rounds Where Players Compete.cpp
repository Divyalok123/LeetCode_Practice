/*
https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// smarter dfs O(n^4 logn)
class Solution {
public:
    int ear, lat, n;
    void dfs(int l, int r, int total, int round) {
        if(l > r) 
            dfs(r, l, total, round);
        else if(l == r)
            ear = min(ear, round), lat = max(lat, round);

        for(int i = 1; i <= l; i++)
            for(int j = l-i+1; j < r-i+1; j++)
                if((i + j >= l + r - total/2) && (i + j <= (total+1)/2))
                    dfs(i, j, (total+1)/2, round+1);
    }
    
    vector<int> earliestAndLatest(int nn, int firstPlayer, int secondPlayer) {
        if(firstPlayer == n-secondPlayer+1)
            return {1, 1};
        
        n = nn, ear = nn, lat = 1;
        dfs(firstPlayer, n-secondPlayer+1, n, 1);
        return {ear, lat};
    }
};


// dfs (O(2^n) with pruning)
class Solution {
public:
    set<array<int, 3>> s;
    int e, l, n, fp, sp;
    void dfs(int MASK, int i, int j, int r, int mi, int mj) {
        if(r == n) return;

        if(i >= j)
            dfs(MASK, 0, n-1, r+1, 1, 1 << (n-1));
        else if(i == fp && j == sp) 
            e = min(e, r), l = max(l, r);
        else if(MASK & mi)
            dfs(MASK, i+1, j, r, mi << 1, mj);
        else if(MASK & mj)
            dfs(MASK, i, j-1, r, mi, mj >> 1);
        else {
            if(i != fp && i != sp)
                dfs(MASK | mi, i+1, j-1, r, mi << 1, mj >> 1);
            if(j != fp && j != sp)
                dfs(MASK | mj, i+1, j-1, r, mi << 1, mj >> 1);
        }
    }
    
    vector<int> earliestAndLatest(int nn, int firstPlayer, int secondPlayer) {
        if(firstPlayer == n-secondPlayer+1)
            return {1, 1};
        
        n = nn, e = nn, l = 1, fp = firstPlayer-1, sp = secondPlayer-1;
        dfs(0, 0, n-1, 1, 1, 1 << (n-1));
        return {e, l};
    }
};