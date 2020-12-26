/*
https://leetcode.com/problems/rotate-string/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    void formlps(string& s, vector<int>& lps) {
        lps.resize(s.size());
        int i = 1, len = 0;
        while(i < s.size()) {
            if(s[i] == s[len])
                lps[i++] = ++len;
            else
            {
                if(len == 0)
                    lps[i++] = 0;
                else
                    len = lps[len-1];
            }
        }
    }
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return 0;
        vector<int> lps;
        formlps(B, lps);

        A += A;
        int i = 0, j = 0;
        while(i < A.size()) {
            if(B[j] == A[i]) {
                i++, j++;
                if(j == B.size()) return true;
            } else {
                if(j != 0) 
                    j = lps[j-1];
                else i++;
            }
        }
        return A == "";
    }
};