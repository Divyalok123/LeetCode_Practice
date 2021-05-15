/*
https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0, odd = 0, even = 0, last = 0;
        for(int i = 0; i < arr.size(); i++) {
            
            arr[i] += last;
            last = arr[i];
            
            if(arr[i]&1)
                ans += even + 1, odd++;
            else
                ans += odd, even++;
        }
        
        return ans%1000000007;
    }
};