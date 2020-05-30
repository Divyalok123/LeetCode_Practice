// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// (Here, the distance between two points on a plane is the Euclidean distance.)
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <iterator>

using namespace std;
//Solution 4(using multiset)
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        multiset<vector<int>, comparator> setway(points.begin(), points.end());
        vector<vector<int>> result;
        copy_n(setway.begin(), K, back_inserter(result));
        return result;
    }

private:
    class comparator
    {
    public:
        bool operator()(const vector<int> &a, const vector<int> &b) const
        {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
};

//Solution 3(using priority_queue)
class comparator
{
public:
    bool operator()(vector<int> const &a, vector<int> const &b)
    {
        return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        priority_queue<vector<int>, vector<vector<int>>, comparator> pqueue(points.begin(), points.end());
        vector<vector<int>> result;
        for (int i = 0; i < K; i++)
        {
            result.push_back(pqueue.top());
            pqueue.pop();
        }
        return result;
    }
};

//Solution 2(using partial_sort) /*fast but slow if K is large */
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        partial_sort(points.begin(), points.begin() + K, points.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });

        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

//Solution 1(using nth_element) /*faster*/
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        nth_element(points.begin(), points.begin() + K, points.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });

        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
