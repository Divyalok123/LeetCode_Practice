/*
https://leetcode.com/problems/greatest-sum-divisible-by-three/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Mathematical O(n) solution
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0;
        
        int one1, one2, two1, two2;
        one1 = one2 = two1 = two2 = INT_MAX;
        for(int& i: nums) {
            int val = i%3;
            if(val == 0)
                ans += i;
            else if(val == 1) {
                sum += i;
                if(i < one1) {
                    one2 = one1;
                    one1 = i;
                } else if(i < one2)
                    one2 = i;
            } else {
                sum += i;
                if(i < two1) {
                    two2 = two1;
                    two1 = i;
                } else if(i < two2)
                    two2 = i;
            }
        }
        
        int toremove = INT_MAX;
        if(sum%3 == 1) {
            if(one1 != INT_MAX) toremove = min(toremove, one1);
            if(two2 != INT_MAX) toremove = min(toremove, two2 + two1);
        } else if(sum%3 == 2) {
            if(two1 != INT_MAX) toremove = min(toremove, two1);
            if(one2 != INT_MAX) toremove = min(toremove, one1 + one2);
        }
        
        return ans + sum - (toremove == INT_MAX ? 0 : toremove);
    }
};

// Improving to O(1) space
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(3);
        cache[1] = -100000000;
        cache[2] = -100000000;
        for(int i = 1; i <= n; i++) {
            vector<int> prev = cache;
            for(int j = 0; j < 3; j++) {
                cache[j] = max(prev[j], nums[i-1] + prev[(nums[i-1] + j)%3]);
            }
        }
        
        return cache[0];
    }
};

// bottom-up dp - O(n) time, O(n) space
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cache(n+1, vector<int>(3, 0));
        cache[0][1] = -100000000;
        cache[0][2] = -100000000;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                cache[i][j] = max(cache[i-1][j], nums[i-1] + cache[i-1][(nums[i-1] + j)%3]);
            }
        }
        
        return cache[n][0];
    }
};

// top-down dp - O(n) time, O(n) space
class Solution {
public:
    vector<vector<int>> cache;
    int dpfunc(vector<int>& vec, int i, int j) {
        if(i == vec.size())
            return j%3 ? -1000000 : 0;
        
        int& ans = cache[i][j%3];
        if(ans != -1000000)
            return ans;

        ans = dpfunc(vec, i+1, j);
        ans = vec[i] + dpfunc(vec, i+1, j+vec[i]);
        return ans = max(a, b);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        cache.resize(n, vector<int>(3, -1000000));
        return dpfunc(nums, 0, 0);
    }
};

// to understand the working of this ^ code
class Solution {
public:
    vector<vector<int>> cache;
    
    void printcache() {
        cout << "--- Cache ---" << endl;
        for(auto& i: cache) {
            for(auto& j: i)
                cout << j << " ";
            cout << endl;
        }
    }
    
    int dpfunc(vector<int>& vec, int i, int j) {
        cout << "i: " << i << " j: " << j << endl;
        if(i == vec.size())
            return j%3 ? -1000000 : 0;
        
        cout << "1" << endl;
        int& ans = cache[i][j%3];
        if(ans != -1000000)
            return ans;

        cout << "2" << endl;
        int a = dpfunc(vec, i+1, j);
        cout << "i: " << i << " j: " << j << " a: " << a << endl;
        
        int b = vec[i] + dpfunc(vec, i+1, j+vec[i]);
        cout << "i: " << i << " j: " << j << " b: " << b << " b without adding: " << b-vec[i] << endl;
        
        printcache();
        return ans = max(a, b);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        cache.resize(n, vector<int>(3, -1000000));
        int ans = dpfunc(nums, 0, 0);
        return ans;
    }
};