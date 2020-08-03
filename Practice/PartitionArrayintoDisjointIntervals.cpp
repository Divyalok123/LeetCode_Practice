/* https://leetcode.com/problems/partition-array-into-disjoint-intervals/ */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        
        if(A.size() == 2) return 1;
        int n = A.size();
        vector<int> one(n), two(n);
        
        int left_max = INT_MIN;
        for(int i = 0; i < A.size(); i++)
        {
            left_max = max(left_max, A[i]);
            one[i] = left_max;
        }
        
        int right_min = INT_MAX;
        for(int i = A.size()-1; i >= 0; i--)
        {
            right_min = min(A[i], right_min);
            two[i] = right_min;
        }
        
        int i = 0;
        while(i < A.size()-1 && one[i] > two[i+1])
            i++;
        
        return i+1;
    }
};