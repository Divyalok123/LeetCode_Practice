/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
using namespace std;

// Binary Search - Time: 
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int getcount(vector<vector<int>>& mat, int val, array<int, 2>& sm) {
        int n = mat.size();
        int i = 0, j = n-1, count = 0;
        while(i < n && j >= 0) {
            if(mat[i][j] <= val) {
                sm[0] = max(sm[0], mat[i][j]);
                count += j+1;
                i++;
            } else {
                sm[1] = min(sm[1], mat[i][j]);
                j--;
            }
        }
        
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        
        while(l < r) {
            int m = l + (r-l)/2;
            
            array<int, 2> sm = {matrix[0][0], matrix[n-1][n-1]};
            int count = getcount(matrix, m, sm);
            
            if(count == k)
                return sm[0];
            
            if(count > k)
                r = sm[0];
            else
                l = sm[1];
        }
        
        return l;
    }
};

// Priority_queue - Time: O(klogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using temp = array<int, 2>;
        
        auto comp = [&matrix](const temp& a, const temp& b){
            return matrix[a[0]][a[1]] > matrix[b[0]][b[1]];
        };
        
        priority_queue<temp, vector<temp>, decltype(comp)> pq(comp);
        int n = matrix.size();
        
        for(int i = 0; i < n; i++)
            pq.push({i, 0});
        
        int count = 0;
        while(count < k-1) {
            auto top = pq.top();
            pq.pop();
            
            count++;
            int r = top[0], c = top[1];
            if(c < n-1) 
                pq.push({r, c+1});
        }
        
        auto top = pq.top();
        return matrix[top[0]][top[1]];
    }
};