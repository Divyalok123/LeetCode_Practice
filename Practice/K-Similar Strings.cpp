/*
https://leetcode.com/problems/k-similar-strings/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.size();
        
        if(n == 1) return 0;
        
        int i = 0;
        while(i < n && s1[i] == s2[i]) i++;
        
        if(i == n) return 0;
        
        queue<pair<string, int>> q;
        unordered_set<string> vis;
        q.push({s1, i});
        vis.insert(s1);
        
        int ans = 0;
        while(q.size()) {
            int sz = q.size();
            bool check = false;
            bool anothercheck = false;
            while(sz--) {
                auto [str, ind] = q.front();
                q.pop();
                
                while(ind < n && str[ind] == s2[ind])
                    ind++;

                if(ind == n) {
                    check = 1;
                    break;
                }

                for(i = ind+1; i < n; i++) {
                    if(str[i] == s2[ind] && str[ind] != s2[ind]) {
                        swap(str[ind], str[i]);
                        
                        if(vis.count(str) == 0) {
                            q.push({str, ind+1});
                            vis.insert(str);
                        }
                        
                        swap(str[ind], str[i]);
                    }
                }
                
            }

            if(check) 
                break;
            ans++;
        }
        
        return ans;
    }
};