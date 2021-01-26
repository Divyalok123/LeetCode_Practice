/*
https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        if(n == 2) return 0;
        
        vector<int> v(limit*2 + 2);
        int i = 0, j = n-1;
        
        while(i < j) {
            int a = nums[i], b = nums[j];
            v[2]+=2;
            v[min(a, b) + 1]--;
            v[a+b]--;
            v[a+b+1]++;
            v[max(a, b) + limit + 1]++;
            i++,j--;
        }
        
        i = 2;
        int ans = INT_MAX;
        while(i < limit*2 + 2) {
            v[i] += v[i-1];
            if(v[i] < ans) ans = v[i];
            i++;
        }
        
        // cout << "V:";
        // for(int& el: v)
        //     cout << el << " ";
        // cout << endl;
        
        return ans;
    }
};