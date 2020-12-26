/*
https://leetcode.com/problems/time-based-key-value-store/
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

/* Solution 2 */
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> umap;
    
    int search(vector<pair<int, string>>& v, int i, int j, int val) {
        if(i >= j) {
            return v[i].first <= val ? i : i-1;
        }
        
        int mid = i + (j-i)/2;
        if(v[mid].first == val)
            return mid;
        else if(v[mid].first > val)
            return search(v, i, j-1, val);
        else 
            return search(v, i+1, j, val);
    }
    
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key) == umap.end())
            return "";
        if(umap[key].back().first < timestamp)
            return umap[key].back().second;
        
        int t = search(umap[key], 0, umap[key].size()-1, timestamp);
        if(t == -1)
            return "";
        return umap[key][t].second;
    }
};

/* Solution 1 */
class TimeMap {
    unordered_map<string, map<int, string>> umap;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        umap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto point = umap[key].upper_bound(timestamp);
        return point == umap[key].begin() ? "" : prev(point)->second; 
    }
};
