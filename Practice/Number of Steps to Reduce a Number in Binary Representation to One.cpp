/*
https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// counting operation if odd and even
class Solution {
public:
    int numSteps(string s) {
        int ans = 0, n = s.size(), carry = 0;
        for(int i = n-1; i > 0; i--) {
            if((s[i]-'0') + carry == 1)
                carry = 1, ans += 2;
            else
                ans += 1;
        }
        
        return ans+carry;
    }
};

// naive brute force
class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size() > 1) {
            if(s.back() == '0')
                s.pop_back();
            else {

                int n = s.size()-1;
                while(n >= 0 && s[n] == '1')
                    s[n--] = '0';
                
                if(n == -1) 
                    s.insert(s.begin(), '1');
                else 
                    s[n] = '1';
            }

            ans++;
        }
        
        return ans;
    }
};