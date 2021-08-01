#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <set>
#include <array>
using namespace std;

class Solution {
public:
    #define ll long long
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        int tot = 2*n;
        vector<array<ll, 3>> vec;
        vec.reserve(tot);
        for(int i = 0; i < n; i++) {
            vec.emplace_back(array<ll,3>{segments[i][0], 1ll, segments[i][2]});
            vec.emplace_back(array<ll,3>{segments[i][1], 0ll, segments[i][2]});
        }
        
        sort(vec.begin(), vec.end());
        
        set<int> ss;        
        vector<vector<ll>> ans;
        array<ll, 2> curr = {vec[0][0], vec[0][2]};
        ss.insert(vec[0][0]);
        for(int i = 1; i < tot; i++) {
            if(vec[i][1] == 1) {
                if(vec[i][0] == curr[0]) curr[1] += vec[i][2];
                else {
                    if(curr[0] != vec[i][0] && curr[1]) {
                        ans.push_back({curr[0], vec[i][0], curr[1]});
                        ss.erase(curr[0]);
                    }
                    curr[0] = ss.size() ? *(ss.begin()) : vec[i][0];
                    curr[1] += vec[i][2];
                    ss.insert(vec[i][0]);
                }
            } else {
                if(vec[i][0] != curr[0] && curr[1]) {  
                    ans.push_back({curr[0], vec[i][0], curr[1]});
                    ss.erase(curr[0]);
                }
                curr[1] -= vec[i][2];
                curr[0] = ss.size() ? *(ss.begin()) : vec[i][0];
            }
        }
        
        return ans;
    }
};