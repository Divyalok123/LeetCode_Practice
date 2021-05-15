/*
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
	int findMaximumXOR(vector<int>& arr) {
        int n=arr.size();
        int newmask, ans = 0, mask = 0;
        unordered_set<int> ss;

        for(int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            for(const int& j: arr)
                ss.insert(mask&j);
            
            newmask = ans | (1 << i);
            for(const int& j: ss)
                if(ss.find(j^newmask) != ss.end())
                {
                    ans = newmask;
                    break;
                }    

            ss.clear();        
        }
        
        return ans;
	}
};