/*
https://leetcode.com/problems/friends-of-appropriate-ages/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Prefix sum and count - O(N)
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0, n = ages.size();
        
        vector<int> count(121);
        for(int& i: ages) count[i]++;
        
        vector<int> prefix(121);
        for(int i = 1; i < 121; i++)
            prefix[i] += prefix[i-1] + count[i];
        
        for(int i = 15; i < 121; i++) {
            if(count[i]) {
                int lim = i/2 + 7;
                ans += (prefix[i]-prefix[lim]-1)*count[i];
            }
        }
        
        return ans;
    }
};

// Naive binary search - O(NlogN)
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            int lim = ages[i]*0.5 + 8;
            int lim2 = ages[i];
            
            auto ind = lower_bound(ages.begin(), ages.end(), lim);
            auto ind2 = upper_bound(ages.begin(), ages.end(), lim2);
            if(ind2 > ind)
                ans += ind2-ind-1;
        }
        
        return ans;
    }
};