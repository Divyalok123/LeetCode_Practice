/*
https://leetcode.com/problems/maximum-ice-cream-bars/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sorting - O(nlogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int i = 0, n = costs.size();
        sort(costs.begin(), costs.end());
        
        while(i < n && coins >= costs[i])
            coins -= costs[i++];
        
        return i;
    }
};