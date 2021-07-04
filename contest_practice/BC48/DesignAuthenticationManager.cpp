/*
https://leetcode.com/contest/biweekly-contest-48/problems/design-authentication-manager/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// Solution 2 
class AuthenticationManager {
    unordered_map<string, list<pair<int, string>>::iterator> um;
    list<pair<int, string>> ss;
    int timetolive;
public:
    AuthenticationManager(int timeToLive) {
        this->timetolive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        while(ss.size() && ss.front().first <= currentTime)
        {
            um.erase(um.find(ss.front().second));
            ss.pop_front();
        }
        
        ss.push_back({currentTime + timetolive, tokenId});
        um[tokenId] = prev(ss.end());
    }
    
    void renew(string tokenId, int currentTime) {
        while(ss.size() && ss.front().first <= currentTime)
        {
            um.erase(um.find(ss.front().second));
            ss.pop_front();
        }
        
        auto itr = um.find(tokenId);
        if(itr == um.end()) return;
        ss.erase(itr->second);
        generate(tokenId, currentTime);
    }
    
    int countUnexpiredTokens(int currentTime) {
        while(ss.size() && ss.front().first <= currentTime) {
            um.erase(um.find(ss.front().second));
            ss.pop_front();
        }
        
        return ss.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

// Solution 1 (O(N^2))
class AuthenticationManager {
    unordered_map<string, int> um;
    int timetolive;
public:
    AuthenticationManager(int timeToLive) {
        this->timetolive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        um[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(um.count(tokenId) && um[tokenId] + timetolive > currentTime) {
            // cout << "tokenId: " << tokenId << " timetolive: " << timetolive << " currtime: " << currentTime << endl;
            um[tokenId] = currentTime;
        }
        
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans = 0;
        for(auto& i: um) 
            if(i.second > 0 && i.second + timetolive > currentTime)
                ans++;
        return ans;
    }
};