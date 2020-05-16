// Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

// Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

// Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) { 
        int minsum = A[0], maxsum = A[0], total = A[0], currmax = A[0], currmin = A[0];
        for(int i = 1; i < A.size(); i++)
        {
            currmax = max(A[i], currmax+A[i]);
            maxsum = max(maxsum, currmax);
            currmin = min(A[i], currmin+A[i]);
            minsum = min(minsum, currmin);
            total += A[i];
        }
        
        if(total == minsum) return maxsum;
        else return max(maxsum, total-minsum);
    }
        
};
    
// int len = A.size();
//     int ans = A[0];
//     int curr = A[0];
//     for(int i = 1; i < len; i++)
//     {
//         if(count == 0) 
//         {
//             count = 100;
//             i = 0;
//         }
//         cout << "Entering" << endl;
//         curr = max(A[i], curr+A[i]);
//         cout << "Curr " << curr << endl;
//         ans = max(ans, curr);
//         cout << "Ans " << ans << endl;
//         if(i == A.size()-1 && count == 1)
//         {
//             curr = A[len-1];
//             i = 0;
//             count = 0;
//             len -= 1;
//         }
//     }

//     return ans;


