/*
https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int maxScore(vector<int>& cc, int k) {
        int ans = 0, n = cc.size();
        for(int i = 0; i < k; i++)
            ans += cc[i];
        
        if(n == k)
            return ans;
        
        int fans = ans;
        for(int i = n-1, j = k-1; j >= 0; j--, i--) {
            ans -= cc[j];
            ans += cc[i];
            
            if(ans > fans)
                fans = ans;
        }
        return fans;
    }
};
