/*
https://leetcode.com/problems/magnetic-force-between-two-balls/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    bool possible(vector<int>& pos, int count, int dis) {
        
        int n = pos.size(), i = 0, last = pos[0];
        while(i < n && count) {
            if(i == 0 || pos[i]-last >= dis) {
                last = pos[i];
                count--;
            }
            i++;
        }
        
        // cout << "count: " << count << endl;
        return count == 0;
    }
    
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end());
        
        int l = 1, r = pos.back() + 1;
        int ans = r;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            // cout << "mid: " << mid << endl;
            if(possible(pos, m, mid))
                l = mid+1, ans = mid;
            else
                r = mid-1;
        }
        
        return ans;
    }
};