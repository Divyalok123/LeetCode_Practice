/*
https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
*/

#include <iostream>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int& i: chalk) sum += i;
            
        cout << "SUM: " << sum << " k: " << k << endl;
        
        k %= sum;
        int i = 0;
        while(k >= chalk[i])
            k-=chalk[i++];
        
        return i;
    }
};