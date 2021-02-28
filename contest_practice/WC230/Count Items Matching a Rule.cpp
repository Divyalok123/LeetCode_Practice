#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string rulekey, string rulevalue) {
        int ans = 0;
        for(auto& i: items) {
            if(rulekey == "type" && i[0] == rulevalue) ans++;
            else if(rulekey == "color" && i[1] == rulevalue) ans++;
            else if(rulekey == "name" && i[2] == rulevalue) ans++;
        }
        
        return ans;
    }
};