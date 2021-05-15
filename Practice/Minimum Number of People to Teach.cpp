/*
https://leetcode.com/problems/minimum-number-of-people-to-teach/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//Brute force - (Performs better)
class Solution {
public:
    bool check(vector<int>& l1, vector<int>& l2) {
        int i = 0, j = 0, n = l1.size(), m = l2.size();
        
        while(i < n && j < m) {
            if(l1[i] == l2[j])
                return 1;
            else if(l1[i] < l2[j]) 
                i++;
            else 
                j++;
        }
        
        return 0;
    }
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        for(auto& i: languages)
            sort(i.begin(), i.end());
        
        unordered_set<int> s;
        for(auto& i: friendships) {
            int a = i[0], b = i[1];
            
            if(!check(languages[a-1], languages[b-1])) {
                s.insert(a);
                s.insert(b);
            }
            
        }        
        
        if(s.size() == 0) return 0;
        
        int ans = 100000;
        
        vector<int> count(n+1);
        for(const int& i: s) {
            for(int& j: languages[i-1])
                count[j]++;
        }
        
        for(int i = 1; i <= n; i++)
            if(ans > (s.size()-count[i])) 
                ans = s.size()-count[i]; 
        
        return ans;
        
    }
};



//Brute force - O(MN)
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int l = languages.size();
        int f = friendships.size();
        
        vector<unordered_set<int>> knows(n+1);
        for(int i = 0; i < l; i++) {
            for(int& j: languages[i])
                knows[j].insert(i+1);
        }
        
        vector<bool> already(f);
        for(int i = 0; i < f; i++) {
            int a = friendships[i][0], b = friendships[i][1];
            for(auto j: languages[a-1])
                if(knows[j].find(b) != knows[j].end()) {
                    already[i] = 1;
                    break;
                }
        }
        
        int ans = 100000;
        for(int i = 1; i <= n; i++) {
            int count = 0;
            for(int j = 0; j < f; j++) {
                if(already[j]) continue;
                
                int a = friendships[j][0], b = friendships[j][1];
                if(knows[i].find(a) == knows[i].end())
                    count++, knows[i].insert(a);
                
                if(knows[i].find(b) == knows[i].end())
                    count++, knows[i].insert(b);
            }
            
            // cout << "language: " << i << " count: " << count << endl;
            if(ans > count) {
                // cout << "added" << endl;
                ans = count;
            }
        }
        
        return ans;
        
    }
};

