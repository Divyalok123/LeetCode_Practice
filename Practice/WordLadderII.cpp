/*
https://leetcode.com/problems/word-ladder-ii/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

// Solution 2 (BFS + DFS) 


// Solution 1 (Simple BFS)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            
        int n = wordList.size();
        int ws = wordList[0].size();
        unordered_set<string> sset(wordList.begin(),wordList.end());

        vector<vector<string>> ans;
        if(sset.find(endWord) == sset.end()) return ans;
        
        queue<vector<string>> q;
        q.push({beginWord});
        
        bool found = 0;
        while(q.size()) {
            int sz = q.size();
            unordered_set<string> vis;
            while(sz--) {
                vector<string> f = q.front();
                q.pop();
                string curr = f.back();
                for(int i = 0; i < ws; i++) {
                    char c = curr[i];
                    for(int j = 0; j < 26; j++) {
                        curr[i] = 'a' + j;

                        if(sset.find(curr) != sset.end()) {
                            f.push_back(curr);
                            q.push(f);
                            vis.insert(curr);
                        
                            if(curr == endWord) {
                                found = 1;
                                ans.push_back(f);
                            }
                            
                            f.pop_back(); 
                        }
                    }
                    curr[i] = c;
                }
            }
            
            if(found) break;
            for(auto& j: vis) {
                sset.erase(j);
                auto itr = sset.find(j);
                if(itr != sset.end()) 
                    sset.erase(itr);
            }
        }
        
        return ans;
    }
};  
