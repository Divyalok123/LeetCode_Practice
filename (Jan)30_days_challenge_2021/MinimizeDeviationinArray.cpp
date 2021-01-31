/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/583/week-5-january-29th-january-31st/3622/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

// Solution 2
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        
        int minval = INT_MAX;
        for(int& i: nums) {
            if(i&1) i *= 2;
            pq.push(i);
            if(i < minval) minval = i;
        }
        
        int ans = INT_MAX;
        while(1) {
            int t = pq.top();
            pq.pop();
            
            if(t-minval < ans) ans = t-minval;
            if(t&1) break;
            
            t /= 2;
            if(t < minval) minval = t;
            pq.push(t);
        }
        
        return ans;
    }
};

// Solution 1
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int& i: nums) 
            s.insert(i&1 ? 2*i : i);
        
        int a = *s.rbegin(), b = *s.begin();
        int ans = a-b;
        while((*s.rbegin()&1) == 0) {
            if(abs(a/2-b) > a-b) break;
            s.erase(*s.rbegin());
            s.insert(a/2);
            a = *s.rbegin(), b = *s.begin();
            ans = min(ans, a-b);
        }
        
        return ans;
    }
};