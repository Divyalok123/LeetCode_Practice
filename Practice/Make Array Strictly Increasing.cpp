/*
https://leetcode.com/problems/make-array-strictly-increasing/
*/

#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//bottom-up - O(mn)
class Solution {
public:
	int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		if (arr1.size() == 1) return 0;
		
		sort(arr2.begin(), arr2.end());
		arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

		int m = arr1.size(), n = arr2.size();
		
		vector<vector<int>> f(m, vector<int>(n, INT_MAX));
		vector<int> g(m, INT_MAX);

		for (int i = 0; i < n; i++)
			f[0][i] = 1;
		g[0] = 0; 

		for (int i = 1; i < m; i++) {
            if (arr1[i] > arr1[i - 1])
				g[i] = g[i - 1];
            
			for (int j = 0; j < n; j++) {
				if (arr2[j] > arr1[i - 1])
					f[i][j] = min(g[i - 1], INT_MAX - 1) + 1;

                if (j > 0)
					f[i][j] = min(f[i][j], min(f[i - 1][j - 1], INT_MAX - 1) + 1);
                
                if (arr2[j] < arr1[i])
					g[i] = min(g[i], f[i - 1][j]);
			}
		}
		
		int ans = min(g[m - 1], *min_element(f[m - 1].begin(), f[m - 1].end()));
		return ans == INT_MAX ? -1 : ans;
	}
};

// bottom-up - O(n^2logm)
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        
        int n = arr1.size(), m = arr2.size();
        
        int dp[n+1][n+1];
        fill_n(*dp, sizeof dp / sizeof **dp, INT_MAX);
        
        dp[0][0] = -1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= i; j++) {
                
                // cout << "i: " << i << " j: " << j << endl;
                if(arr1[i-1] > dp[j][i-1])
                    dp[j][i] = arr1[i-1];
                
                // cout << "dpval: " << dp[j][i] << endl;
                if(j > 0) {
                    int ind = upper_bound(arr2.begin(), arr2.end(), dp[j-1][i-1]) - arr2.begin();
                    
                    if(ind != m)    
                        dp[j][i] = min(dp[j][i], arr2[ind]);
                }
                
                // cout << "dpval: " << dp[j][i] << endl;
                if(i == n && dp[j][i] != INT_MAX)
                    return j;
            }
        }
        
        return -1;
    }
};

// top-down with memo - O(mnlogm)
class Solution {
public:
    #define MAX 1e9
    int n, m;
    vector<vector<int>> cache;

    int dfs(vector<int>& arr1, vector<int>& arr2, int i, int j, int prev) {
        if(i >= n) 
            return 0;
        
        j = upper_bound(arr2.begin() + j, arr2.end(), prev)-arr2.begin();
        
        if(j >= m && arr1[i] <= prev)
            return MAX;
            
        if(cache[i][j] != -1)
            return cache[i][j];
        
        int a = MAX, b = MAX;
        if(arr1[i] > prev)
            a = dfs(arr1, arr2, i+1, j, arr1[i]);
        
        if(j < m)
            b = 1 + dfs(arr1, arr2, i+1, j, arr2[j]);
        
        return cache[i][j] = min(a, b);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        
        n = arr1.size(), m = arr2.size();
        cache.resize(n + 1, vector<int>(m + 1, -1));
        int ans = dfs(arr1, arr2, 0, 0, -1);
        
        return ans >= MAX ? -1 : ans;
    }
};


