/*
https://leetcode.com/problems/exclusive-time-of-functions/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        vector<int> top;
        int last = -1;
        for(string& log: logs) {
            int id = 0, i = 0, n = log.size();
            
            while(log[i] != ':')
                id *= 10, id += log[i++]-'0';
            
            bool start = false;
            i++;
            if(log[i] == 's') start = true;
            
            while(log[i] != ':') i++;
            
            i++;
            
            int timestamp = 0;
            while(i < n)
                timestamp *= 10, timestamp += log[i++]-'0';
            
            if(start) {
                if(top.size()) ans[top.back()] += timestamp - last; 
                top.push_back(id);
            } else {
                ans[top.back()] += timestamp - last + 1;
                top.pop_back();
            }     
            
            last = timestamp + (!start);
        }
        
        return ans;
    }
};