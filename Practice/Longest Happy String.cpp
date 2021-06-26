/*
https://leetcode.com/problems/longest-happy-string/
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

// improving to O(1) space 
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        int ca = 0, cb = 0, cc = 0;
        while(a + b + c) {
            if(a && ca != 2 && ((a >= b && a >= c) || ((cb == 2 && a >= c) || (cc == 2 && a >= b))))
                ans += 'a', a--, ca++, cb = 0, cc = 0;
            else if(b && cb != 2 && ((b >= a && b >= c) || ((cc == 2 && b >= a) || (ca == 2 && b >= c))))
                ans += 'b', b--, cb++, ca = 0, cc = 0;
            else if(c && cc != 2 && ((c >= a && c >= b) || ((cb == 2 && c >= a) || (ca == 2 && c >= b))))
                ans += 'c', c--, cc++, ca = 0, cb = 0;
            else break;
        }
        
        return ans;
    }
};

// priority_queue solution
class Solution {
public:
    #define mp make_pair
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        
        if(a) pq.push(mp(a, 'a'));
        if(b) pq.push(mp(b, 'b'));
        if(c) pq.push(mp(c, 'c'));
        
        string ans = "";
        while(pq.size() > 1) {
            auto [val1, ch1] = pq.top();
            pq.pop();
            auto [val2, ch2] = pq.top();
            pq.pop();
            
            ans += ch1, val1--;
            if(val1) ans += ch1, val1--;
            
            ans += ch2, val2--;
            if(val2 && val2 >= val1) 
                ans += ch2, val2--;
            
            if(val1) pq.push(mp(val1, ch1));
            if(val2) pq.push(mp(val2, ch2));
        }
        
        if(pq.size() == 0) return ans;
        
        if(pq.top().second != ans.back())
        {
            ans += pq.top().second;
            if(pq.top().first > 1) 
            ans += pq.top().second;
        } 

        return ans;
    }
};