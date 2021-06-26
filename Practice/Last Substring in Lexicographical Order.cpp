/*
https://leetcode.com/problems/last-substring-in-lexicographical-order/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// my suffix array implementation
class Solution {
public:
    
    void countsort(int p[], int c[], int n) {
        int count[n], pos[n], fp[n];
        memset(count, 0, sizeof count);
        
        for(int i = 0; i < n; i++)
            count[c[i]]++;
        
        pos[0] = 0;
        for(int i = 1; i < n; i++)
            pos[i] = pos[i-1] + count[i-1];
        
        for(int i = 0; i < n; i++)
        {
            int cl = c[p[i]];
            fp[pos[cl]] = p[i];
            pos[cl]++;
        }
        
        for(int i = 0; i < n; i++)
            p[i] = fp[i];
    }
    
    string lastSubstring(string s) {
        
        s += '$';
        int n = s.size();
        
        int p[n], c[n];
        
        {
            array<int, 2> store[n];
            for(int i = 0; i < n; i++)
                store[i] = {s[i], i};
            
            sort(store, store + n);
            
            for(int i = 0; i < n; i++)
                p[i] = store[i][1];
            
            c[p[0]] = 0;
            for(int i = 1; i < n; i++)
            {
                if(store[i][0] == store[i-1][0])
                    c[p[i]] = c[p[i-1]];
                else
                    c[p[i]] = c[p[i-1]] + 1;
            }
        }
        
        int k = 0;
        while((1 << k) < n) {
            for(int i = 0; i < n; i++)
                p[i] = (p[i] - (1 << k) + n) % n;
            
            countsort(p, c, n);
            
            int newc[n];
            newc[p[0]] = 0;
            
            for(int i = 1; i < n; i++) {
                array<int, 2> curr = {c[p[i]], c[(p[i] + (1 << k)) % n]};
                array<int, 2> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
                
                if(curr == prev)
                    newc[p[i]] = newc[p[i-1]];
                else
                    newc[p[i]] = newc[p[i-1]] + 1;
            }
            
            for(int i = 0; i < n; i++)
                c[i] = newc[i];
            
            k++;
        }
        
        string ans = s.substr(p[n-1]);
        ans.pop_back();
        return ans;
    }
};

//two pointers
//src: https://leetcode.com/problems/last-substring-in-lexicographical-order/discuss/363662/Short-python-code-O(n)-time-and-O(1)-space-with-proof-and-visualization
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size();
        
        int first = 0, second = 1, k = 0;
        
        while(second + k < n) {
            if(s[first + k] < s[second + k]) {
                first = max(first + k + 1, second);
                second = first + 1;
                k = 0;
            } else if(s[first + k] > s[second + k]) {
                second = second + k + 1;
                k = 0;
            } else {
                k++;
            }
        }
        
        return s.substr(first);
    }
};