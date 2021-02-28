/*
https://leetcode.com/problems/number-of-digit-one/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        long div = 1;
        int ans = 0;
        for(long i = 1; i <= n; i *= 10) {
            div = i*10;
            ans += n/div * i;
            
            if(i == 1)
                ans += n%div != 0;
            else
                ans += min(max(0l, n%div - i + 1), i);
            // cout << "ans: " << ans << endl;
        }
        return ans;
    }
};