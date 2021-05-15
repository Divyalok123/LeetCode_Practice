/*
https://leetcode.com/problems/average-waiting-time/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        
        double sum = 0;
        int end = customers[0][0];
        for(auto& i: customers) {
            int a = i[0], b = i[1];
            if(end > a) 
                sum += (end-a);
            
            sum += b;
            end = end+b > a+b ? end+b : a+b;
        }
        
        return sum/n;
    }
};