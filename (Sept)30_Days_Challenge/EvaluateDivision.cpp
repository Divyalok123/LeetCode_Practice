/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/557/week-4-september-22nd-september-28th/3474/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* --- Method 2 (DSU)--- */


/* --- Method 1 (DFS)--- */
class Solution
{
public:
    unordered_map<string, double> umap;
    using vvs = vector<vector<string>>;
    vector<vector<pair<int, double>>> v;
    vector<bool> visited;
    double dfs(int start, int end, double ans)
    {
        if (visited[start])
            return -1;
        if (start == end)
            return ans;
        visited[start] = true;
        double check = 0;
        for (int l = 0; l < v[start].size(); l++)
        {
            check = 0;
            check = dfs(v[start][l].first, end, ans * (v[start][l].second));
            if (check != 0)
            {
                if (check == -1)
                    continue;
                break;
            }
        }

        return check;
    }

    vector<double> calcEquation(vvs &eq, vector<double> &values, vvs &qu)
    {
        int i = 1;
        for (auto &a : eq)
        {
            if (umap[a[0]] == 0)
                umap[a[0]] = i++;

            if (umap[a[1]] == 0)
                umap[a[1]] = i++;
        }

        v.resize(i);
        for (int l = 0; l < eq.size(); l++)
        {
            v[umap[eq[l][0]]].push_back(make_pair(umap[eq[l][1]], values[l]));
            v[umap[eq[l][1]]].push_back(make_pair(umap[eq[l][0]], 1 / values[l]));
        }

        vector<double> ans(qu.size());
        visited.resize(i);
        for (int l = 0; l < qu.size(); l++)
        {
            visited.assign(i, false);
            if (umap[qu[l][0]] == 0 || umap[qu[l][1]] == 0)
            {
                ans[l] = -1;
            }
            else
            {
                ans[l] = dfs(umap[qu[l][0]], umap[qu[l][1]], 1);
            }
        }

        return ans;
    }
};