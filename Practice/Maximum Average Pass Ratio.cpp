/*
https://leetcode.com/problems/maximum-average-pass-ratio/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    #define mp make_pair
    #define pii pair<double, pair<double, double>>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pii> pq;
        
        double sum = 0;
        for(auto& i: classes) {
            double pass = i[0], total = i[1];
            double diff = (pass + 1)/(total+1) - pass/total;
            
            if(diff != 0)
                pq.push(mp(diff, mp(pass, total)));
            else
                sum += 1;
        }
        
        if(pq.size() == 0) return 1;
        
        while(extraStudents--) {
            auto top = pq.top();
            pq.pop();
            
            double passv = top.second.first + 1;
            double totalv = top.second.second + 1;
            double diff = (passv + 1)/(totalv + 1) - passv/totalv;
            
            pq.push(mp(diff, mp(passv, totalv)));
        }
        
        while(pq.size()) {
            auto top = pq.top();
            sum += top.second.first/top.second.second;
            pq.pop();
        }
        
        return sum/classes.size();
    }
};