// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

// Return the intersection of these two interval lists.

// (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> output;
        int i = 0; 
        int j = 0;
        while(i < A.size() && j < B.size())
        {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);
            if(A[i][1] < B[j][0]) i++;
            else if(B[j][1] < A[i][0]) j++;
            else
            {
                output.push_back({start, end});
                if(A[i][1] < B[j][1]) i++;
                else j++;
            }
        }
        
        return output;
    }
};