/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3609/
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/* Solution 2 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 1;
        int fi = 0, fj = 0;
        
        for(int i = 0; i < n; i++) {
            int r = i;
            while(r < n-1 && s[r] == s[r+1])
                r++;
                
            int l = i;
            while(l > 0 && r < n-1 && s[l-1] == s[r+1]) {
                l--;
                r++;
            }
            
            if(ans < r-l+1) {
                ans = r-l+1;
                fi = l;
                fj = r;
            }
        }
        
        // cout << "ans: " << ans << endl;
        return s.substr(fi, fj-fi+1);
    }
};

/* Solution 1 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 1;
        int fi = 0, fj = 0;
        
        vector<vector<bool>> v(n, vector<bool>(n));
        for(int i = n; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(j == i) {
                    v[i][j] = 1;
                } else if(abs(j-i) == 1) {
                    v[i][j] = (s[i] == s[j]);
                    if(v[i][j] && ans < 2) {
                        ans = 2;
                        fi = i;
                        fj = j;
                    }
                } else {
                    v[i][j] = (s[i] == s[j] && v[i+1][j-1]);
                    if(v[i][j] && ans < j-i+1) {
                        ans = j-i+1;
                        fi = i;
                        fj = j;
                    }
                }
            }
        }
        
        // cout << "ans: " << ans << endl;
        return s.substr(fi, fj-fi+1);
    }
};