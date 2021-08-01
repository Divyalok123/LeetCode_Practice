/*
https://leetcode.com/problems/minimum-genetic-mutation/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

// two ended bfs
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> sett(bank.begin(), bank.end());
        if(sett.count(end) == 0) return -1;
        unordered_set<string> front, back, *ref1, *ref2;
        vector<char> poss = {'A', 'C', 'G', 'T'};
        front.insert(start);
        back.insert(end);
        
        int len = 0;
        while(front.size() && back.size()) {
            
            if(front.size() <= back.size()) {
                ref1 = &front;
                ref2 = &back;
            } else {
                ref1 = &back;
                ref2 = &front;
            }
            
            unordered_set<string> newset;
            
            for(string s: *ref1) {
                for(int i = 0; i < 8; i++) {
                    char c = s[i];
                    for(char x: poss) {
                        if(x != c) {
                            s[i] = x;
                            if(ref2->count(s)) return len+1;
                            if(sett.count(s)) {
                                newset.insert(s);
                                sett.erase(s);
                            }
                        }
                    }
                    s[i] = c;
                }
            }
            
            *ref1 = newset;
            len++;
        }
        
        return -1;
    }
};

// simple bfs
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> ss(bank.begin(), bank.end());

        queue<string> q;
        unordered_set<string> vis;
        vector<char> poss = {'A', 'C', 'G', 'T'};
        q.push(start);
        
        int len = 0;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                string f = q.front();
                q.pop();
                
                if(f == end) 
                    return len;
                    
                for(int i = 0; i < 8; i++) {
                    char c = f[i];
                    
                    for(char x: poss) {
                        if(c != x) {
                            f[i] = x;
                            if(vis.count(f) || ss.count(f) == 0) 
                                continue;
                            q.push(f);
                            vis.insert(f);
                        }
                    }
                    
                    f[i] = c;
                }
                
            }
            
            len++;
        }
        
        return -1;
    }
};