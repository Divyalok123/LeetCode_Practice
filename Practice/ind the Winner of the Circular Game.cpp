/*
https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//bottom-up dp
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 1;
        for(int i = 2; i <= n; i++) 
            ans = (ans + k-1)%i + 1;
        return ans;
    }
};

//top-down dp
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n == 1)
            return 1;
        return (findTheWinner(n-1, k) + k-1)%n + 1;
    }
};

// simulation
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            v[i] = i+1;
        
        int st = 0;
        while(n > 1) {
            st = (st+(k-1))%n;
            v.erase(v.begin() + st);
            n--;
        }
        
        return v[0];
    }
};