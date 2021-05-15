/*
https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    
    int fls(string& s) {
        vector<int> count(26);
        for(char& c: s)
            count[c-'a']++;

        for(int& j: count)
            if(j) return j;
        
        return -1;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> vals(n);
        
        for(int i = 0; i < n; i++) 
            vals[i] = fls(words[i]);
        
        sort(vals.begin(), vals.end());
        
        // for(int& i: vals)
        //     cout << i <<  " ";
        // cout << endl;
        
        int m = queries.size();
        vector<int> ans(m);
        
        for(int i = 0; i < m; i++) {
            int val = fls(queries[i]);
            auto ind = upper_bound(vals.begin(), vals.end(), val);
            ans[i] = vals.end()-ind;
        }
        
        return ans;
    }
};