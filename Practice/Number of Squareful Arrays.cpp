/*
https://leetcode.com/problems/number-of-squareful-arrays/
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// held-karp hamiltonian paths - O(2^n * n^2) - though we have to trade off with space here which is - O(2^n * n)
class Solution {
public:
    bool isPerfect(double v) {
        double rt = sqrt(v);
        return rt == (int)rt;
    }

    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        
        vector<int> graph[n];
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(isPerfect(A[i] + A[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        int lim = 1 << n;
        int dp[lim][n];
        memset(dp, 0, sizeof(dp));
        
        
        for(int i = 0, bit = 1; i < n; i++, bit <<= 1)
            dp[bit][i] = 1;
        
        for(int subset = 3; subset < lim; subset++) {
            for(int i = 0, biti = 1; i < n; i++, biti <<= 1) {
                if(subset & biti) {
                    for(int j: graph[i]) {
                        if(subset & (1 << j)) {
                            dp[subset][j] += dp[subset ^ (1 << j)][i];
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += dp[lim-1][i];
        
        for(int i = 0; i < n; i++) {
            int count = 1;
            for(int j = i+1; j < n; j++) {
                if(A[i] == A[j])
                    count++;
            }
            ans /= count;
        }
        
        return ans;
    }
};

// recursion - O(n! * n)
class Solution {
public:
    // set<vector<int>> s;
    
    bool isPerfect(double v) {
        double rt = sqrt(v);
        return rt == (int)rt;
    }
    
    void printv(vector<int>& v) {
        cout << "V: ";
        for(int i: v)
            cout << i << " ";
        cout << endl;
    }
    
    int n, ans;
    void recurse(vector<int>& A, vector<int>& res, int MASK) {
        if(res.size() == n) {
            ans++;
            return;
        }
        
        for(int i = 0, bit = 1; i < n; i++, bit <<= 1) {
            if((MASK & bit) || (i > 0 && A[i] == A[i-1] && !(MASK & (bit >> 1)))) continue;
            if(res.size() == 0 || isPerfect(res.back() + A[i])) {
                res.push_back(A[i]);
                recurse(A, res, MASK | bit);
                res.pop_back();
            }
        }
    }
    
    int numSquarefulPerms(vector<int>& A) {
        n = A.size();
        ans = 0;
        sort(A.begin(), A.end());
        vector<int> res;
        recurse(A, res, 0);
        return ans;
    }
};