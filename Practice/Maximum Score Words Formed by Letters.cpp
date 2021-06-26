/*
https://leetcode.com/problems/maximum-score-words-formed-by-letters/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// using BIT manipulation
class Solution {
public:
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();
        vector<int> count(26);
        for(auto& l: letters)
            count[l-'a']++;
        
        // total combinations
        int total = 1 << n, ans = 0;
        for(int i = 0; i <= total; i++) {
            vector<int> countcopy = count;
            int thisscore = 0, mask = i;
            for(int j = 0; j < n; j++) {
                if(mask&1) {
                    bool check = false;
                    int sum = 0;
                    
                    for(auto& k: words[j]) {
                        if(countcopy[k-'a'] == 0) 
                            check = 1;
                        
                        sum += score[k-'a'];
                        countcopy[k-'a']--;
                    }
                    
                    if(check)
                        break;
                    else
                        thisscore += sum;
                }
                
                mask >>= 1;
            }
            ans = max(ans, thisscore);
        }
        
        return ans;
    }
};

// little better
class Solution {
public:
    
    int helper(vector<string>& words, vector<int>& count, vector<int>& score, int i, int val) {
        if(i == words.size()) 
            return val;
        
        //leave it
        int ans = helper(words, count, score, i+1, val);
        
        //take it
        int sum = 0;
        bool check = false;
        for(char& c: words[i]) {
            if(count[c-'a'] <= 0) 
                check = true;
            sum += score[c-'a'];
            count[c-'a']--;
        }
        
        if(!check)
            ans = max(ans, helper(words, count, score, i+1, val + sum));
        
        for(char& c: words[i])
            count[c-'a']++;
            
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);
        for(auto& l: letters)
            count[l-'a']++;
        
        return helper(words, count, score, 0, 0);
    }
};

// simple dfs solution
class Solution {
public:
    
    int helper(vector<string>& words, vector<int>& count, vector<int>& score, int i, int val) {
        if(i == words.size()) return val;
        
        //take it
        vector<int> countcopy = count;
        int sum = 0;
        for(char& c: words[i]) {
            if(countcopy[c-'a'] > 0)
                sum += score[c-'a'], countcopy[c-'a']--;
            else {
                sum = -1;
                break;
            }
        }
        
        int ans = 0;
        if(sum != -1)
            ans = helper(words, countcopy, score, i+1, val + sum);
        
        //leave it
        ans = max(ans, helper(words, count, score, i+1, val));
        
        return ans;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(26);
        for(auto& l: letters)
            count[l-'a']++;
        
        return helper(words, count, score, 0, 0);
    }
};