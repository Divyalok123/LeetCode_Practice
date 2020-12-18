/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/571/week-3-december-15th-december-21st/3570/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define lmax LLONG_MAX

static int fio = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        ll lo = lmax, mi = lmax;
        int i = 0;
        
        for(int& n: nums) {
            if(n <= lo) lo = n;
            else if(n <= mi) mi = n;
            else return 1;
        }
        
        return 0;
    }
};