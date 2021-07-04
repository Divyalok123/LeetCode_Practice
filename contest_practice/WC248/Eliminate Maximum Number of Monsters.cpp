/*
https://leetcode.com/contest/weekly-contest-248/problems/eliminate-maximum-number-of-monsters/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        
        for(int i = 0; i < n; i++)
            time[i] = (double)dist[i]/(double)speed[i];
        
        sort(time.begin(), time.end());
        
        int count = 0, tt = 0;
        while(count < n) {
            if(time[count] > tt) count++;
            else break;
            tt++;
        }
        
        return count;
    }
};