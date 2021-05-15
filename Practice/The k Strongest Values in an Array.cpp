/*
https://leetcode.com/problems/the-k-strongest-values-in-an-array/
*/

#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
using namespace std;

//as the order is not important we can use 
//nth_element instead of sort
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        nth_element(arr.begin(), arr.begin()+(n-1)/2, arr.end());
        int med = arr[(n-1)/2];
        
        nth_element(arr.begin(), arr.begin()+k, arr.end(), [&med](int& a, int& b){
            int xa = abs(med-a);
            int xb = abs(med-b);
            return xa > xb || (xa == xb && a > b);
        });        
        
        arr.resize(k);
        return arr;
    }
};

//improving solution 1 (don't need extra space)
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int med = arr[(n-1)/2];
        
        sort(arr.begin(), arr.end(), [&med](const int& a, const int& b){
            int xa = abs(med-a);
            int xb = abs(med-b);
            return xa > xb || (xa == xb && a > b);
        });
        
        arr.resize(k);
        return arr;
    }
};

//simple solution (nlogn)
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int med = arr[(n-1)/2];
        
        vector<array<int, 2>> v(n);
        for(int i = 0; i < n; i++)
            v[i] = {abs(med-arr[i]), arr[i]};
        
        sort(v.begin(), v.end(), [](const array<int, 2>& a, const array<int, 2>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
            ans[i] = v[i][1];
        return ans;
    }
};