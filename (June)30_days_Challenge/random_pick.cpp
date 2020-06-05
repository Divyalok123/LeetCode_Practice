// Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.
// Note:
// 1 <= w.length <= 10000
// 1 <= w[i] <= 10^5
// pickIndex will be called at most 10000 times.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    vector<int> prob;
    int size;

public:
    Solution(vector<int> &w)
    {
        size = w.size();
        prob.assign(size, 0);

        for (int i = 0; i < size; i++)
        {
            prob[i] = i == 0 ? w[i] : prob[i - 1] + w[i];
        }
    }

    int pickIndex()
    {
        int random = rand() % prob[size - 1] + 1; // remove one when using upper_bound
        auto ind = lower_bound(prob.begin(), prob.end(), random);
        // auto ind = upper_bound(prob.begin(), prob.end(), random);
        return ind - prob.begin();
    }
};