/*
https://leetcode.com/problems/daily-temperatures/
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/* Solution 3 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if(n == 0) return {};
        
        vector<int> ans(n);
        int j, i = n-2;
        while(i >= 0) {
            j = i+1;
            while(j < n-1 && T[j] <= T[i]) {
                if(ans[j] == 0) break;
                j += ans[j];
            }
            ans[i] = T[j] > T[i] ? j-i : 0;
            i--;
        }
        
        return ans;
    }
};

/* Solution 2 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if(n == 0) return {};
        
        vector<int> ans(n);
        stack<int> s;
        int i = n-1;
        while(i >= 0) {
            while(s.size() && T[s.top()] <= T[i]) s.pop();
            ans[i] = s.size() ? s.top()-i : 0;
            s.push(i--);
        }
        
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        if(n == 0) return {};
        
        vector<int> ans(n);
        stack<int> s;
        int i = 0;
        while(i < n) {
            while(s.size() && T[s.top()] < T[i]) {
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i++);
        }
        
        return ans;
    }
};