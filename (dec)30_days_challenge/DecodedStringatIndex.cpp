/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3572/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        if(K == 1) return S.substr(0, 1);

        long long i = 0, total = 0;
        while(i < S.size() && total < K) {
            if(isdigit(S[i]))
            {
                total *= (S[i]-'0');
            } else 
                total++;
            i++;
        }
        
        i--;
        while(i >= 0) {
            if(isdigit(S[i])) {
                total /= (S[i]-'0');
                K %= total;
            } else {
                if(K == 0 || K == total) //K==total -> this condition is for when we have done total-- consecutively
                    return S.substr(i, 1);
                total--;
            }
            i--;
        }
        
        return "I'mdumb";
    }
};