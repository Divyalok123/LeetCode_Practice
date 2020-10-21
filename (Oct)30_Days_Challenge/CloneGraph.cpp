/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3501/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/* Solution 2 (DFS) */
class Solution
{
    unordered_map<Node *, Node *> mm;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;

        Node *ans = new Node(node->val, {});
        ans->neighbors.resize(node->neighbors.size());
        mm[node] = ans;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (mm.find(node->neighbors[i]) == mm.end())
            {
                mm[node->neighbors[i]] = cloneGraph(node->neighbors[i]);
            }
            ans->neighbors[i] = mm[node->neighbors[i]];
        }
        return ans;
    }
};

/* Solution 1 (BFS) */
class Solution
{
    unordered_map<Node *, Node *> mm;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;

        Node *ans = new Node(node->val, {});
        mm[node] = ans;
        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *f = q.front();
            q.pop();

            Node *n = mm[f];
            n->neighbors.resize(f->neighbors.size());
            for (int i = 0; i < f->neighbors.size(); i++)
            {
                if (mm.find(f->neighbors[i]) == mm.end())
                {
                    Node *newn = new Node(f->neighbors[i]->val, {});
                    mm[f->neighbors[i]] = newn;
                    q.push(f->neighbors[i]);
                }

                n->neighbors[i] = mm[f->neighbors[i]];
            }
        }

        return ans;
    }
};