/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/560/week-2-october-8th-october-14th/3489/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
    //serialize helper
    void shelper(TreeNode *root, string &ans)
    {
        if (!root)
        {
            return;
        }

        int size;
        TreeNode *temp;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                temp = q.front();
                q.pop();

                if (temp)
                {
                    ans += to_string(temp->val) + ".";
                    if (temp->left)
                        q.push(temp->left);
                    else
                        q.push(NULL);

                    if (temp->right)
                        q.push(temp->right);
                    else
                        q.push(NULL);
                }
                else
                    ans += ".";
            }
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        shelper(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        string s = "";
        queue<TreeNode *> q;
        TreeNode *root, *temp;
        int i = 0, n = data.size(), ns, size;

        while (i < n && data[i] != '.')
            s.push_back(data[i++]);
        i++;

        stringstream ss(s);
        ss >> ns;
        root = new TreeNode(ns);

        q.push(root);

        while (!q.empty())
        {
            size = q.size();
            while (size--)
            {
                temp = q.front();
                q.pop();

                s = "";
                while (i < n && (data[i] != '.'))
                    s.push_back(data[i++]);
                i++;

                if (s != "")
                {
                    stringstream ss(s);
                    ss >> ns;
                    temp->left = new TreeNode(ns);
                    q.push(temp->left);
                }
                else
                {
                    temp->left = NULL;
                }

                s = "";
                while (i < n && (data[i] != '.'))
                    s.push_back(data[i++]);
                i++;

                if (s != "")
                {
                    stringstream ss(s);
                    ss >> ns;
                    temp->right = new TreeNode(ns);
                    q.push(temp->right);
                }
                else
                {
                    temp->right = NULL;
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;