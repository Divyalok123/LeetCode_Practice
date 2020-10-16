/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3497/
*/

#include <iostream>
#include <vector>
using namespace std;

//solution 2
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
            return false;

        int s = matrix[0].size();
        if (s == 0)
            return false;

        int i = n - 1, m, j = 0;
        while ((i >= 0) && (j <= s - 1))
        {
            m = matrix[i][j];
            if (m == target)
                return true;
            else if (m < target)
                j++;
            else
                i--;
        }

        return false;
    }
};

//solution 1
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        if (n == 0)
            return false;

        int s = matrix[0].size();
        if (s == 0)
            return false;

        int i = 0, m, j = n - 1;
        while (i <= j)
        {
            m = (i + j) / 2;
            if ((matrix[m][0] <= target) && (target <= matrix[m].back()))
            {
                int k = 0, mm, l = s - 1;
                while (k <= l)
                {
                    mm = (k + l) / 2;
                    if (matrix[m][mm] == target)
                        return true;
                    else if (matrix[m][mm] < target)
                        k = mm + 1;
                    else
                        l = mm - 1;
                }
                // cout << "here" << endl;
                return false;
            }
            else if (matrix[m][0] > target)
                j = m - 1;
            else
                i = m + 1;
        }

        return false;
    }
};