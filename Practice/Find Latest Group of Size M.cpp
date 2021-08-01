/*
https://leetcode.com/problems/find-latest-group-of-size-m/
*/

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

// COUNT the groups
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        
        if(n == m) return n;
        
        int count[n+1], length[n+2];
        memset(count, 0, sizeof count);
        memset(length, 0, sizeof length);
        
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int v = arr[i], ll = 0, lr = 0;
            
            if(v > 1)
                ll = length[v-1];
            if(v < n)
                lr = length[v+1];
            
            length[v] = ll + lr + 1;
            
            if(ll)
                length[v-ll] = ll + lr + 1;
            if(lr)
                length[v+lr] = ll + lr + 1;
            
            count[length[v]]++;
            count[ll]--;
            count[lr]--;
            
            if(count[m])
                ans = i + 1;
        }
        
        return ans;
    }
};

// UNION-FIND - (union by size) - O(nlogn)
class Solution {
public:
    vector<int> parent, size;
    
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa == pb) return;
        
        int sa = size[pa], sb = size[pb];
        
        if(sa < sb) swap(pa, pb);
        
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(m == n) return n;
        
        parent.resize(n);
        size.resize(n);
        
        iota(parent.begin(), parent.end(), 0);
        
        int count[n+1];
        memset(count, 0, sizeof(count));
        
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int val = arr[i];
            size[val-1] = 1;
            
            if(val < n && size[val]) {
                count[size[find(val)]]--;
                un(val-1, val);
            }
            
            if(val > 1 && size[val-2]) {
                count[size[find(val-2)]]--;
                un(val-1, val-2);
            }
            
            count[size[find(val-1)]]++;
            if(count[m])
                ans = i+1;
        }
        
        return ans;
    }
};