/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3442/
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> p, r;
    int findp(int a)
    {
        if(p[a] == a)
            return a;
        return p[a] = findp(p[a]);
    }
    
    void douni(int a, int b)
    {
        a = findp(a);
        b = findp(b);
        
        if(a != b)
        {
            if(r[a] < r[b])
                swap(a, b);
            p[b] = a;
            r[a] += r[b];
        }
    }
    
    int largestComponentSize(vector<int>& A) {
        int maxele = *max_element(A.begin(), A.end());
        p.resize(maxele+1);
        r.assign(maxele+1, 1);
        for(int i = 0; i <= maxele; i++)
            p[i] = i;
        
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 2; j <= sqrt(A[i]); j++)
            {
                if(A[i]%j == 0) {
                    douni(j, A[i]/j);
                    douni(j, A[i]);
                }
            }
        }
        
        unordered_map<int, int> m;
        for(int i = 0; i < A.size(); i++)
            ans = max(ans, ++m[findp(A[i])]);
        
        return ans;
    }
};