/*
https://leetcode.com/problems/utf-8-validation/
*/

#include <iostream>
#include <vector>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int bytes = 0;
        
        for(int& i: data) {
            if(bytes == 0) {
                int mask = (1 << 7);
                while((mask&i))
                    bytes++, mask >>= 1;
                
                if(mask == 0 || bytes > 4 || bytes == 1) return false;
                if(bytes == 0) continue;
                bytes--;
            } else {
                bool check = (i&(1 << 7)) && ((i&(1 << 6)) == 0);
                if(!check) return false;
                bytes--;
            }
        }
        
        return bytes == 0;
    }
};