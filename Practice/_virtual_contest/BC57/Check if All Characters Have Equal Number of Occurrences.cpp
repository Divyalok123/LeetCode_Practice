#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int count[27] = {0};
        
        for(char c: s)
            count[c-'a']++;
        
        int val = -1;
        
        for(int i = 0; i < 27; i++) {
            if(count[i]) {
                if(val == -1) val = count[i];
                else if(val != count[i]) return false;
            }
        }
        
        return true;
    }
};