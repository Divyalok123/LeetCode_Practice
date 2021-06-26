/*
https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// improvement: minsize substrings will have max number of occurences : low probability of collisions (we can lower it more by using more hashes)
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), ans = 0;
        
        unordered_map<long long, int> store;        
        long long MOD = 1000000009, p = 9413;
        
        long long hashes[n+1], powers[n];
        powers[0] = 1, hashes[0] = 1;
        for(int i = 1; i < n; i++)
            powers[i] = (powers[i-1]*p)%MOD;
        
        for(int i = 0; i < n; i++)
            hashes[i+1] = (hashes[i] + (s[i] - 'a' + 1)*powers[i])%MOD;
        
        int check[26] = {0};
        int i = minSize, j = 0, k = 0, count = 0;
        long long hash;

        while(k < i) {
            int ind = s[k]-'a';
            if(check[ind] == 0)
                count++;

            check[ind]++;
            k++;
        }

        if(count <= maxLetters) {
            hash = (hashes[k] + MOD - hashes[k-i])%MOD;
            hash = (hash * powers[n-(k-i)-1])%MOD;
            store[hash]++;
        }

        while(k < n) {
            int ind1 = s[j]-'a', ind2 = s[k]-'a';
            check[ind1]--;
            if(check[ind1] == 0)
                count--;

            check[ind2]++;
            if(check[ind2] == 1)
                count++;

            if(count <= maxLetters) {
                hash = (hashes[k+1] + MOD - hashes[k+1-i])%MOD;
                hash = (hash*powers[n-(k+1-i)-1])%MOD;
                store[hash]++;
            }

            k++, j++;
        }
            
        
        for(auto& [k, v]: store)
            if(ans < v)
                ans = v;
        
        return ans;
    }
};

// naive brute with hashing
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), ans = 0;
        
        unordered_map<long long, int> store[maxSize+1];        
        long long MOD = 1000000009, p = 9413;
        
        long long hashes[n+1], powers[n];
        powers[0] = 1, hashes[0] = 1;
        for(int i = 1; i < n; i++)
            powers[i] = (powers[i-1]*p)%MOD;
        
        for(int i = 0; i < n; i++)
            hashes[i+1] = (hashes[i] + (s[i] - 'a' + 1)*powers[i])%MOD;
        
        int check[26] = {0};
        for(int i = minSize; i <= maxSize; i++) {
            int j = 0, k = 0, count = 0;
            long long hash;
            
            auto& thisstore = store[i];
            
            while(k < i) {
                int ind = s[k]-'a';
                if(check[ind] == 0)
                    count++;
                
                check[ind]++;
                k++;
            }
            
            if(count <= maxLetters) {
                hash = (hashes[k] + MOD - hashes[k-i])%MOD;
                hash = (hash * powers[n-(k-i)-1])%MOD;
                thisstore[hash]++;
            }
                
            while(k < n) {
                int ind1 = s[j]-'a', ind2 = s[k]-'a';
                check[ind1]--;
                if(check[ind1] == 0)
                    count--;
                
                check[ind2]++;
                if(check[ind2] == 1)
                    count++;
                
                if(count <= maxLetters) {
                    hash = (hashes[k+1] + MOD - hashes[k+1-i])%MOD;
                    hash = (hash*powers[n-(k+1-i)-1])%MOD;
                    thisstore[hash]++;
                }
                
                k++, j++;
            }
            
            for(auto& [key, value]: thisstore)
                if(ans < value)
                    ans = value;
            
            for(int l = 0; l < 26; l++)
                check[l] = 0;
            
        }
        
        return ans;
    }
};