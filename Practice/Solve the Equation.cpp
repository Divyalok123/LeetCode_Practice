/*
https://leetcode.com/problems/solve-the-equation/
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    
    void process(const string& eq, int& i, int& countx, int& count) {
        int check = 1, n = eq.size();

        if(eq[i] == '-') check = -1, i++;
        else if(eq[i] == '+') i++;

        int first = -1;
        int c = 0;
        while(i < n && eq[i] >= '0' && eq[i] <= '9') {
            c *= 10;
            c += eq[i]-'0';
            if(first == -1) first = c;
            i++;
        }

        if(eq[i] == 'x') {
            if(!c && first==-1) c = 1;
            countx += check * c, i++;
        } else if(i == n || eq[i] == '=' || eq[i] == '-' || eq[i] == '+')
            count += check * c;
    }
    
    string solveEquation(const string& eq) {
        int countxl = 0, countxr = 0;
        int countl = 0, countr = 0;
        
        int i = 0, n = eq.size();
        while(eq[i] != '=')
            process(eq, i, countxl, countl);
        
        i++;
        
        while(i < n)
            process(eq, i, countxr, countr);

        if(countxl == countxr && countl == countr) 
            return "Infinite solutions";
        
        if(countxl == countxr)
            return "No solution";
        
        int ans = (countr-countl)/(countxl-countxr);
        return "x=" + to_string(ans);
    }
};