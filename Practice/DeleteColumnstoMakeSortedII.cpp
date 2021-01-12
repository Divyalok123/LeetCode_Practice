/*
https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        if(n <= 1)
            return 0;
        
        int m = A[0].size();
        vector<bool> v(n-1, 0);
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            bool check = 0;
            for(int j = 0; j < n-1; j++) {
                if(!v[j] && A[j][i] > A[j+1][i]) {
                    check = 1;
                    ans++;
                    break;
                }
            }
            
            if(check) continue;
            for(int j = 0; j < n-1; j++) {
                v[j] = v[j] || (A[j][i] < A[j+1][i]);
            }
        }        
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        if(n <= 1)
            return 0;
        
        int m = A[0].size();
        vector<string> v(n, "");
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                v[j].push_back(A[j][i]);
            }
            
            bool check = 0;
            for(int j = 1; j < n; j++) {
                if(v[j] < v[j-1]) {
                    check = 1;
                    break;
                }
            }
            
            if(check) {
                for(int j = 0; j < n; j++) {
                    v[j].pop_back();
                }
            }
        }        
        
        return m-v[0].size();
    }
};