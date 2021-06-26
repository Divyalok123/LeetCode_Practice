/*
https://leetcode.com/problems/largest-merge-of-two-strings/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string ans(n+m, '-');
        
        int i = 0, j = 0, k = 0;
        int check = -1;
        while(i < n || j < m) {
            if(i < n ^ j < m)
                ans[k++] = (i < n ? word1[i++] : word2[j++]);
            else if(word1[i] == word2[j]) {
                if(check != -1) 
                    ans[k++] = check ? word1[i++] : word2[j++];
                else {
                    int l = i, r = j;
                    while(l < n && r < m && word1[l] == word2[r])
                        l++, r++;
                    
                    if(l == n)
                        check = 0;
                    else if(r == m)
                        check = 1;
                    else
                        check = word1[l] > word2[r];
                }
            } else if(word1[i] < word2[j]) 
                ans[k++] = word2[j++], check = -1;
            else
                ans[k++] = word1[i++], check = -1;
        }
        
        return ans;
    }
};