/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3607/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/* Solution 2 */
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> v(5);
        int ans = 0;
        
        v[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 1; j < 5; j++) 
                v[j] += v[j-1];
        
        for(int& i: v)
            ans += i;
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    int helper(int n, int i) {
        if(i == 0 || n == 0) return 1;
        
        int ans = 0;
        for(int j = i; j >= 1; j--) {
            ans += helper(n-1, j);
        }
        
        return ans;
    }
    
    int countVowelStrings(int n) {
        return helper(n, 5);
    }
};