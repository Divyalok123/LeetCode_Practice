/*
https://leetcode.com/contest/weekly-contest-251/problems/delete-duplicate-folders-in-system/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    class Node {
    public:
        unordered_map<string, Node*> children;
        string val;
        bool isEnd;
        bool isCleared;
        Node(): isEnd(false), isCleared(false) {}
        Node(const string& s): val(s), isEnd(false), isCleared(false) {}
    };
    
    unordered_map<string, int> store;
    string counter(Node* root) {
        if(!root) return "";
        
        string hash;
        for(auto& nex: root->children) {
            string temphash = counter(nex.second);
            temphash += nex.first;
            hash += "#" + temphash;
        }
        
        // cout << "In collect | hash: " << hash << endl;
        
        if(hash.size())
            store[hash]++;
        return hash;
    }
    
    string destroy(Node* root) {
        if(!root) return "";
        
        string hash;
        for(auto& nex: root->children) {
            string temphash = destroy(nex.second);
            temphash += nex.first;
            hash += "#" + temphash;
        }
        
        if(store[hash] > 1) {
            // cout << "In destroy | hash: " << hash << " removing: " << root->val << endl;
            root->isCleared = true;
        }
        
        return hash;
    }
    
    void collect(Node* root, vector<string>& temp, vector<vector<string>>& ans) {
        if(!root) return;
        if(root->isCleared) return;
        
        if(root->children.size() == 0) {
            if(temp.size())
                ans.push_back(temp);
            return;
        }
        
        if(root->isEnd)
            ans.push_back(temp);
        
        for(auto& nex: root->children) {
            temp.push_back(nex.first);
            collect(nex.second, temp, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("\\");
        
        for(auto& path: paths) {
            Node* temp = root;
            for(auto& val: path) {
                if(temp->children[val] == NULL)
                    temp->children[val] = new Node(val);
                temp = temp->children[val];
            }
            temp->isEnd = true;
        }
        
        counter(root);
        destroy(root);
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        collect(root, temp, ans);
        
        return ans;
    }
};