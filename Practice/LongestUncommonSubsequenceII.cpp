/*
https://leetcode.com/problems/longest-uncommon-subsequence-ii/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Solution 2 (O(max_string_size*NlogN + N^2)) ->taking O(1) for hashmap
class Solution {
public:
    bool check(const string& a, const string& b) {
        if(a.size() > b.size())
            return 0;

        if(a.size() == b.size())
            return a == b;
        
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(a[i] == b[j]) i++;
            j++;
        }
        
        return i==n;
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b){
            return a.size() > b.size();
        });        

            
        // cout << "STRS: ";
        // for(string& i: strs)
        //     cout << i << " ";
        // cout << endl;
        
        unordered_map<string, int> um;
        for(string& i: strs)
            um[i]++;
        int n = strs.size();
        for(int i = 0; i < n; i++)
        {
            if(um[strs[i]] == 1) {
                int j;
                for(j = i-1; j >= 0; j--) {
                    if(check(strs[i], strs[j])) 
                        break;
                }
                
                if(j == -1) return strs[i].size();
            }    
        }
        
        return -1;
    }
};

// Solution 1 (Brute Force, O(N^2*max_string_size*2^max_string_size))
class Solution {
public:
    void getsub(string& s, int i, string& thiss, unordered_set<string>& ss) 
    {
        if(i == s.size()) {
            if(thiss.size()) ss.insert(thiss);
            return;
        }
        
        
        getsub(s, i+1, thiss, ss);
        thiss.push_back(s[i]);
        getsub(s, i+1, thiss, ss);
        thiss.pop_back();
    }
    
    bool check(const string& a, const string& b) {
        if(a.size() > b.size())
            return 0;
        
        if(a.size() == b.size())
            return a == b;
        
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(a[i] == b[j])
                i++, j++;
            else 
                j++;
        }
        
        return i==n;
    }
    
    int findLUSlength(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        for(int i = 0; i < n; i++) 
        {
            string s;
            unordered_set<string> ss;
            getsub(strs[i], 0, s, ss);
            
            for(auto& sub: ss) {
                int j;
                for(j = 0; j < n; j++) {
                    if(i != j)
                        if(check(sub, strs[j]))
                            break;
                }
                
                if(j == n)
                    ans = max(ans, (int)sub.size());
            }
        }
        
        return ans ? ans : -1;
    }
};