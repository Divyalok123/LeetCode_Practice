#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    class trienode {
        public:
        int count;
        trienode* node[2] = {};
        
        trienode() {
            count = 0;
            // for(int i = 0; i < 2; i++)
                // node[i] = NULL;
        }
    };
    
    int maxbits = 17;
    
    void insert(int n, trienode* t) {
        trienode* curr = t;
        for(int i = maxbits; i >= 0; i--) {
            int v = (n>>i)&1;
            
            if(!curr->node[v])
                curr->node[v] = new trienode();
            
            curr->node[v]->count+=1;
            curr = curr->node[v];
        }
    }
    
    int countless(trienode* tree, int n, int lim) {
        trienode* curr = tree;
        int ans = 0;
        for(int i = maxbits; i >= 0 && curr; i--) {
            int nbit = (n>>i)&1;
            int lbit = (lim>>i)&1;
            
            if(lbit == 0) {
                curr = curr->node[nbit];
                continue;
            }
            
            if(curr->node[nbit])
                ans += curr->node[nbit]->count;
            
            curr = curr->node[1-nbit];
        }
        
        return ans;
    }
    
    int countPairs(vector<int>& nums, int low, int high) {
        int ans = 0;
        trienode* tree = new trienode();
        for(int i = 0; i < nums.size(); i++) {
            ans += countless(tree, nums[i], high+1)-countless(tree, nums[i], low);
            insert(nums[i], tree);
        }
        
        return ans;
    }
};