/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
using namespace std;

//  Priority queue + MergeSort solution - O(klogk)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(m*n < k)
            k = m*n;

        vector<vector<int>> ans(k);
        using temp = array<int, 3>;
        
        class compare {
          public:
            bool operator()(const temp& a, const temp& b){
                return a[0]+a[1] > b[0]+b[1];
            }
        };
        
        priority_queue<temp, vector<temp>, compare> pq;
        for(int i = 0; i < n; i++)
            pq.push({nums1[i], nums2[0], 0});
        
        int count = 0, start = 0;        
        while(count < k) {
            auto top = pq.top();
            pq.pop();
            
            int nums1val = top[0], nums2val = top[1], nums2ind = top[2];
            ans[count++] = {nums1val, nums2val};
            
            if(nums2ind < m-1) {
                pq.push({nums1val, nums2[nums2ind+1], nums2ind+1});
            }
        }
        
        return ans;
    }
};

// Merge sort solution - O(k^2)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(m*n < k)
            k = m*n;
        
        vector<int> ind(n);
        vector<vector<int>> ans(k);
        
        int count = 0, start = 0;        
        while(count < k) {
            int minval = INT_MAX;
            array<int, 2> minind = {-1, -1};
            for(int i = start; i < n; i++) {
                if(nums2[ind[i]] + nums1[i] < minval)
                    minval = nums2[ind[i]] + nums1[i], minind = {i, ind[i]};
            }
            
            ans[count++] = {nums1[minind[0]], nums2[minind[1]]};
            ind[minind[0]]++;
            
            if(ind[minind[0]] == m)
                start++;
        }
        
        return ans;
    }
};

// Naive solution - O(k^2log(k^2))
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        using temp = array<int, 2>;
        
        class compare {
          public:
            bool operator()(const temp& a, const temp& b){
                return a[0]+a[1] > b[0]+b[1];
            }
        };
        
        priority_queue<temp, vector<temp>, compare> pq;
        
        for(int i = 0; i < min(k, n); i++) 
            for(int j = 0; j < min(k, m); j++) 
                pq.push({nums1[i], nums2[j]});
        
        
        vector<vector<int>> ans(min(m*n, k));
        
        int i = 0;
        while(i < k && pq.size()) {
            ans[i++] = {pq.top()[0], pq.top()[1]};
            pq.pop();
        }
        
        return ans;
    }
};