/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3492/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() == 0 || B.size() == 0)
            return false;
        
        if(A.size() != B.size())
            return false;
        
        int c, b1[26] = {0}, b2[26] = {0};
        string s1, s2;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] != B[i])
                s1.push_back(A[i]), s2.push_back(B[i]);
            else
            {
                c = A[i]-'a';
                if(b1[c] == 1)
                    s1.push_back(A[i]), s2.push_back(B[i]), b1[c]++, b2[c]++;
                else if(b1[c] == 0)
                    b1[c] = 1, b2[c] = 1;
            }
        }
    
        if(s1.size()==0)
            return false;
        
        if(s1.size()==1)
            return s1[0] == s2[0];
        
        if(s1 == s2)
            return true;
        
        string news1, news2;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != s2[i])
                news1.push_back(s1[i]), news2.push_back(s2[i]);
        }
        
        if(news1.size() != 2)
            return false;
        news1[0] ^= news1[1] ^= news1[0] ^= news1[1];
        return news1 == news2;
    }
};