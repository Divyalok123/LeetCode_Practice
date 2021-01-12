/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3598/
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

/* Solution 3 (two-end BFS - Great idea!) */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ss(wordList.begin(), wordList.end()), qs, qe, *qsref, *qeref;
        
        if(ss.find(endWord) == ss.end()) return 0;
        int size = beginWord.size();
        qs.insert(beginWord);
        qe.insert(endWord);
        
        int ans = 1;
        while(qs.size() && qe.size()) {
            if(qs.size() <= qe.size()) {
                qsref = &qs;
                qeref = &qe;
            } else {
                qsref = &qe;
                qeref = &qs;
            }
            
            unordered_set<string> tempset;
            for(auto i = qsref->begin(); i != qsref->end(); i++) {
                string s = *i;
                for(int j = 0; j < s.size(); j++) {
                    char c = s[j];
                    for(int k = 0; k < 26; k++) {
                        s[j] = 'a' + k;
                        if(qeref->find(s) != qeref->end()) return ans + 1;
                        if(ss.find(s) != ss.end()) {
                            tempset.insert(s);
                            ss.erase(s);
                        }
                    }
                    s[j] = c;
                }
            }
            ans++;
            swap(*qsref, tempset);
        }
        
        return 0;
    }
};

/* Solution 2 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ss(wordList.begin(), wordList.end());
        if(ss.find(endWord) == ss.end()) return 0;
        
        queue<string> q;
        int size = beginWord.size();
        q.push(beginWord);
        
        int ans = 1;
        while(q.size()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                string front = q.front();
                q.pop();
                
                if(front == endWord) return ans;
                
                for(int k = 0; k < size; k++) {
                    char c = front[k];
                    for(int j = 0; j < 26; j++) {
                        front[k] = 'a' + j;
                        if(ss.find(front) != ss.end()) {
                            q.push(front);
                            ss.erase(front);
                        }
                        front[k] = c;
                    }
                }
            }
            ans++;
        }
        
        return 0;
    }
};

/* Solution 1 */
class Solution {
public:
    bool diff(string& a, string& b) {
        if(a.size() != b.size()) return 0;
        int difference = 0;
        for(int i = 0; i < a.size(); i++)
            if(b[i] != a[i]) {
                difference++;
                if(difference > 1) return false;
            }
        
        return difference == 1;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> ss;
        for(string& s: wordList)
            ss.insert(s);
        
        if(ss.find(endWord) == ss.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int ans = 1;
        while(q.size()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                string front = q.front();
                q.pop();
                
                if(front == endWord) return ans;
                
                ss.erase(front);
                auto itr = ss.begin();
                while(itr != ss.end()) {
                    string thiss = *itr;
                    if(diff(thiss, front)) {
                        q.push(thiss);
                        itr = ss.erase(itr);
                    } else itr++;
                }
            }
            ans++;
        }
        
        return 0;
    }
};