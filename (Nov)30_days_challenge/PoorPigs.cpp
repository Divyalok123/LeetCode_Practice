/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3530/
*/

#include <iostream>
using namespace std;

/* Solution 1*/
class Solution {
public:
    int poorPigs(int buckets, int md, int mt) {
        int ans = log(buckets)/log(mt/md + 1);
        if(ans < (log(buckets)/log(mt/md + 1))) ans++;
        return ans;
    }
};