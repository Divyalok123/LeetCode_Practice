/*
https://leetcode.com/problems/snapshot-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Binary Search - get->O(log(size)), set->O(1), snap->O(1) 
class SnapshotArray {
    vector<vector<pair<int, int>>> v;
    int snap_id;
public:
    SnapshotArray(int length) {
        v.resize(length);
        snap_id = 0;
    }
    
    void set(int index, int val) {
        int sz = v[index].size();
        if(sz && snap_id == v[index][sz-1].first)
            v[index][sz-1].second = val;
        else
            v[index].push_back({snap_id, val});
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        if(v[index].size()) {
            
            auto ind = upper_bound(v[index].begin(), v[index].end(), make_pair(snap_id, INT_MAX));
            if(ind != v[index].begin()) {
                auto pre = prev(ind);
                return pre->second;
            } else {
                return 0;
            }
        } 
        return 0;
    }
};
