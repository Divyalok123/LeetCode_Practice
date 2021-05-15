/*
https://leetcode.com/problems/min-cost-to-connect-all-points/
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// using prims
class Solution {
public:
    int dist(vector<int> a, vector<int> b) {
        return abs(b[0]-a[0]) + abs(b[1]-a[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> checked(n);
        vector<int> smallest(n, 10000000);
        int ans = 0;
        smallest[0] = 0;
        for(int i = 0; i < n; i++) {
            
            int ind = -1;
            for(int j = 0; j < n; j++) {
                if(!checked[j] && (ind == -1 || smallest[j] < smallest[ind]))
                    ind = j;
            }
            
            checked[ind] = 1;
            ans += smallest[ind];
            
            for(int j = 0; j < n; j++) {
                if(!checked[j])
                    smallest[j] = min(smallest[j], dist(points[j], points[ind]));
            }
        }
        
        return ans;
    }
};

/*
[[7,18],[-15,19],[-18,-15],[-7,14],[4,1],[-6,3]]
*/

// using kruskals algo (DSU, O(N^2log(N))), N^2 as there are N*(N-1)/2 edges
class Solution {
public:
    vector<int> parent, rank;
    
    int find(int a) {
       return parent[a] == a ? a : parent[a] = find(parent[a]); 
    }
    
    void dounion(int a, int b) {
        int pa = find(a), pb = find(b);
        
        if(pa != pb) {
            int ra = rank[pa], rb = rank[pb];
            
            if(ra < rb) {
                swap(pa, pb);
            } else if(ra == rb) {
                rank[a]++;
            }
            
            parent[pb] = pa;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int, 3>> v;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                v.push_back({abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]), i, j});
            }
        }
        
        sort(v.begin(), v.end());
        
        parent.resize(n);
        rank.assign(n, 1);
        
        iota(parent.begin(), parent.end(), 0);
        
        int i = 0, count = 0, ans = 0;
        while(count < n-1) {
            auto [a, b, c] = v[i++];
            
            if(find(b) != find(c)) {
                ans += a;
                count++;
                dounion(b, c);
            }
        }
        
        return ans;
    }
};