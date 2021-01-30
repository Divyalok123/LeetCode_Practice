/*
https://leetcode.com/problems/reverse-pairs/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* Solution 2 */
class Solution {
public:
    
    int merge(vector<int>& nums, int i, int m, int j) {
        vector<int> temp(j-i+1);
        int k = 0, c = 0, l = i, r = m+1;
        int finalcount = 0;
        while(l <= m) {
            while(r <= j && nums[l] > 2l*nums[r])
                r++, c++;
            finalcount += c;
            l++;
        }
        
        l = i, r = m+1;
        while(l <= m && r <= j) {
            if(nums[l] <= nums[r])
                temp[k++] = nums[l++];
            else
                temp[k++] = nums[r++];
        }
        
        while(l <= m)
            temp[k++] = nums[l++];
        
        while(r <= j)
            temp[k++] = nums[r++];
        
        for(l = i; l <= j; l++)
            nums[l] = temp[l-i];
        
        return finalcount;
    }
    
    int mergeSort(vector<int>& nums, int i, int j) {
        if(i >= j) return 0;
        
        int m = i + (j-i)/2;
        int ans = 0;
        ans += mergeSort(nums, i, m);
        ans += mergeSort(nums, m+1, j);
        return ans + merge(nums, i, m, j);
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

/* Solution 1 */
class Solution {
    vector<int> bitree;
    int maxn;
public:
    
    void update(int ind) {
        while(ind<=maxn) {
            bitree[ind]++;
            ind += ind&-ind;
        }
    }
    
    int query(int ind) {
        int ans = 0;
        while(ind > 0) {
            ans += bitree[ind];
            ind -= ind&-ind;
        }
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), j=0;
        vector<long> temp(2*n);
        
        for(int i = 0; i < n; i++) {
            temp[j++] = nums[i];
            temp[j++] = nums[i]*2l;
        }
        
        sort(temp.begin(), temp.end());
        
        unordered_map<long, int> um;
        int r = 1;
        for(auto& i: temp)
            um[i] = r++;
        
        maxn = temp.size();
        bitree.resize(maxn+1);
        
        int ans = 0;
        for(int i = n-1; i >= 0; i--) {
            ans += query(um[nums[i]]-1);
            update(um[2l*nums[i]]);
        }
        
        return ans;
    }
};

