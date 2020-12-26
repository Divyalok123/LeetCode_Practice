/*
https://leetcode.com/problems/custom-sort-string/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

/* Solution 2 */
class Solution {
public:
    string customSortString(string S, string T) {
        sort(T.begin(), T.end(), [&S](char& a, char& b) { return S.find(a) < S.find(b); });
        return T;
    }
};

/* Solution 1 */
class Solution {
public:
    string customSortString(string S, string T) {
        
        unordered_map<char, int> umap;
        unordered_map<int, char> st;
        unordered_map<int, int> sumap;
        
        int val = 1;
        for(int i = 0; i < S.size(); i++) {
            st[val] = S[i];
            umap[S[i]] = val++;
        }
        
        vector<int> vv(26);
        for(char& c: T) {
            if(umap[c])
                sumap[umap[c]]++;
            else vv[c-'a']++;
        }
        
        int i = 0;
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < vv[j]; k++)
                T[i++] = 'a'+j;
        
        for(int j = 1; j < val; j++)
            for(int k = 0; k < sumap[j]; k++)
                T[i++] = st[j];
        
        return T;
    }
};