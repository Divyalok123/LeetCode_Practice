/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

/* Solution 3 (Tree) */
class Solution {
    int MAXV;
    vector<int> bit;
public:
    
    void update(int v, int ind) {
        while(ind < MAXV) {
            bit[ind] = max(bit[ind], v);
            ind += ind&-ind;
        }
    }
    
    int query(int ind) {
        int ans = 0;
        while(ind > 0) {
            ans = max(ans, bit[ind]);
            ind -= ind&-ind;
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        
        MAXV = n+1;
        bit.resize(MAXV);
        
        set<int> s;
        unordered_map<int, int> m;
        
        for(int& i: nums)
            s.insert(i);
        
        int ind = 0;
        for(int i: s) 
            m[i] = ++ind;
        
        for(int i = 0; i < n; i++)
            nums[i] = m[nums[i]];
        
        cout << "NUMS" << endl;
        for(int i: nums)
            cout << i << " ";
        cout << endl;
        
        int ans = 1;
        for(int i = 0; i < n; i++) {
            int v = query(nums[i]-1);
            v++;
            update(v, nums[i]);
        }
        
        ans = max(ans, query(n));
        return ans;
    }
};

/* Solution 2 (Binary Search) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int ans = 1;
        vector<int> dp(n);
        int ind = 0;
        for(int& el: nums) {
            int m, i = 0, j = ind;
            while(i < j) {
                m = (i + j)/2;
                if(dp[m] < el)
                    i = m+1;
                else
                    j = m;
            }
            
            dp[i] = el;
            if(i == ind)
                ind++;
        }
        
        return ind;
    }
};

/* Solution 1 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int ans = 1;
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            int j = i-1;
            while(j >= 0) {
                if(nums[j] < nums[i]) {
                    if(dp[j]+1 > dp[i])
                        dp[i] = dp[j]+1;
                }
                j--;
            }
            
            if(dp[i] > ans)
                ans = dp[i];
        }
        
        return ans;
    }
};