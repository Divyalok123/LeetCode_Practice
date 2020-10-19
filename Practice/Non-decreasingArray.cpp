/*
https://leetcode.com/problems/non-decreasing-array/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        int n = v.size();
        if(n == 1)
            return true;
    
        int i = 0, val = -100005;
        while(i < n-1 && v[i] <= v[i+1])
            val = v[i], i++;
        
        if(i == n-1)
            return 1;
        
        if(val <= v[i+1]) v[i] = v[i+1];
        else v[i+1] = v[i];
        
        if(v[i] < val) {
            // cout << "val: " << val << " v[" << i << "]: " << v[i] << endl; 
            return false;
        }
        
        val = v[i];
        i++;
       
        while(i < n-1 && v[i] <= v[i+1])
            i++;
    
        return i==(n-1);
    }
};