#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <array>
using namespace std;


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        int tot = 2 * n;
        vector<array<int, 3>> vec;
        vec.reserve(tot);
        for(int i = 0; i < n; i++) {
            vec.emplace_back(array<int, 3>{times[i][0], 0, i});
            vec.emplace_back(array<int, 3>{times[i][1], 1, i});
        }
        
        sort(vec.begin(), vec.end(), [](array<int, 3>& a, array<int, 3>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> um;
        
        for(int i = 0; i < n; i++)
            pq.push(i);
        
        for(int i = 0; i < tot; i++) {
            if(vec[i][1] == 0) {
                int t = pq.top();
                pq.pop();
                
                if(vec[i][2] == targetFriend) 
                    return t;
                
                um[vec[i][2]] = t;
            } else {
                pq.push(um[vec[i][2]]);
            }         
        }
        
        return -1;
    }
};

