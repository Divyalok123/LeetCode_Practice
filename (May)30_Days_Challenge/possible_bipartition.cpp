// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
// Each person may dislike some other people, and they should not go into the same group.
// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
// Return true if and only if it is possible to split everyone into two groups in this way.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//Approach 3 (using sets) (without graph)


//Approach 2 (Graph Coloring) *DFS*
class Solution {
    
public:
    
    bool dfs(vector<vector<int>>& adjlist, vector<int>& coloring, int node, int color)
    {
        if(coloring[node] != -1)
            return coloring[node] == color;
        coloring[node] = color;
        for(auto ele: adjlist[node])
        {            
            if(!dfs(adjlist, coloring, ele, 1 - color))
                    return false;
        }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> coloring(N+1, -1);
        
        vector<vector<int>> adjlist(N+1);
        for(int i = 0; i < dislikes.size(); i++)
        {
            adjlist[dislikes[i][0]].push_back(dislikes[i][1]);
            adjlist[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for(int i = 1; i <= N; i++)
        {
            if(coloring[i] == -1 && !dfs(adjlist, coloring, i, 1))
                return false;
        }
        
        return true;
    }
};


//Approach 1 (Graph coloring) *BFS*
class Solution
{
public:
    bool isBipartitionPossible(vector<vector<int>> &adjacencyList, int curr, vector<int> &coloring)
    {
        queue<int> elements;
        elements.push(curr);
        coloring[curr] = 1;

        while (!elements.empty())
        {
            int frontElement = elements.front();
            elements.pop();

            for (auto innerElement : adjacencyList[frontElement])
            {
                if (coloring[frontElement] == coloring[innerElement])
                {
                    return false;
                }

                if (coloring[innerElement] == -1)
                {
                    coloring[innerElement] = 1 - coloring[frontElement];
                    elements.push(innerElement);
                }
            }
        }

        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> adjacencyList(N + 1);
        for (int i = 0; i < dislikes.size(); i++)
        {
            adjacencyList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjacencyList[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> coloring(N + 1, -1);
        for (int i = 1; i <= N; i++)
        {
            if (coloring[i] == -1)
            {
                if (!isBipartitionPossible(adjacencyList, i, coloring))
                    return false;
            }
        }

        return true;
    }
};

/*
First try (using sets) (didn't pass) 
!!Bad code ahead!!

Approach: Make a 2D array to mark the guys we can't put together
Make two sets to store the two groups. Whike putting them check: can we
put it in set1? if yes then put and continue else try putting in set2
if we can't put in either of them that means bipartition is not possible

*/
class Solution
{
    int arr[2001][2001];

public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        if (dislikes.size() == 0)
            return true;

        memset(arr, 0, sizeof(arr));
        unordered_set<int> set1;
        unordered_set<int> set2;

        for (int i = 0; i < dislikes.size(); i++)
        {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            arr[a - 1][b - 1] = 1;
            arr[b - 1][a - 1] = 1;
        }

        set1.insert(1);
        for (int i = 2; i <= N; i++)
        {
            int count = 0;
            for (auto x : set1)
            {
                if (arr[x - 1][i - 1] || arr[i - 1][x - 1])
                {
                    count = 1;
                    break;
                }
            }
            if (count == 0)
            {
                set1.insert(i);
                continue;
            }
            for (auto y : set2)
            {
                if (arr[y - 1][i - 1] || arr[i - 1][y - 1])
                {
                    count = 2;
                    break;
                }
            }
            if (count == 2)
                return false;
            set2.insert(i);
        }

        return true;
    }
};
