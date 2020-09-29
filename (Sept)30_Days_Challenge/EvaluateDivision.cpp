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
class Solution
{
    unordered_map<string, string> parent;
    unordered_map<string, double> values;

    string finder(string a)
    {
        string s;
        if (parent.find(a) != parent.end())
            s = parent[a];
        else
            s = a;

        if (s != a)
        {
            string x = finder(s);
            values[a] = values[a] * values[s];
            parent[a] = x;
        }

        return parent.find(a) == parent.end() ? a : parent[a];
    }

    void add(string a)
    {
        if (parent.find(a) != parent.end())
            return;
        parent[a] = a;
        values[a] = 1.0;
    }

    void unionof(string &a, string &b, double val)
    {
        add(a);
        add(b);

        string parentofa = finder(a);
        string parentofb = finder(b);

        parent[parentofa] = parentofb;
        values[parentofa] = (val * values[b] / values[a]);
    }

public:
    vector<double> calcEquation(vector<vector<string>> &e, vector<double> &v, vector<vector<string>> &q)
    {
        if (q.size() == 0)
            return {};
        vector<double> ans(q.size());

        for (int i = 0; i < v.size(); i++)
            unionof(e[i][0], e[i][1], v[i]);

        for (int i = 0; i < q.size(); i++)
            ans[i] = ((parent.find(q[i][0]) != parent.end()) && (parent.find(q[i][1]) != parent.end()) && (finder(q[i][0]) == finder(q[i][1]))) ? (values[q[i][0]] / values[q[i][1]]) : -1.0;
        return ans;
    }
};

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