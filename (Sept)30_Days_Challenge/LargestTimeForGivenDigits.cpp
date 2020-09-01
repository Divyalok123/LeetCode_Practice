/*
https://leetcode.com/explore/featured/card/september-leetcoding-challenge/554/week-1-september-1st-september-7th/3445/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "", temp = "";
        
        sort(A.begin(), A.end(), greater<int>());
        
        int n = 24, n1, n2, n4 = -1;
        do {
            n1 = A[0]*10 + A[1];
            n2 = A[2]*10 + A[3];
            
            if(n1 <= 23 && n2 <= 59) 
                if(n1*100 + n2 > n4)
                    n4 = n1*100 + n2;
            
        } while (n-- && prev_permutation(A.begin(), A.end()));
        
        if(n4 == -1) return "";
        ans = to_string(n4);
        n = ans.size();
        n = 4-n;
        while(n--)
            temp += "0";
        
        if(temp.size() > 0) ans = temp + ans;
        ans.insert(2, ":");
        return ans;
    }
};