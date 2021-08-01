/*
https://leetcode.com/problems/repeated-string-match/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// using kmp
class Solution {
public:

    void printvec(vector<int>& v, string& s) {
        cout << s << ": ";
        for(int& i: v)
            cout << i << " ";
        cout << endl;
    }
    
    bool kmp(const string& str1, const string& str2) {
        int n = str1.size(), m = str2.size();
        
        vector<int> lps(m);
        lps[0] = 0;
        
        int i = 1, l = 0, j;
        while(i < m) {
            if(str2[i] == str2[l]) {
                l++;
                lps[i] = l;
                i++; 
            } else {
                if(l == 0) 
                    i++;
                else
                    l = lps[l-1];
            }
        }
        
        i = 0, j = 0;
        while(i < n) {
            if(str1[i] == str2[j]) {
                i++, j++;
                if(j == m) return 1;
            }
            
            else {
                if(j)
                    j = lps[j-1];
                else
                    j = 0, i++;
            }
        }
        
        return 0;
    }
    
    int repeatedStringMatch(string a, const string& b) {
        int n = a.size();
        int m = b.size();
        
        if(m == 0) return 0;
        
        string sa = a;
        int count = 1;
        while(sa.size() < b.size()) sa += a, count++;
        
        if(kmp(sa, b)) return count;
        
        sa += a;
        
        if(kmp(sa, b)) return count + 1;
        
        return -1;
    }
};

// naive algo
class Solution {
public:
    int repeatedStringMatch(const string& a, const string& b) {
        int n = a.size(), m = b.size();
        if(m == 0) return 0;
        
        int i = 0, j = 0;
        int lasti = 0, count = 1;
        
        while(j < m && i < n) {
            // cout << "i: " << i << " j: " << j << endl;
            if(a[i] == b[j]) {
                i++, j++;
                if(i == n && j != m)
                    i = 0, count++;
            } 
            
            else 
                j = 0, i = ++lasti, count = 1;
        }
        
        return j == m ? count : -1;
    }
};