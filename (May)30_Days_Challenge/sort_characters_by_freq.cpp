// Given a string, sort it in decreasing order based on the frequency of characters.

#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

//Solution 1
class comparator {
public:
    bool operator()(const pair<int, char>& p1, const pair<int, char>& p2)
    {
        return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
    }
};

class Solution {
    unordered_map<char, int> mymap;
    priority_queue<pair<int, char>, vector<pair<int, char>>, comparator> myqueue;
    
public:
    string frequencySort(string s) {
        for(int i = 0; i < s.length(); i++)
        {
            mymap[s[i]]++;
        }
        
        for(auto x: mymap)
        {
            myqueue.push(make_pair(x.second, x.first));
        }
        
        string ans = "";
        while(!myqueue.empty())
        {
            int val = (int)myqueue.top().first;
            while(val--)
                ans.push_back(myqueue.top().second);
            myqueue.pop();
        }
        
        return ans;
    }
};