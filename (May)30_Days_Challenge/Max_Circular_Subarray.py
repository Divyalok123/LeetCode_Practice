# Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

# Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

# Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

# import math
List: [2, 3, 4, -1, 2, 4]


class Solution:
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        total = A[0]
        minsum = A[0]
        maxsum = A[0]
        currmax = A[0]
        currmin = A[0]
        for i in range(1, len(A)):
            currmax = max(A[i], currmax + A[i])
            maxsum = max(maxsum, currmax)
            currmin = min(A[i], currmin + A[i])
            minsum = min(minsum, currmin)
            total += A[i]
        if(total == minsum):
            return maxsum
        else:
            return max(total-minsum, maxsum)
