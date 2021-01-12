/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3599/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MOD 1000000007

/* Solution 2 (BITree) */
class Solution {
public:
    vector<int> bitree;
    int maxval;
    
    void update(int idx) {
        while(idx < maxval) {
            bitree[idx]++;
            idx += (idx & -idx);
        }
    }
    
    int sum(int idx) {
        int ans = 0;
        while(idx) {
            ans += bitree[idx];
            idx -= (idx & -idx);
        }
        return ans;
    }
    
    int createSortedArray(vector<int>& inst) {
        int maxv = *max_element(inst.begin(), inst.end());
        maxval = maxv+2;
        bitree.resize(maxval);
        int ans = 0, c = 0;
        for(int i: inst) {
            int ans1 = sum(i-1);
            int ans2 = c-sum(i);
            update(i);
            c++;
            ans = (ans + min(ans2, ans1))%MOD;
        }
        
        return ans;
    }
};

/* Solution 1 (Segment Tree) */
class Solution {
public:
    vector<int> stree;
    void update(int node, int s, int e, int pos) {
        if(s > e) return;
        if(s == e) {
            stree[node] = (stree[node]+1)%MOD;
            return;
        }
        int m = s + (e-s)/2;
        if(pos <= m) 
            update(2*node, s, m, pos);
        else
            update(2*node+1, m+1, e, pos);
        stree[node] = (stree[2*node] + stree[2*node+1])%MOD;
    
    }
    
    int query(int node, int s, int e, int qs, int qe) {
        if(qs > e || qe < s) return 0;
        
        if(qs <= s && qe >= e)
            return stree[node];
        
        int m = s + (e-s)/2;

        int q1 = query(2*node, s, m, qs, qe);
        int q2 = query(2*node+1, m+1, e, qs, qe);
        
        return (q1 + q2)%MOD;
    }
    
    int createSortedArray(vector<int>& inst) {
        int maxv = *max_element(inst.begin(), inst.end());
        stree.resize(4*maxv + 100);

        int ans = 0;
        for(int i: inst) {
            int ansl = query(1, 1, maxv, 1, i-1);
            int ansr = query(1, 1, maxv, i+1, maxv);
            
            update(1, 1, maxv, i);
            ans = (ans + (ansl < ansr ? ansl : ansr))%MOD;
        }
        
        return ans;
    }
};