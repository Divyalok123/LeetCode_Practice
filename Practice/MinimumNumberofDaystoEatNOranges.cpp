/*
https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> umap;
    int minDays(int n) {
        if(n <= 1) return 1;
        if(umap[n] != 0) return umap[n];
        return umap[n] = 1 + min(n%2 + minDays(n/2), n%3 + minDays(n/3));
    }
};