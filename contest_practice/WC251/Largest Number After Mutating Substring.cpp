/*
https://leetcode.com/contest/weekly-contest-251/problems/largest-number-after-mutating-substring/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int ind = -1, i = 0, n = num.size();
        
        while(i < n && change[num[i]-'0'] <= num[i]-'0') i++;
        
        if(i == n) return num;
        
        while(i < n && change[num[i]-'0'] >= num[i]-'0') {
            num[i] = '0' + change[num[i]-'0'];
            i++;
        }
        
        
        return num;
    }
};