/*
https://leetcode.com/problems/water-and-jug-problem/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <queue>
using namespace std;

// GCD (Bezout's Identity: there exits numbers x and y such that a*x + b*y == gcd(a, b), 
//                         so we just take the gcd and check if target is divisible by gcd 
//                         that means target is achievable by using some quantities of both a and b)
class Solution {
public:
    bool canMeasureWater(int j1C, int j2C, int target) {
        if(j1C + j2C < target) return 0;
        if(j1C+j2C == target || j1C == target || j2C == target) return 1;
        if((j1C & 1) == 0 && (j2C & 1) == 0 && (target & 1)) return 0;
        
        return target % (__gcd(j1C, j2C)) == 0;
    }
};

// BFS : accepted
class Solution
{
public:
    bool canMeasureWater(int j1C, int j2C, int target)
    {
        if (j1C + j2C == target)
            return 1;

        queue<array<int, 2>> q;
        unordered_map<int, unordered_map<int, int>> um;
        q.push({0, 0});

        while (q.size())
        {
            auto front = q.front();
            q.pop();

            int a = front[0], b = front[1];
            if (a + b == target || a == target || b == target)
                return 1;

            um[a][b] = 1;

            if (um[j1C][b] == 0)
                q.push({j1C, b});

            if (um[a][j2C] == 0)
                q.push({a, j2C});

            if (um[0][b] == 0)
                q.push({0, b});

            if (um[a][0] == 0)
                q.push({a, 0});

            if (a + b <= j2C && um[0][a + b] == 0)
                q.push({0, a + b});

            if (a + b <= j1C && um[a + b][0] == 0)
                q.push({a + b, 0});

            if (a + b > j2C && um[a - (j2C - b)][j2C] == 0)
                q.push({a - (j2C - b), j2C});

            if (a + b > j1C && um[j1C][b - (j1C - a)] == 0)
                q.push({j1C, b - (j1C - a)});
        }

        return 0;
    }
};

// DFS : TLE
class Solution
{
public:
    vector<vector<int>> cache;
    unordered_map<int, unordered_map<int, int>> um;
    bool dfs(int j1, int j2, int j1C, int j2C, int target)
    {
        if (j1 == target || j2 == target || j1 + j2 == target)
            return 1;

        if (cache[j1][j2] != -1)
            return cache[j1][j2];
        um[j1][j2] = 1;
        bool ans = 0;
        if (um[j1C][j2] == 0)
            ans |= dfs(j1C, j2, j1C, j2C, target);

        if (um[j1][j2C] == 0)
            ans |= dfs(j1, j2C, j1C, j2C, target);

        if (um[0][j2] == 0)
            ans |= dfs(0, j2, j1C, j2C, target);

        if (um[j1][0] == 0)
            ans |= dfs(j1, 0, j1C, j2C, target);

        if (j1 + j2 <= j2C && um[0][j1 + j2] == 0)
            ans |= dfs(0, j1 + j2, j1C, j2C, target);

        if (j1 + j2 <= j1C && um[j1 + j2][0] == 0)
            ans |= dfs(j1 + j2, 0, j1C, j2C, target);

        if (j1 + j2 > j2C && um[j1 - (j2C - j2)][j2C] == 0)
            ans |= dfs(j1 - (j2C - j2), j2C, j1C, j2C, target);

        if (j1 + j2 > j1C && um[j1C][j2 - (j1C - j1)] == 0)
            ans |= dfs(j1C, j2 - (j1C - j1), j1C, j2C, target);

        return cache[j1][j2] = ans;
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        if (jug1Capacity + jug2Capacity == targetCapacity)
            return 1;
        cache.resize(jug1Capacity + 1, vector<int>(jug2Capacity + 1, -1));
        return dfs(0, 0, jug1Capacity, jug2Capacity, targetCapacity);
    }
};