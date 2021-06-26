/*
https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// improved
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int ps = puzzles.size(),
            ws = words.size();
        
        vector<int> ans(ps);
        unordered_map<int, int> nwords;
        
        for(int i = 0; i < ws; i++) {
            int val = 0;
            for(int j = 0; j < words[i].size(); j++)
                val |= (1 << (words[i][j]-'a'));

            nwords[val]++;
        }
        
        for(int i = 0; i < ps; i++) {
            int val = 0;
            for(int j = 0; j < 7; j++)
                val |= (1 << (puzzles[i][j]-'a'));
            
            int count = 0, mask = val, check = 1 << (puzzles[i][0]-'a');
            
            //all submasks of val
            while(val >= check) {
                if(val & check)
                    count += nwords[val];
                val = (val-1)&mask;
            }
            
            ans[i] = count;            
        }
        
        return ans;        
    }
};

//bitmask + hashmap
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int ps = puzzles.size(),
            ws = words.size();
        
        vector<int> ans(ps);
        vector<unordered_map<int, int>> nwords(26);
        
        for(int i = 0; i < ws; i++) {
            int val = 0;
            for(int j = 0; j < words[i].size(); j++)
                val |= (1 << (words[i][j]-'a'));

            for(int j = 25, bit = 1 << 25; j >= 0; j--, bit >>= 1)
                if(val & bit) {
                    nwords[j][val]++;
                }
        }
        
        for(int i = 0; i < ps; i++) {
            int val = 0;
            for(int j = 0; j < puzzles[i].size(); j++)
                val |= (1 << (puzzles[i][j]-'a'));
            
            auto& um = nwords[puzzles[i][0]-'a'];
            int count = 0, mask = val;
            
            //all submasks of val
            count += um[val];
            while(val) {
                val = (val-1) & mask;
                count += um[val];
            }
            
            ans[i] = count;            
        }
        
        return ans;        
    }
};
