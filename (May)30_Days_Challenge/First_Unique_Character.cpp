// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Solution 2
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> mymap;   
        for(int i = 0; i < s.length(); i++)
        {
            if(mymap.find(s[i]) == mymap.end())
            {
                mymap[s[i]] = {1, i};
            }
            else
            {
                mymap[s[i]].first++;
            }
        }
        
        int minIndex = INT_MAX;
        for(auto p: mymap)
        {
            if(p.second.first == 1 && p.second.second < minIndex)
            {
                minIndex = p.second.second;
            }
        }
        
        if(minIndex != INT_MAX)
            return minIndex;
        return -1;
    }
};

//Solution 1
class Solution {
public:
    int firstUniqChar(string s) {
        int countarr[26];
        memset(countarr, 0, 4*26);
        
        for(int i = 0; i < s.length(); i++)
        {
            countarr[s[i]-'a']++;
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(countarr[s[i] - 'a'] == 1)
            {
                return i;                
            }
        }
        return -1;
        
    }
};

