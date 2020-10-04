/*
https://leetcode.com/problems/delete-columns-to-make-sorted/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size() == 1)
            return 0;
        int count = 0;
        for(int i = 0; i < A[0].size(); i++)
        {
            for(int j = 0; j < A.size()-1; j++)
            {
                if(A[j][i] > A[j+1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};