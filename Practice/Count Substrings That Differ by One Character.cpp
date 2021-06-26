/*
https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// sol4: Alternate to sol3 with O(1) space
class Solution {
public:
    
    void counter(string& s, string& t, int si, int tj, int& ans) {
        int m = s.size(), n = t.size(), count = 0, prev = 0;
        while(si < m && tj < n) {
            count++;
            
            if(s[si] != t[tj])
                prev = count, count = 0;
            
            ans += prev;
            si++, tj++;
        }
    }
    
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), ans = 0;
        
        for(int i = 0; i < m; i++)
            counter(s, t, i, 0, ans);
        
        for(int i = 1; i < n; i++)
            counter(s, t, 0, i, ans);
        
        return ans;
    }
};

// sol3: Improving sol2 O(n^2) time O(n^2) space
class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), ans = 0;
        
        int left[m+1][n+1], right[m+1][n+1];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(s[i-1] == t[j-1])
                    left[i][j] = 1 + left[i-1][j-1];
        
        for(int i = m-1; i >= 0; i--) 
            for(int j = n-1; j >= 0; j--)
                if(s[i] == t[j])
                    right[i][j] = 1 + right[i+1][j+1];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                if(s[i] != t[j])
                    ans += (1 + left[i][j]) * (1 + right[i+1][j+1]);
        
        return ans;
    }
};

// sol2: faster O(n^3) time solution
class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size(), ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0, si = i, tj = j;
                while(si < m && tj < n) {
                    if(s[si] != t[tj])
                        ++count;
                    
                    if(count > 1) break;
                    
                    if(count) 
                        ans++;
                    
                    si++, tj++;
                }
                
            }
        }
        
        return ans;
    }
};

// sol1: naive comparing substring - O(n^3)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size(), n = t.size();
        
        vector<unordered_map<string, int>> tm(n+1);
        
        for(int i = 0; i < n; i++) {
            string str;
            for(int j = i; j < n; j++) {
                str += t[j];
                tm[j-i+1][str]++;
            }
        }
        
        vector<unordered_map<string, int>> sm(m+1);
        for(int i = 0; i < m; i++) {
            string str;
            for(int j = i; j < m; j++) {
                str += s[j];
                sm[j-i+1][str]++;
            }
        }
        
        int ans = 0, lim = min(n, m);
        for(int i = 1; i <= lim; i++) {
            for(auto& [str, count]: sm[i]) {
                for(auto& [strt, countt]: tm[i]) {
                    int c = 0;
                    for(int j = 0; j < i; j++)
                    {
                        if(strt[j] != str[j]) {
                            c++;
                            if(c == 2) break;
                        }
                    }
                    
                    if(c == 1)
                        ans += count * countt;
                }
            }
        }
        
        return ans;
    }
};