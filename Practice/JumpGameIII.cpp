/*
https://leetcode.com/problems/jump-game-iii/submissions/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        // cout << "start: " << start << endl;
        if ((start < 0) || (start >= arr.size()) || (arr[start] == -1))
            return false;
        if (arr[start] == 0)
        {
            return true;
        }
        int val = arr[start];
        arr[start] = -1;
        return canReach(arr, start - val) || canReach(arr, start + val);
    }
};