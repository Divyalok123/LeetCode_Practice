/*
You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.
*/

#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int ts = tasks.size();
        vector<int> m(26, 0);
        int maxim = 0;
        for (auto a : tasks)
        {
            m[a - 'A']++;
            if (m[a - 'A'] > maxim)
                maxim = m[a - 'A'];
        }

        int s = 0;
        for (auto a : m)
        {
            if (a == maxim)
                s++;
        }

        int ans = maxim + (n) * (maxim - 1) + s - 1;
        if (ans < tasks.size())
            return tasks.size();
        return ans;
    }
};