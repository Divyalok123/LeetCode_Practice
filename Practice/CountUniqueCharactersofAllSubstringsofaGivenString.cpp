/*
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define MOD 1000000007
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<int> left(n), right(n);
        
        vector<int> v(26, -1);
        for(int i = 0; i < n; i++) {
            left[i] = v[s[i]-'A'];
            v[s[i]-'A'] = i;                
        }
        
        v.assign(26, n);
        for(int i = n-1; i >= 0; i--) {
            right[i] = v[s[i]-'A'];
            v[s[i]-'A'] = i;
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) 
            ans = (ans + 1ll*(i-left[i])*(right[i]-i))%MOD;
        
        return ans;
    }
};