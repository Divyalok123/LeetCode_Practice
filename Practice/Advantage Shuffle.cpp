/*
https://leetcode.com/problems/advantage-shuffle/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

// shorter and better - O(nlogn)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        multiset<int> mul(A.begin(), A.end());
        
        for(int i = 0; i < n; i++) {
            auto ind = mul.upper_bound(B[i]);
            if(ind == mul.end())
                ind = mul.begin();
            A[i] = *ind;
            mul.erase(ind);
        }
        
        return A;
    }
};

//naive sorting based solution - O(nlogn)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        int n = A.size();
        vector<int> ans(n, -1);
        unordered_map<int, vector<int>> um;
        
        for(int i = 0; i < n; i++)
            um[B[i]].push_back(i);
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> store;
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(A[i] > B[j]) {
                vector<int>& ref = um[B[j]];
                int ind = ref.back();
                ref.pop_back();
                ans[ind] = A[i];
                j++;
            } else {
                store.push_back(A[i]);
            }
        }
        
        for(int i = 0; i < n; i++) 
            if(ans[i] == -1) {
                ans[i] = store.back();
                store.pop_back();
            }
        
        return ans;
    }
};