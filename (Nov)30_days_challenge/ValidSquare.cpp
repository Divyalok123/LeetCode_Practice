/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/565/week-2-november-8th-november-14th/3527/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 2 */
class Solution
{
public:
    int d(vector<int> &a, vector<int> &b)
    {
        int sum1 = a[0] - b[0];
        int sum2 = a[1] - b[1];
        return sum1 * sum1 + sum2 * sum2;
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<int> v(6);
        v[0] = d(p1, p2), v[1] = d(p1, p3), v[2] = d(p1, p4);
        v[3] = d(p2, p3), v[4] = d(p2, p4), v[5] = d(p3, p4);
        sort(v.begin(), v.end());
        return (v[0] > 0 && v[4] == v[5] && v[0] == v[3] && (v[0] < v[5]));
    }
};

/* Solution 1 */
class Solution
{
public:
    int d(vector<int> &a, vector<int> &b)
    {
        int sum1 = a[0] - b[0];
        int sum2 = a[1] - b[1];
        return sum1 * sum1 + sum2 * sum2;
    }

    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> v(4);
        v[0] = p1, v[1] = p2, v[2] = p3, v[3] = p4;
        sort(v.begin(), v.end());
        int s1 = d(v[0], v[1]), s2 = d(v[2], v[3]); // horizontal adjacent
        int s3 = d(v[1], v[3]), s4 = d(v[0], v[2]); //vertical adjacent
        int d1 = d(v[0], v[3]), d2 = d(v[1], v[2]); //diagonal
        return (s1 && s2 && s3 && s4 && s1 == s2 && s2 == s3 && s3 == s4) && (d1 == d2);
    }
};