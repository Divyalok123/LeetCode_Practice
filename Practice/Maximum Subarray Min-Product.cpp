/*
https://leetcode.com/problems/maximum-subarray-min-product/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// stack - O(N)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    #define MOD 1000000007
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n+2);
        long long ans = 0;
        vector<int> s;
        
        for(int i = 0; i <= n; i++) {
            int val = i == n ? 0 : nums[i];
            prefix[i+1] = val + prefix[i];
            while(s.size() && nums[s.back()] >= val) {
                int t = nums[s.back()];
                s.pop_back();
                
                int first = s.size() ? s.back() + 1 : 0; 
                int last = i-1;
                
                ans = max(ans, t * 1ll * (prefix[last+1]-prefix[first]));
            }
            s.push_back(i);
        }        
        
        return ans % MOD;
    }
};

// sorting + binarySearch - O(NlogN)
class Solution {
public:
    #define MOD 1000000007
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> prefix(n+1);
        vector<array<int, 2>> vec(n);
        for(int i = 1; i <= n; i++) {
            prefix[i] = nums[i-1] + prefix[i-1];
            vec[i-1] = {nums[i-1], i-1};
        }
        
        sort(vec.begin(), vec.end());
        
        set<int> s({vec[0][1]});
        long long ans = vec[0][0] * prefix[n];
        
        int i = 1;
        while(i < n && vec[i][0] == vec[0][0])
            s.insert(vec[i++][1]);

        while(i < n) {
            int val = vec[i][0];
            vector<int> ss;
            while(i < n && vec[i][0] == val) {
                int ind = vec[i][1];
                auto itr = s.upper_bound(ind);
                
                int last = (itr == s.end() ? n-1 : *itr-1);
                int first = (itr == s.begin() ? 0 : *prev(itr)+1);
                ans = max(ans, val * 1ll * (prefix[last+1] - prefix[first]));
                ss.push_back(vec[i][1]);
                i++;
            }
            
            s.insert(ss.begin(), ss.end());
        }

        return ans % MOD;
    }
};