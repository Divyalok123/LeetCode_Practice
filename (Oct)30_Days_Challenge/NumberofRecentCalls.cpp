/*
https://leetcode.com/explore/featured/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3480/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

/* Solution 2 */
class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty() && (t-q.front()) > 3000)
            q.pop();
        return q.size();
    }
};

/* Solution 1 */
class RecentCounter {
    vector<int> v;
    int i = 0;
public:
    RecentCounter() {
        v.resize(0);
    }
    
    int ping(int t) {
        v.push_back(t);
        while(i < v.size() && (t-v[i]) > 3000)
            i++;
        return v.size()-i;
    }
};