/*
https://leetcode.com/contest/weekly-contest-239/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minswaps(string& pre, string& num) {
        int n = pre.size();
        int i = 0, j = 0;
        int ans = 0;
        
        while(i < n) {
            j = i;
            while(pre[j] != num[i])
                j++;
            
            while(i < j) {
                swap(pre[j], pre[j-1]);
                j--;
                ans++;
            }
            i++;
        }
        return ans;
    }
    
    int getMinSwaps(string num, int k) {
        string prev = num;
        while(k--)
            next_permutation(num.begin(), num.end());
        
        return minswaps(prev, num);
    }
};