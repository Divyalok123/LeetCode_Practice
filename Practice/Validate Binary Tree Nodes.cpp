/*
https://leetcode.com/problems/validate-binary-tree-nodes/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

//dfs
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> check;
    bool dfs(int i, int& count, vector<int>& leftChild, vector<int>& rightChild) {
        if(check[i] == 0) return false;
        
        check[i] = 0;
        count++;
        
        if(leftChild[i] != -1) {
            if(dfs(leftChild[i], count, leftChild, rightChild) == 0)
                return false;
        }
        
        if(rightChild[i] != -1) {
            if(dfs(rightChild[i], count, leftChild, rightChild) == 0)
                return false;
        }
        
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        check.resize(n, 0);
        int count = 0;
        for(auto& i: leftChild) {
            if(i != -1) {
                if(check[i]) return false;
                check[i] = 1, count++;
            }
        }
        
        for(auto& i: rightChild) {
            if(i != -1) {
                if(check[i]) return false;
                check[i] = 1, count++;
            }
        }
        
        if(count != n-1) return false;
        
        count = 0;
        for(int i = 0; i < n; i++) {
            if(check[i] == 0) {
                check[i] = 1;
                if(dfs(i, count, leftChild, rightChild) == 0)
                    return false;
                break;
            }
        }

        
        return count == n;
    }
};

// bfs
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> check(n);
        int count = 0;
        for(auto& i: leftChild) {
            if(i != -1) {
                if(check[i]) return false;
                check[i] = 1, count++;
            }
        }
        
        for(auto& i: rightChild) {
            if(i != -1) {
                if(check[i]) return false;
                check[i] = 1, count++;
            }
        }
        
        if(count != n-1) return false;
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(check[i] == 0) {
                q.push(i);
                check[i] = 1;
                break;
            }
        }

        count = 0;
        while(q.size()) {
            int f = q.front();
            q.pop();
            
            if(check[f] == 0) return false;
            
            count++;
            check[f] = 0;
            if(leftChild[f] != -1)
                q.push(leftChild[f]);
            if(rightChild[f] != -1)
                q.push(rightChild[f]);
        }
        
        return count == n;
    }
};

//union-find
class Solution {
public:
    vector<int> parent, rank;
    
    int find(int a) {
        return a == parent[a] ? a : parent[a] = find(parent[a]);
    }
    
    void un(int a, int b) {
        int pa = find(a), pb = find(b);
        if(pa == pb) return;
        
        int ra = rank[pa], rb = rank[pb];
        if(ra > rb)
            swap(pa, pb);
    
        parent[pa] = pb;
        if(ra == rb)
            rank[pa]++;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n), rank.resize(n);
        iota(parent.begin(), parent.end(), 0);
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1 && find(leftChild[i]) != leftChild[i]) return false;
            if(rightChild[i] != -1 && find(rightChild[i]) != rightChild[i]) return false; 
            if(find(i) == leftChild[i] || find(i) == rightChild[i]) return false;
            
            if(leftChild[i] != -1)
                un(leftChild[i], i), count++;

            if(rightChild[i] != -1)
                un(rightChild[i], i), count++;
        }
        
        return count == n-1;
    }
};