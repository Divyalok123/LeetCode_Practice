/*
https://leetcode.com/problems/super-palindromes/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//getting palindromes
class Solution {
public:
    static bool ispalin(string& str) {
        int n = str.size();
        if(n == 1) return 1;

        int l = 0, r = n-1;
        while(l < r) 
            if(str[l++] != str[r--]) 
                return 0;

        return 1;
    }
    
    static void getnext(string& curr) {
        int n = curr.size();
        int a = n/2-1;
        int b = n/2;

        bool check = (n&1);
        
        if(curr[b] != '9') {
            curr[b]++;
            if(check == 0)
                curr[a]++;
            return;
        } 
        

        if(curr.front() == '9' && curr.back() == '9') {
            long long num = (long long)pow(10, n) + 1;
            curr = to_string(num);
            return;
        }
        
        if(check) curr[b++] = '0';
        
        int i = a;
        while(i >= 0 && curr[i] == '9') {
            curr[i] = '0', curr[n-i-1] = '0';
            i--;
        } 
        
        curr[i]++, curr[n-i-1]++;
    }

    static vector<long long> getsuperpalins() {
        vector<long long> superpalins;
        string currpalin = "11";
        long long num = 11;
        superpalins = {1, 4, 9};
        while(num < 1000000000) {
            num *= num;
            string str = to_string(num);
            if(ispalin(str))
                superpalins.push_back(num);
            getnext(currpalin);
            num = stoll(currpalin);
        }
        return superpalins;
    }
    
    
    int superpalindromesInRange(const string& left, const string& right) {
        static auto superpalins = getsuperpalins();
        long long num1 = stoll(left);
        long long num2 = stoll(right);
        
        auto ind1 = lower_bound(superpalins.begin(), superpalins.end(), num1);
        auto ind2 = upper_bound(ind1, superpalins.end(), num2);
        
        return ind2-ind1;    
    }
};