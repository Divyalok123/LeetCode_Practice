# Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

# Return the intersection of these two interval lists.

# (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans = []
        i = 0
        j = 0
        while(i < len(A) and j < len(B)):
            start = max(A[i][0], B[j][0])
            end = min(A[i][1], B[j][1])
            if(A[i][1] < B[j][0]):
                i+=1
            elif(B[j][1] < A[i][0]):
                j+=1
            else:
                ans.append([start, end])
                if(A[i][1] < B[j][1]):
                    i+=1
                else: 
                    j+=1
        return ans