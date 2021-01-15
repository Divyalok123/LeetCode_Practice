/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/581/week-3-january-15th-january-21st/3605/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        vector<int> v(n+1);
        v[0] = 0;
        v[1] = 1;

        int maxv = 1;
        for(int i = 2; i <= n; i++) {
            v[i] = i&1 ? v[i/2] + v[i/2+1] : v[i/2];
            if(maxv < v[i]) maxv = v[i];
        }
        
        return maxv;
    }
};

int main() {
    Solution s;

    int n;
    cin >> n;

    cout << "MAX: " << s.getMaximumGenerated(n) << endl;
}