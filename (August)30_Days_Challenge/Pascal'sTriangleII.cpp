/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(!rowIndex) return {1};
        vector<int> v(2, 1);
        vector<int> x;
        int i = 1;
        while(i < rowIndex) {
            x.resize(v.size()+1);
            x[0] = 1; x[v.size()] = 1;
            for(int i = 0; i < v.size()-1; i++) {
                x[i+1] = v[i] + v[i+1];
            }
            v.swap(x);
            i++;
        }
        return v;
    }
};