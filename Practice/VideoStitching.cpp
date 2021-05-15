/*
https://leetcode.com/problems/video-stitching/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 2 (Little Improvisation)
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if(T == 0) return 0;
        
        vector<vector<int>> newclips;
        int n = clips.size();
        sort(clips.begin(), clips.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        newclips.push_back(clips[0]);
        for(int i = 1; i < n; i++)
            if(newclips.back().front() != clips[i][0])
                newclips.push_back(clips[i]);
        
        if(clips[0][0] != 0) return -1;
        int ans = 1, i = 1, furthest = newclips[0][1];
        
        n = newclips.size();
        while(i < n && furthest < T) {
            int currmax = INT_MIN;
            while(i < n && newclips[i][0] <= furthest) {
                if(newclips[i][1] > currmax) 
                    currmax = newclips[i][1];
                i++;
            }
            
            ans++;
            if(currmax <= furthest) 
                return -1;
            
            furthest = currmax;
        }        
        
        return furthest < T ? -1 : ans;
    }
};

// Solution 1
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if(T == 0) return 0;
        
        sort(clips.begin(), clips.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        int n = clips.size();
        if(clips[0][0] != 0) return -1;
        int ans = 1, i = 1, furthest = clips[0][1];
        
        while(i < n && furthest < T) {
            int currmax = INT_MIN, ind = -1;
            while(i < n && clips[i][0] <= furthest) {
                if(clips[i][1] > currmax) 
                    currmax = clips[i][1];
                i++;
            }
            
            ans++;
            if(currmax <= furthest) 
                return -1;
            
            furthest = currmax;
        }        
        
        return furthest < T ? -1 : ans;
    }
};