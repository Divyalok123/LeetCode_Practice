/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3653/
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 2 (O(1) - Space)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int j = -1, i = 0, k = 0, n = pushed.size();
        while(i < n) {
            pushed[++j] = pushed[i];
            while(j != -1 && pushed[j] == popped[k]) j--, k++;
            i++;
        }
        
        return k == n;
    }
};

// Solution 1 (O(N) - Space)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for(int i = 0; i < pushed.size(); i++) {
            s.push(pushed[i]);
            while(s.size() && s.top() == popped[j]) 
                s.pop(), j++;
        }
        
        return s.empty();
    }
};