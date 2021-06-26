/*
https://leetcode.com/problems/find-longest-awesome-substring/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <array>
using namespace std;

// reverse: O(N*10)
class Solution {
public:
    
    int longestAwesome(const string& s) {
        int ans = 1, 
            n = s.size();
        
        int maskcache[1024];
        memset(maskcache, -1, sizeof(maskcache));
        maskcache[0] = 0;
        
        int mask = 0;
        for(int i = 0; i < n; i++) {
            mask ^= (1 << (s[i]-'0'));
            if(maskcache[mask] == -1)
                maskcache[mask] = i+1;
        }
        
        
        for(int i = n; i >= ans; i--) {
            if(i != n)
                mask ^= (1 << (s[i]-'0'));
            
            for(int j = 9, bit = 1 << 9; j >= -1; j--, bit >>= 1) {
                int currmask = mask ^ bit;
                if(maskcache[currmask] != -1)
                    ans = max(ans, i - maskcache[currmask]);
            }
            
        }
        
        return ans;
    }
};

// improving to smarter bitmask solution: O(N*10)
class Solution {
public:
    
    int longestAwesome(const string& s) {
        int ans = 1, 
            n = s.size();
        
        int maskcache[1024];
        memset(maskcache, -1, sizeof(maskcache));
        maskcache[0] = 0;
        
        int mask = 0;
        for(int i = 0; i < n; i++) {
            int currmask = 1 << (s[i]-'0');
            mask ^= currmask;
            
            if(maskcache[mask] != -1)
                ans = max(ans, i+1 - maskcache[mask]);    
            else
                maskcache[mask] = i+1;

            for(int j = 9, bit = 1 << 9; j >= 0; j--, bit >>= 1) {
                currmask = mask ^ bit;
                if(maskcache[currmask] != -1)
                    ans = max(ans, i+1-maskcache[currmask]);
            }
        }
        
        return ans;
    }
};

// naive bitmask solution: O(2^10 * N) -> (TLE)
class Solution {
public:
    
    int longestAwesome(string s) {
        int ans = 1, 
            n = s.size();
        
        vector<array<int, 2>> sett;
        sett.push_back({1 << (s[0]-'0'), 1});
        for(int i = 1; i < n; i++) {
            int mask = 1 << (s[i]-'0');
            vector<array<int, 2>> newsett;
            for(auto& [bitmask, count]: sett) {
                
                int bitcount = __builtin_popcount(bitmask);
                int nextbitcount = __builtin_popcount(bitmask ^ mask);
                if(nextbitcount <= 1) {
                    if(count + 1 > ans)
                        ans = count + 1;
                }
                
                newsett.push_back({bitmask ^ mask, count+1});
            }
            
            newsett.push_back({mask, 1});
            sett = newsett;
            
        }
        
        return ans;
    }
};