/*
https://leetcode.com/problems/couples-holding-hands/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// smarter simple swapping - because there is only one way to decompose the graph and every swap will count
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n), part(n);
        
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
            part[i] = i&1 ? i-1 : i+1;
        }
        
        int ans = 0, next, ind;
        for(int i = 0; i < n; i+=2) {
            next = i+1;
            if(row[next] != part[row[i]])
            {
                ans++;
                ind = pos[part[row[i]]];
                pos[row[ind]] = i+1;
                pos[row[next]] = ind;
                swap(row[ind], row[next]);
            }
        }
        
        return ans;        
    }
};

// union-find - O(N) (amortised)
class Solution {
public:
    vector<int> parent, rank;
    
    int find(int a) {
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    
    bool unionn(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa == pb) return 0;
        
        int ra = rank[pa], rb = rank[pb];
        
        if(ra > rb)
            swap(pa, pb);
        
        parent[pa] = pb;
        
        if(ra == rb) rank[pa]++;
        
        return 1;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() >> 1;
        
        parent.resize(2*n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(2*n);
        int swaps = 0;
        for(int i = 0; i < n; i++) {
            int ele1 = row[2*i];
            int ele2 = row[2*i + 1];
            
            if(unionn(ele1/2, ele2/2))
                swaps++;
        }   
        
        return swaps;
    }
};