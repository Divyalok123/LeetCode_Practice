/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3561/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        
        int i = 1;
        while(i < n && arr[i] > arr[i-1])
            i++;
        
        if(i == n || i == 1) return 0;
        
        while(i < n && arr[i] < arr[i-1])
            i++;
        
        return i == n;
    }
};