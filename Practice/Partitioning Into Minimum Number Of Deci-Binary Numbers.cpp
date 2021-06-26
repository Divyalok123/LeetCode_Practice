/*
https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

#include <iostream>
#include <string>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int minPartitions(string n) {
        int sz = n.size();
        char maxx = '0';
        for(int i = 0; i < sz; i++)
            if(n[i] > maxx) {
                maxx = n[i];
                if(maxx == '9')
                    break;
            }
        
        return maxx-'0';
    }
};