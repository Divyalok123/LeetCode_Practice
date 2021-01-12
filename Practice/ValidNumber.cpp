/*
https://leetcode.com/problems/valid-number/
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if(n == 0) return 1;

        if(n == 1) return isdigit(s[0]); //single element should be a digit

        auto check = [](char c){return c == '+' || c == '-';};
        
        while(s.size() && s.back() == ' ') s.pop_back();
        
        if(s.size() == 0) return false; //if all spaces
        if(s.back() == 'e' || check(s.back())) return 0;
        
        cout << "checkpoint 1" << endl;
        
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        
        cout << "checkpoint 2, i: " << i << endl;
        
        int starti = i;
        bool fe = 0, sn = 0, fd = 0, fdot = 0;
        for(; i < s.size(); i++) {
            if(!fd) if(isdigit(s[i])) fd = 1; //found a digit
            
            if(s[i] == ' ') return false; //checking for space
            
            if(!isdigit(s[i])) //if not a digit
                if(!(s[i] == 'e' || s[i] == '+' || s[i] == '-' || s[i] == '.')) return false; //if doesn't match allowed values
            
            if(s[i] == '.') { //found a dot
                if(fdot || fe) return false; //if second dot or an e have been found
                fdot = 1; //first dot
            } 

            if(check(s[i])) { //found a sign
                if(sn) return false; //second sign
                if(i != starti) sn = 1;//first sign if not 0th
            } 
            
            if(check(s[i]) && (i > starti && s[i-1] != 'e')) //sign found but the prev elem is not 'e'
                return false;
            
            if(s[i] == 'e') { //found an 'e'
                if(i == n-1 || !fd || fe) return 0;
                fe = 1;
            }
        }
        
        return fd;
    }
};