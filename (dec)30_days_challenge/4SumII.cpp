/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3569/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> a, b, c, d, ab;
        
        for(int& i: A) a[i]++;
        for(int& i: B) b[i]++;
        for(int& i: C) c[i]++;
        for(int& i: D) d[i]++;
        
        for(auto& f: a)
            for(auto& s: b)
                ab[f.first+s.first] += (f.second*s.second);
        
        int ans = 0;
        for(auto& f: c)
            for(auto& s: d)
                ans += ab[-(f.first + s.first)]*f.second*s.second;
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap;
        int n = A.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                umap[A[i]+B[j]]++;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int v = umap[-(C[i]+D[j])]; 
                if(v) ans += v;
            }
        }
        
        return ans;
    }
};