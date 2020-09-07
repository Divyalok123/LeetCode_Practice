/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3450/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//solution 2
class Solution
{
public:
    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        unordered_map<int, int> um;
        int n = A.size(), ai = 0, bi = 0, i, j;
        vector<int> a(n * n), b(n * n);
        for (i = 0; i < n * n; i++)
            if (A[i / n][i % n])
                a[ai++] = i / n * 100 + i % n;
        for (j = 0; j < n * n; j++)
            if (B[j / n][j % n])
                b[bi++] = j / n * 100 + j % n;

        for (i = 0; i < ai; i++)
            for (j = 0; j < bi; j++)
                um[a[i] - b[j]]++;

        int ans = 0;
        for (auto x : um)
            ans = max(ans, x.second);

        return ans;
    }
};

//solution 1
class Solution
{
    int maxval = 0;
    int count;

public:
    void iterate(vector<vector<int>> &v1, vector<vector<int>> &v2, int a, int b, int s)
    {
        count = 0;
        int i, j;
        for (i = 0; i < s; i++)
            for (j = 0; j < s; j++)
                if (v1[i][j] && v2[a + i][b + j])
                    count++;
        maxval = max(maxval, count);
    }

    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {

        int size = A.size();
        vector<vector<int>> v(3 * size - 2, vector<int>(3 * size - 2, 0));

        int i, j;
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                v[i + size - 1][j + size - 1] = A[i][j];

        for (i = 0; i < 2 * size - 1; i++)
            for (j = 0; j < 2 * size - 1; j++)
                iterate(B, v, i, j, size);

        return maxval;
    }
};