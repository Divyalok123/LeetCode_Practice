/*
https://leetcode.com/problems/shuffle-an-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    vector<int> originalarray;
    vector<int> permutablearray;

public:
    Solution(vector<int> &nums)
    {
        originalarray = nums;
        permutablearray = nums;
        srand(time(0));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        permutablearray = originalarray;
        return permutablearray;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = 0; i < permutablearray.size(); i++)
            swap(permutablearray[i], permutablearray[rand() % (i + 1)]);
        return permutablearray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */