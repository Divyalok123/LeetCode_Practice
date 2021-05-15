/*
https://leetcode.com/problems/find-the-closest-palindrome/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// improved
#define mp make_pair
class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        
        if(n.size() == 1) {
            num--;
            return to_string(num);
        }
        
        double val = log10(num);
        if(val == (int)val)
            return to_string(num-1);
        
        val = log10(num-1);
        if(val == (int)val)
            return to_string(num-2);
        
        val = log10(num+1);
        if(val == (int)val)
            return to_string(num+2);
        
        int size = n.size();
        bool check = false;
        for(int i = 0; i < size/2; i++) {
            if(n[i] != n[size-i-1])
                n[size-i-1] = n[i], check = 1;
        }
        
        long long num1 = stoll(n);
        string nn = n, nnn = n;
        if(size&1) {
            nn[size/2]++;
            nnn[size/2]--;
        } else {
            nn[size/2-1]++, nn[size/2]++;
            nnn[size/2-1]--, nnn[size/2]--;
        }
        
        long long num2 = stoll(nn);
        long long num3 = stoll(nnn);
        
        auto minval = min({mp((check ? abs(num-num1) : INT_MAX), num1), mp(abs(num-num2), num2), mp(abs(num-num3), num3)});
        return to_string(minval.second);
    }
};
 
// brute force
#define mp make_pair
class Solution {
public:
    string nearestPalindromic(string n) {
        long long num = stoll(n);
        
        if(n.size() == 1) {
            num--;
            return to_string(num);
        }
        
        double val = log10(num);
        if(val == (int)val)
            return to_string(num-1);
        
        val = log10(num-1);
        if(val == (int)val)
            return to_string(num-2);
        
        val = log10(num+1);
        if(val == (int)val)
            return to_string(num+2);
        
        int size = n.size();
        bool check = false;
        for(int i = 0; i < size/2; i++) {
            if(n[i] != n[size-i-1])
                n[size-i-1] = n[i], check = 1;
        }
        
        int a = size/2 - 1;
        int b = size/2;
        
        if(check) {
            if(size&1) {
                long long num2 = stoll(n);
                string nn = n;
                string nnn = n;
                if(num2 < num) {
                    nnn[b]++;
                    nn[a]++, nn[b+1]++;
                } else {
                    nnn[b]--;
                    nn[a]--, nn[b+1]--;
                }
                
                long long num1 = stoll(nnn);
                long long num3 = stoll(nn);
                
                auto minval = min({mp(abs(num-num2), num2), mp(abs(num-num1), num1), mp(abs(num-num3), num3)});
                return to_string(minval.second);
            } else {
                long long num2 = stoll(n);
                string nn = n;
                if(num2 < num || nn[a] == '0')
                    nn[a]++, nn[b]++;
                else
                    nn[a]--, nn[b]--;
                
                long long num1 = stoll(nn);
                
                auto minval = min({mp(abs(num1-num), num1), mp(abs(num2-num), num2)});
                return to_string(minval.second);
            }
        }
        
        if(size&1) {
            if(n[b] == '0')
                n[b]++;
            else
                n[b]--;
            return n;
        }
        
        
        if(n[a] == '0') {
            n[a]++, n[b]++;
            return n;
        } else if(n[a] == '9') {
            n[a]--, n[b]--;
            return n;
        } 
        
        string nn = n;
        nn[a]--, nn[b]--;
        n[a]++, n[b]++;

        long long num1 = stoll(nn);
        long long num2 = stoll(n);
        return num1 < num2 ? to_string(num1) : to_string(num2);
    }
};