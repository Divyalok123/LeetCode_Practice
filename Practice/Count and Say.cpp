/*
https://leetcode.com/problems/count-and-say/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static vector<string> getall() {
        int n = 30;
        
        static vector<string> store(30);
        store[0] = "1";
        
        for(int i = 1; i < 30; i++) {
            string& curr = store[i-1];
            string& newstring = store[i];
            int j = 0, n = curr.size();

            while(j < n) {
                char v = curr[j], c = 0;
                while(j < n && curr[j] == v)
                    j++, c++;
                newstring += to_string(c);
                newstring.push_back(v);
            }
        }
        
        return store;
    }
    
    string countAndSay(int n) {
        static auto store = getall();
        return store[n-1];
    }
};