/*
https://leetcode.com/problems/smallest-sufficient-team/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int n, m;
    void helper(vector<int>& peopleMask, long long currans, long long& ourans, int curr) {
        int bitscurr = __builtin_popcountll(currans);
        int bitsfinal = __builtin_popcountll(ourans);
        
        if(curr == (1 << n)-1) {
            // cout << "bitscurr: " << bitscurr << " bitsfinal: " << bitsfinal << endl;
            if(bitscurr < bitsfinal)
                ourans = currans;
            return;
        }
        
        if(bitscurr >= bitsfinal) return;
        
        int bits = 1;
        while(curr & bits)
            bits <<= 1;
        
            
        for(int i = 0; i < m; i++) {
            int person = peopleMask[i];
            if(person & bits) {
                currans |= (1ll << i);
                helper(peopleMask, currans, ourans, curr|person);
                currans ^= (1ll << i);
            }
        }    
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = req_skills.size(), m = people.size();
        unordered_map<string, int> um;
        
        for(int i = 0; i < n; i++)
            um[req_skills[i]] = i;
        
        vector<int> peopleMask(m);
        for(int i = 0; i < m; i++) {
            int val = 0;
            for(const auto& j: people[i])
                val |= (1 << um[j]);
            peopleMask[i] = val;
        }
        
        long long ourans = (1ll << m)-1;
        helper(peopleMask, 0ll, ourans, 0);
        
//         cout << __builtin_popcount(ourans) << endl;
        
//         int copyy = ourans;
//         cout << "BITS: ";
//         while(copyy) {
//             cout << ((copyy & 1) > 0) << " ";
//             copyy >>= 1;
//         }
//         cout << endl;
        
        vector<int> ans;
        long long mask = 1;
        for(int i = 0; i < m; i++, mask <<= 1)
            if(ourans & mask)
                ans.push_back(i);
        
        return ans;
    }
};
