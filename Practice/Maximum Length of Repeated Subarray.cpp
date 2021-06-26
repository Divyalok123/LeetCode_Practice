/*
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Rabin Karp Hashing - O(NlogN) time solution
class Solution {
public:
    int MOD;
    int power(int a, int b) {
        int ans = 1;
        while(b) {
            if(b&1)
                ans = (ans*1ll*a)%MOD;
            a = (a*1ll*a)%MOD;
            b >>= 1;
        }
        
        return ans;
    }
    
    bool check(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        unordered_set<int> ss;
        long long p = 19941229, poww = power(p, k-1);
        
        int hash = 0;
        for(int i = 0; i < n; i++) {
            if(i >= k) 
                hash = (hash - poww*1ll*a[i-k] + MOD)%MOD;
            hash = (hash*1ll*p + a[i])%MOD;
            if(i >= k-1)
                ss.insert(hash);
        }
        
        hash = 0;
        for(int i = 0; i < m; i++) {
            if(i >= k)
                hash = (hash - poww*1ll*b[i-k] + MOD)%MOD;
            hash = (hash*1ll*p + b[i])%MOD;
            if(i >= k-1 && ss.find(hash) != ss.end())
                    return true;
        }
        
        return false;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        MOD = 1000000007;
        
        int l = 1, r = min(n, m), ans = 0;
        while(l <= r) {
            int mid = (l + r)/2;
            
            if(check(nums1, nums2, mid)) 
                ans = mid, l = mid+1;
            else
                r = mid-1;
        }
        
        return ans;        
    }
};

// Further space improvement - O(1) space
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0, k = i; j < m && k < n; j++, k++) {
                if(nums1[k] == nums2[j]) {
                    count++;
                    if(ans < count) 
                        ans = count;
                } else 
                    count = 0;
            }
        }
        
        for(int i = 0; i < m; i++) {
            int count = 0;
            for(int j = 0, k = i; j < n && k < m; j++, k++) {
                if(nums1[j] == nums2[k]) {
                    count++;
                    if(ans < count)
                        ans = count;
                } else 
                    count = 0;
            }
        }
        
        return ans;        
    }
};

// Improved space - O(m)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int dp[2][m+1];
        memset(dp[0], 0, sizeof(dp[0]));
        dp[1][0] = 0;
        
        int ans = 0, r = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[r][j] = dp[1-r][j-1] + 1;
                    if(ans < dp[r][j]) 
                        ans = dp[r][j];
                } else
                    dp[r][j] = 0;
            }
            
            r = 1-r;
        }
        
        return ans;        
    }
};

// simple bottom-up dp - Time: O(n*m) - Space: O(n*m)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int dp[n+1][m+1];
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 0;
        
        for(int i = 0; i <= m; i++)
            dp[0][i] = 0;
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(ans < dp[i][j]) 
                        ans = dp[i][j];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;        
    }
};