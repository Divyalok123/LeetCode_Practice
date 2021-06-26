/*
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0, mask = 1 << 30;
        for(int i = 30; i >= 0; i--) {
            if(mask & c) {
                if((a&mask) == 0 && (b&mask) == 0)
                    ans++;
            } else {
                ans += (a&mask) > 0;
                ans += (b&mask) > 0;
            }
            
            mask >>= 1;
        }
        
        return ans;
    }
};