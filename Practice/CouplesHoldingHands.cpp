/*
https://leetcode.com/problems/couples-holding-hands/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n), part(n);
        
        for(int i = 0; i < n; i++) {
            pos[row[i]] = i;
            part[i] = i&1 ? i-1 : i+1;
        }
        
        int ans = 0, next, ind;
        for(int i = 0; i < n; i+=2) {
            next = i+1;
            if(row[next] != part[row[i]])
            {
                ans++;
                ind = pos[part[row[i]]];
                pos[row[ind]] = i+1;
                pos[row[next]] = ind;
                swap(row[ind], row[next]);
            }
        }
        
        return ans;        
    }
};