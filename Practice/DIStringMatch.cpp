/*
https://leetcode.com/problems/di-string-match/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        if(S.size() == 0)
            return {};
        int i = 0, j = S.size();
        
        vector<int> v(S.size()+1);
        for(int k = 0; k < S.size(); k++)
        {
            if(S[k] == 'I')
                v[k] = i++;
            else 
                v[k] = j--;
        }
        
        v[S.size()] = i;
        return v;
    }
};