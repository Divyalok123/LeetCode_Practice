/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3439/
*/

#include <iostream>
#include <cmath>
using namespace std;
int rand7();//predefined 

//solution 2
class Solution {
public:
    int rand10() {
        int val;
        while(1) {
            val = rand7()+(rand7()-1)*7;
            if(val <= 40)
                return (val-1)%10 + 1;
            
            val = (val-40 - 1)*7 + rand7();
            if(val <= 60)
                return (val-1)%10 + 1;
            
            val = (val-60 - 1)*7 + rand7();
            if(val <= 20)
                return (val-1)%10 + 1;
        }
    }
};

//solution 1
class Solution {
public:
    int rand10() {
        int ans = rand7() + (rand7()-1)*7;
        while(ans > 40)
            ans = rand7() + (rand7()-1)*7;
        return (ans-1)%10+1;        
    }
};