/* https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/ */

#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

static int x = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if(n == 0) return true;
        
        int i = 0, j = n-1;
        while(i < j) {
            while(i < n && !isalnum(s[i])) i++;
            while(i < n && !isalnum(s[j])) j--;
            if(i >= j) break;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};