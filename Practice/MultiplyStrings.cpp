/*
https://leetcode.com/problems/multiply-strings/
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Solution 2
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        string ans(n+m, '0');
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                int val = (num1[i]-'0')*(num2[j]-'0');
                int point1 = i+j, point2 = i+j+1;
                
                val += (ans[point2]-'0');
                
                ans[point2] = val%10 + '0';
                ans[point1] += val/10;
            }   
        }
        
        for(int i = 0; i < n+m; i++)
            if(ans[i] != '0') 
                return ans.substr(i);
        
        return  "0";
    }
};

// Solution 1
class Solution {
public:
    string add(string a, string b) {
        int n = a.size(), m = b.size();
        if(n == 0 || m == 0) 
            return n ? a : b;
        
        if(n < m) {
            swap(a, b);
            swap(n, m);
        }
        
        int i = n-1, carry = 0, j = m-1;
        string ans;
        while(i >= 0 && j >= 0) {
            int val = carry + (a[i]-'0') + (b[j]-'0');
            carry = val/10;
            val %= 10;
            ans.push_back(val+'0');
            i--, j--;
        }
        
        while(i >= 0) {
            int val = carry + (a[i]-'0');
            carry = val/10;
            val %= 10;
            ans.push_back(val+'0');
            i--;
        }
        
        if(carry)
            ans.push_back('1');
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    string multiply(const string& num1, const string& num2) {        
        int n = num1.size(), m = num2.size();
        int i = n-1, j, ten = 0;
        
        string ans = "";
        while(i >= 0) {
            j = m-1;
            int carry = 0, dig = num1[i]-'0';
            string temp;
            while(j >= 0) {
                int val = (num2[j]-'0')*dig + carry;
                carry = val/10;
                val %= 10;
                temp.push_back(val+'0');
                j--;
            }
            
            if(carry)
                temp += to_string(carry);
            
            reverse(temp.begin(), temp.end());
            
            for(int k = 0; k < ten; k++)
                temp.push_back('0');
            
            ans = add(ans, temp);

            i--;
            ten++;
        }
        
        if(ans[0] == '0') return "0";
        
        return ans;
    }
};