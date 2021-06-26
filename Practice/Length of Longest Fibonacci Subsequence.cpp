/*
https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>
using namespace std;

// smarter two pointer solution
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i < n; i++) {
            
            int l = 0, r = i-1;
            while(l < r) {
                int sum = arr[l] + arr[r];
                if(sum > arr[i]) r--;
                else if(sum < arr[i]) l++;
                else {
                    dp[r][i] = dp[l][r] + 1;
                    if(ans < dp[r][i])
                        ans = dp[r][i];
                    l++, r--;
                }
            }
            
        }
        
        return ans == 0 ? 0 : ans + 2;
    }
};

// search with hash table operation with dp - O(n^2) : TLE (mp due to unordered_map)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, dp[n][n];
        memset(dp, 0, sizeof(dp));

        unordered_map<int, int> um;
        um[arr[0]] = 1;
        um[arr[1]] = 2;
        
        for(int i = 2; i < n; i++) {
            um[arr[i]] = i+1;
            for(int j = 0; j < i; j++) {
                int itr = um[arr[i]-arr[j]];
                if(itr == 0 || arr[i]-arr[j] >= arr[j]) continue;
                dp[j][i] = dp[itr-1][j] + 1;
                if(dp[j][i] > ans)
                    ans = dp[j][i];
            }
        }
        
        return ans == 0 ? 0 : ans + 2;
    }
};

// using binary search with dp - O(n^2logn)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int itr = upper_bound(arr.begin(), arr.begin() + j, arr[i]-arr[j])-arr.begin();
                if(itr == 0 || arr[itr-1] != arr[i]-arr[j])
                    dp[j][i] = 2;
                else
                    dp[j][i] = dp[itr-1][j] + 1;
                
                if(dp[j][i] > ans)
                    ans = dp[j][i];
            }
        }
        
        return ans > 2 ? ans : 0;
    }
};


// naive interating for every pair - O(n^2logn)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s;
        s = {arr[0], arr[1]};
        int n = arr.size(), ans = 0;
        for(int i = 2; i < n; i++) {
            // cout << "i: " << i << " " << arr[i] << endl;
            for(int j = i-1; j >= ans; j--) {
                // cout << "j: " << j << " " << arr[j] << endl;
                int a = arr[i], b = arr[j], diff = a-b, c = 0;
                // cout << "diff: ";
                while(diff < b && s.find(diff) != s.end()) {
                    // cout << diff << " | ";
                    c++;
                    a = b;
                    b = diff;
                    diff = a-b;
                }
                // cout << endl;
                
                if(c && ans < c + 2)
                    ans = c + 2;
                // cout << "ans: " << ans << endl;
            }
            s.insert(arr[i]);
        }
        
        return ans;
    }
};