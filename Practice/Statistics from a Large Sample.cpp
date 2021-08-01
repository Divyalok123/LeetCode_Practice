/*
https://leetcode.com/problems/statistics-from-a-large-sample/
*/

#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        
        vector<array<double, 2>> store;
        store.reserve(256);
        for(double i = 0; i < 256; i++)
            if(count[i])
                store.push_back({static_cast<double>(count[i]), i});
        
        double minn = INT_MAX, maxx = INT_MIN, sum = 0, cnt = 0, mode = -1, modec = 0;
        
        for(auto st: store) {
            double val = st[0];
            double i = st[1];
            cnt += val;
            sum += val * i;
            
            if(val && i < minn) minn = i;
            if(val && i > maxx) maxx = i;
            if(modec < val) {
                mode = i;
                modec = val;
            }
        }
        
        double mean = sum/cnt;
        
        int mid1 = (cnt-1)/2 + 1,
            mid2 = cnt/2 + 1,
            n = store.size();
        
        // cout << "mid1: " << mid1 << " mid2: " << mid2 << endl;
        
        double tcnt = 0, midv1 = 0, midv2 = 0;
        for(double i = 0; i < n; i++) {
            if(tcnt + store[i][0] > mid1) {
                midv1 = store[i][1], midv2 = store[i][1];
                break;
            } else if(tcnt + store[i][0] == mid1) {
                midv1 = store[i][1], midv2 = store[i][1];
                if(mid1 != mid2)
                    midv2 = store[i+1][1];
                break;
            }
            
            tcnt += store[i][0];
        }
        
        // cout << "mid1: " << midv1 << " mid2: " << midv2 << endl;
        
        double median = (midv1 + midv2)/2l;
        
        return {minn,maxx,mean,median, mode};
    }
};