/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 2 (Merge Sort)
class Solution {
public:
    vector<int> ans, index;
    void merge(vector<int>& v, int s, int m, int e) {
        if(s > e) return;
        vector<int> temp(e-s+1);
        int l = s, r = m+1;
        int k = 0, c = 0;
        
        while(l <= m && r <= e) {
            if(v[index[l]] <= v[index[r]]) {
                temp[k++] = index[l];
                ans[index[l++]] += c;
            } else {
                temp[k++] = index[r++];
                c++;                
            }
        } 
        
        while(l <= m) {
            temp[k++] = index[l];
            ans[index[l++]] += c;
        }
        
        while(r <= e)
            temp[k++] = index[r++];
        
        for(int i = s; i <= e; i++)
            index[i] = temp[i-s];
    }
    
    void mergeSort(vector<int>& v, int s, int e) {
        if(s >= e) return;
        int m = s + (e-s)/2;
        mergeSort(v, s, m);
        mergeSort(v, m+1, e);
        merge(v, s, m, e);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        
        index.resize(n);
        for(int i = 0; i <= n-1; i++)
            index[i] = i;

        mergeSort(nums, 0, n-1);
        return ans;
    }
};

// Solution 1 (BITree)
class Solution {
    vector<int> bitree;
public:
    void update(int ind) {
        while(ind <= 20001) {
            bitree[ind]+=1;
            ind += ind&-ind;
        }
    }    
    
    int query(int ind) {
        int ans = 0;
        while(ind) {
            ans += bitree[ind];
            ind -= ind&-ind;
        }
        return ans;
    } 
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        bitree.resize(20003);
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--) {
            nums[i] += 10001;
            ans[i] = query(nums[i]-1);
            update(nums[i]);
        }
        return ans;
    }
};

