// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

//Solution 2 (BFS) (degree)
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        queue<int> q;
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses);
        for (auto i : prerequisites)
        {
            graph[i[1]].push_back(i[0]);
            degree[i[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (degree[i] == 0)
                q.push(i);
        }

        int num = 0;
        while (!q.empty())
        {
            int n = q.front();
            num++;
            q.pop();
            for (auto i : graph[n])
            {
                if (--degree[i] == 0)
                    q.push(i);
            }
        }
        return num == numCourses;
    }
};

//Solution 1 (DFS)
using namespace std;
class Solution
{
    bool visited[10000];
    bool recurstack[10000];
    bool circle = false;
    int visitedcount;

public:
    void dfs(vector<vector<int>> &graph, bool *visited, bool *recurstack, int node)
    {
        visited[node] = true;
        visitedcount++;
        recurstack[node] = true;

        for (auto neighbour : graph[node])
        {
            if (circle)
                return;
            else if (!visited[neighbour])
                dfs(graph, visited, recurstack, neighbour);
            else if (recurstack[neighbour])
                circle = true;
        }

        recurstack[node] = false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        memset(visited, false, sizeof(visited));
        memset(recurstack, false, sizeof(recurstack));
        visitedcount = 0;
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int source = prerequisites[i][0];
            int dest = prerequisites[i][1];
            graph[dest].push_back(source);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == false)
            {
                dfs(graph, visited, recurstack, i);
            }
        }

        if (circle)
            return false;

        if (visitedcount != numCourses)
            return false;

        return true;
    }
};
