/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3431/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int even = 0;
        for(int i = 0; i < A.size(); i++)
            if((A[i]&1) == 0)
                swap(A[i], A[even++]);
        return A;
    }
};