/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/580/week-2-january-8th-january-14th/3602/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Solution 1 */
class Solution {
public:
    int numRescueBoats(vector<int>& people, int lim) {
        int n = people.size();
        if(n <= 1) return n;
        
        int ans = 0;
        
        sort(people.begin(), people.end());
        
        if(people[0] >= lim) return n;
        
        int i = 0, j = n-1;
        while(j >= i && people[j] >= lim) ans++, j--;
        
        if(j < i) return ans;
        
        while(j > i) {
            if(people[j] + people[i] > lim) {
                ans++;
                j--;
            } else {
                ans++;
                i++, j--;
            }
        }
        
        if(j==i) ans++;
        
        return ans;
    }
};