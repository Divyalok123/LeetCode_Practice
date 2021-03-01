/*
https://leetcode.com/explore/featured/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3657/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Solution 2
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans = 0, n = candyType.size()/2;
        vector<bool> v(200002);
        for(int i: candyType) {
            if(!v[i+100000]) {
                v[i+100000] = 1;
                ans++;
            }
        }
        return ans > n ? n : ans;
    }
};

// Solution 1
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int ans = 0, n = candyType.size()/2;
        unordered_set<int> s(candyType.begin(), candyType.end());
        return s.size() >= n ? n : s.size();
    }
};