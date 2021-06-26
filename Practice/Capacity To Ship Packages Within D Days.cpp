/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:

    bool possible(vector<int>& weights, int days, int m) {
        int n = weights.size(), i = 0, d = 0;
        
        while(i < n && d < days) {
            // cout << "i: " << i << endl;
            int w = 0;
            while(i < n && w + weights[i] <= m)
                w += weights[i++];
            d++;
        }
        
        return i == n;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = 1;
        for(int& i: weights)
            r += i;
        
        while(l < r) {
            int m = l + (r-l)/2;
            // cout << "m: " << m << endl;
            if(possible(weights, days, m)) 
                r = m;
            else
                l = m+1;
        }
        
        return l;
    }
};