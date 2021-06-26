/*
https://leetcode.com/problems/find-duplicate-file-in-system/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();

// simple brute 
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> store;
        
        for(auto& str: paths) {
            string dir = "";
            int i = 0, n = str.size();
    
            while(i < n && str[i] != ' ')
                dir += str[i++];
            
            string val, key;
            while(i < n) {
                if(str[i] == ' ') {
                    key = "", val = "";
                } else if(str[i] == '(') {
                    val = dir + "/" + key;
                    key = "";
                } else if(str[i] == ')') {
                    store[key].push_back(val);
                } else {
                    key += str[i];
                }
                i++;
            }
        }
        
        vector<vector<string>> ans;
        for(auto& [key, val]: store) {
            if(val.size() > 1)
                ans.emplace_back(val);
        }
        
        return ans;
    }
};