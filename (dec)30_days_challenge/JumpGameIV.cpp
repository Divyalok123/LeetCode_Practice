/*
https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/572/week-4-december-22nd-december-28th/3582/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

/* Improved */
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        if(arr.front() == arr.back()) return 1;
        
        unordered_map<int, vector<int>> umap;

        // Improvisation 1: rather than pushing all the elements .. only push the first and 
        // last of its continuous occurence (if more than 1 are continous)
        int k = 0;
        while(k < n) {
            umap[arr[k]].push_back(k);
            k++;
            while(k < n-2 && arr[k+1] == arr[k])
                k++;
        }
        
        vector<bool> v(n, false);
        queue<pair<int, int>> q;
        v[0] = 1;
        q.push({0, 0});
        
        while(q.size()) {
            int sz = q.size();
            while(sz--) { //ref-while
                pair<int, int> p = q.front();
                q.pop();
                int i = p.first, j = p.second;
                if(i == n-1) return j; //Improvisation 2: we can return from here

                if(i-1 >= 0 && !v[i-1]) { v[i-1] = 1; q.push({i-1, j+1}); }
                if(i+1 < n && !v[i+1]) { v[i+1] = 1; q.push({i+1, j+1}); }

                // Improvisation 3: we don't need the popping operation 
                // because we are pushing all el only once due to the ref-while above
                for(int& ind: umap[arr[i]]) { 
                    if(v[ind] == 0) {
                        q.push({ind, j+1});
                        v[ind] = 1;
                    }
                }
            }
        }
        
        return -1;
    }
};

/* Solution 1 */
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < n; i++)
            umap[arr[i]].push_back(i);
        
        vector<bool> v(n, false);
        queue<pair<int, int>> q;
        v[0] = 1;
        q.push({0, 0});
        int ans = INT_MAX;
        
        while(q.size()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if(i == n-1) ans = min(ans, j);
            
            if(i-1 >= 0 && !v[i-1]) { v[i-1] = 1; q.push({i-1, j+1}); }
            if(i+1 < n && !v[i+1]) { v[i+1] = 1; q.push({i+1, j+1}); }
            while(umap[arr[i]].size()) {
                int ind = umap[arr[i]].back();
                if(v[ind] == 0) {
                    q.push({ind, j+1});
                    v[ind] = 1;
                }
                umap[arr[i]].pop_back();
            }
        }
        
        return ans;
    }
};