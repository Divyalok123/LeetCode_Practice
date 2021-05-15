/*
https://leetcode.com/problems/queries-on-a-permutation-with-key/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BIT solution
class Solution {
    vector<int> BIT;
    int MAX;
public:
    
    void update(int i, int val) {
        while(i < MAX) {
            BIT[i] += val;
            i += i&(-i);
        }
    }
    
    int query(int i) {
        int val = 0;
        while(i > 0) {
            val += BIT[i];
            i -= i&(-i);
        }
        return val;
    }
    
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        MAX = n+m+1;
        BIT.resize(MAX);
        
        vector<int> ans(n);
        unordered_map<int, int> ind;
        for(int i = 1; i <= m; i++) {
            ind[i] = i+n;
            update(i+n, 1);
        }
        
        int i = 0;
        for(int q: queries) {
            int indexOfq = ind[q];
            ans[i++] = query(indexOfq)-1;
            update(indexOfq, -1);
            update(n, 1);
            ind[q] = n;
            n--;
        }
        
        return ans;
    }
};

// naive solution
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> v(m);
        for(int i = 0; i < m; i++)
            v[i] = i+1;
        
        vector<int> ans(queries.size());
        int k = 0;
        for(int& i: queries) {
            auto index = find(v.begin(), v.end(), i);
            ans[k++] = index-v.begin();
            v.erase(index);
            v.insert(v.begin(), i);
        }
        
        return ans;
    }
};