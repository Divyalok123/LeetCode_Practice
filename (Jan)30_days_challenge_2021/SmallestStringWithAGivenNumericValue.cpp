/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/582/week-4-january-22nd-january-28th/3619/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//Solution 3
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        k -= n;
        int v1 = k/25, v2 = k%25;
        if(v2) ans += string(n-v1-1, 'a');
        else ans += string(n-v1, 'a');
        if(v2) ans += 'a' + v2;
        ans += string(v1, 'z');
        
        return ans;
    }
};

//Solution 2
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k-=n;
        int i = n-1;
        while(k) {
            int v = (k < 25) ? k : 25;
            ans[i--] += v;
            k -= v;
        }
        
        return ans;
    }
};

//Solution 1
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, '-');
        for(int i = 0; i < n; i++) {
            // cout << "k: " << k << " i: " << i << " n-i: " << n-i << endl;
            if(k > 26) {
                if(k/26 == n-i) {
                    ans[i] = 'z';
                    k-=26;
                } else if(k/26 < n-i && ceil(((float)k-1)/26) > n-i-1) {
                    int v = k%26;
                    ans[i] = 'a' + v-1;
                    k-=v;
                } else 
                    ans[i] = 'a', k--;
            } else {
                if(i == n-1)
                    ans[i] = 'a' + k-1;
                else 
                    ans[i] = 'a', k--;
            }
        }
        return ans;
    }
};
