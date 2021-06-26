/*
https://leetcode.com/problems/bulb-switcher-ii/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

// maths
class Solution {
public:
    int flipLights(int n, int presses) {
        if(presses == 0) return 1;
        if(n == 1) return 2;
        if(n == 2) return presses == 1 ? 3 : 4;
        if(presses == 1) return 4;
        if(presses == 2) return 7;
        return 8;
    }
};

// bfs
class Solution {
public:
    int size;
    void toggle(char& c) {
        if(c == '0') c = '1';
        else c = '0';
    }
    
    int operation0(int num) {
        for(int bit = 1 << (size-1); bit; bit >>= 1)
            num ^= bit;
        return num;
    }
    
    int operation1(int num) {
        for(int bit = 1 << (size-1); bit; bit >>= 2)
            num ^= bit;
        return num;
    }
    
    int operation2(int num) {
        for(int bit = 1 << (size-2); bit; bit >>= 2)
            num ^= bit;
        return num;
    }
    int operation3(int num) {
        for(int bit = 1 << (size-1); bit; bit >>= 3)
            num ^= bit;
        return num;
    }
    
    int flipLights(int n, int presses) {
        if(presses == 0) 
            return 1;
        if(n == 1) 
            return 2;
        
        //since sequence repeats
        if(n > 6)
            n = n%6 + 6;
        
        size = n;
        queue<int> q;
        q.push((1 << n)-1);
        
        unordered_set<int> ss;
        while(presses--) {
            ss.clear();
            int sz = q.size();
            while(sz--) {
                int front = q.front();
                q.pop();
                
                int nextt[4] = {operation0(front), operation1(front), operation2(front), operation3(front)};
                
                for(int i = 0; i < 4; i++) {
                    if(ss.find(nextt[i]) == ss.end())
                    {
                        q.push(nextt[i]);
                        ss.insert(nextt[i]);
                    }
                }
                
            }
            
        }
        
        return ss.size();
    }
};

// dfs
class Solution {
public:
    unordered_set<string> ss;
    int ans;
    void toggle(char& c) {
        if(c == '0') c = '1';
        else c = '0';
    }
    
    string operation0(string& s) {
        int n = s.size();
        string newstring = s;
        for(int i = 0; i < n; i++)
            toggle(newstring[i]);
        return newstring;
    }
    
    string operation1(string& s) {
        int n = s.size();
        string newstring = s;
        for(int i = 0; i < n; i+=2)
            toggle(newstring[i]);
        return newstring;
    }
    
    string operation2(string& s) {
        int n = s.size();
        string newstring = s;
        for(int i = 1; i < n; i+=2)
            toggle(newstring[i]);
        return newstring;
    }
    
    string operation3(string& s) {
        int n = s.size();
        string newstring = s;
        for(int i = 0; i < n; i+=3)
            toggle(newstring[i]);
        return newstring;
    }
    
    void helper(int p, string& s) {
        if(p == 0) {
            ans++;
            return;
        }
        
        string temp = to_string(p), news;
        string s0 = operation0(s);
        news = s0+temp;
        if(ss.find(news) == ss.end()) {
            ss.insert(news);
            helper(p-1, s0);
        }
        
        string s2 = operation2(s);
        news = s2 + temp;
        if(ss.find(news) == ss.end()) {
            ss.insert(news);
            helper(p-1, s2);
        }
        
        string s1 = operation1(s);
        news = s1 + temp;
        if(ss.find(news) == ss.end()) {
            ss.insert(news);
            helper(p-1, s1);
        }
        
        string s3 = operation3(s);
        news = s3 + temp;
        if(ss.find(news) == ss.end()) {
            ss.insert(news);
            helper(p-1, s3);
        }
    }
    
    int flipLights(int n, int presses) {
        if(presses == 0) 
            return 1;

        if(n > 6) // repetition after 6 n's and since it is not so big we can use a bitmask too
            n= n%6 + 6;
        ans = 0;
        string s(n, '1');
        helper(presses, s);
        return ans;
    }
};