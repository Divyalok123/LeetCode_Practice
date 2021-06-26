/*
https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// O(n) time - O(n) space - super Awesome (for ref: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623747/JavaC%2B%2BPython-One-Pass-O(N4)-to-O(N))
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, xorr = 0;
        unordered_map<int, int> um, total;
        um[0] = 1;
        for(int i = 0; i < n; i++) {
            xorr ^= arr[i];
            ans += um[xorr]*i - total[xorr];
            um[xorr]++;
            total[xorr] += i+1;
        }
        
        return ans;
    }
};

// O(n^2) time - O(1) space
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, xorr = 0;
        for(int i = 0; i < n; i++) {
            xorr = 0;
            for(int j = i; j < n; j++) 
            {
                xorr ^= arr[j];
                if(xorr == 0)
                    ans += j-i;
            }
        }
        
        return ans;
    }
};

// O(n^3) time - O(1) space
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, xor1 = 0, xor2 = 0;
        for(int i = 0; i < n-1; i++) {
            xor1 = 0;
            for(int j = i+1; j < n; j++) {
                xor1 ^= arr[j-1];
                xor2 = 0;
                for(int k = j; k < n; k++) {
                    xor2 ^= arr[k];
                    if(xor2 == xor1)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};