/*
https://leetcode.com/problems/find-k-closest-elements/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Improving two pointers - Binary Search - O(logn + k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int i = 0, j = n-k;
        while(i < j) {
            int m = (i + j)/2;
            if(x-arr[m] <= arr[m+k]-x)
                j = m;
            else
                i = m+1;
        }
        
        vector<int> ans(k);
        for(int m = i; m < i+k; m++)
            ans[m-i] = arr[m];
        
        return ans;
    }
};

// Two Pointers - Time: O(n), Space: O(1)
class Solution {
public:
    int abss(int a, int b) {
        return a-b < 0 ? -1*(a-b) : a-b;    
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int i = 0, j = n-1;
        while(j-i >= k) {
            if(abss(arr[i], x) > abss(arr[j], x))
                i++;
            else
                j--;
        }
        
        vector<int> ans(k);
        for(int m = i; m <= j; m++)
            ans[m-i] = arr[m];
        
        return ans;
    }
};

// Prefix Sum - Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        vector<int> pre(n+1);
        for(int i = 1; i <= n; i++)
            pre[i] = abs(arr[i-1]-x);
        
        for(int i = 1; i <= n; i++) 
            pre[i] += pre[i-1];
        
        int ind = -1, minv = INT_MAX;
        
        for(int i = k-1; i < n; i++) {
            int val = pre[i+1]-pre[i+1-k]; 
            if(val < minv) {
                minv = val;
                ind = i;
            }
        }
        
        vector<int> ans(k);
        for(int i = ind-k+1, j = 0; i <= ind; i++, j++)
            ans[j] = arr[i];
        
        return ans;
    }
};

// Priority Queue - O(nlogn)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < n; i++) 
            pq.push({abs(x-arr[i]),i});
        
        vector<int> ans(k);
        int i = 0;
        while(i < k) {
            ans[i++] = arr[pq.top().second];
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
