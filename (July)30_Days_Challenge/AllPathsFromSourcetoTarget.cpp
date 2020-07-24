/*
Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
*/

#include <iostream>
#include <vector>
using namespace std;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution
{

    void dfs(vector<vector<int>> &g, int n, int c, vector<int> &t, vector<vector<int>> &o)
    {
        if (c == n - 1)
        {
            o.push_back(t);
            return;
        }

        for (auto a : g[c])
        {
            t.push_back(a);
            dfs(g, n, a, t, o);
            t.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> o;
        int n = graph.size();
        vector<int> t(1, 0);
        dfs(graph, n, 0, t, o);
        return o;
    }
};