/*
    Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

static int x = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorv = 0;
        for(int a: nums)
            xorv ^= a;
        
        xorv &= -xorv;
        
        int elem1 = 0, elem2 = 0;
        for(int a: nums)
        {
            if((xorv & a) == 0)
                elem1 ^= a;
            else
                elem2 ^= a;
        }
        
        return {elem1, elem2};
    }
};