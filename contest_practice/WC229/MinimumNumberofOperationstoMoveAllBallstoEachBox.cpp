/*
https://leetcode.com/contest/weekly-contest-229/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++) {
            int val = 0;
            int j = i-1, k = i+1;
            while(j >= 0) {
                if(boxes[j] == '1') val += i-j;
                j--;
            }
            
            while(k < n) {
                if(boxes[k] == '1') val += k-i;
                k++;
            }
            
            ans[i] = val;
        }
        
        return ans;
    }
};