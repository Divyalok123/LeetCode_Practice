/*
https://leetcode.com/contest/weekly-contest-239/problems/minimum-interval-to-include-each-query/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <array>
#include <queue>
using namespace std;

// Solution 3 (union find)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> parent;
    
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int qn = queries.size(), in = intervals.size();
        vector<int> v = queries;        
        parent.resize(qn+1);
        vector<int> ans(qn, -1);
        
        for(int i = 0; i <= qn; i++)
            parent[i] = i;
        
        sort(v.begin(), v.end());
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            int dista = a[1]-a[0]+1;
            int distb = b[1]-b[0]+1;
            
            return dista < distb;
        });
        
        unordered_map<int, int> ind;
        for(int i = 0; i < qn; i++)
            ind[v[i]] = i;

        int j = 0;
        for(auto& i: intervals) {
            int l = i[0], r = i[1];
            int len = r - l + 1;
            
            int indl = lower_bound(v.begin(), v.end(), l)-v.begin();
            int indr = upper_bound(v.begin(), v.end(), r)-v.begin();
        
            int p = find(indl);
            while(p < indr && ans[p] == -1) {
                ans[p] = len;
                parent[p] = find(p+1);
                p = find(p);
            }
        }
        
        vector<int> fans(qn, -1);
        for(int i = 0; i < qn; i++)
            fans[i] = ans[ind[queries[i]]];
        
        return fans;
    }
};

// Solution 2 (Priority_queue) O(nlogn + qlogq)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int qn = queries.size(), in = intervals.size();
        using at = array<int, 2>;

        vector<at> v(qn);
        for(int i = 0; i < qn; i++)
            v[i] = {queries[i], i};

        sort(v.begin(), v.end());
        sort(intervals.begin(), intervals.end());

        priority_queue<at, vector<at>, greater<at>> pq;
        vector<int> ans(qn);
        
        int j = 0;
        for(auto i: v) {
            while(j < in && intervals[j][1] < i[0])
                j++;
            
            while(j < in && intervals[j][0] <= i[0]) {
                int l = intervals[j][0], r = intervals[j][1];
                pq.push({r-l+1, r});
                j++;
            }
            
            while(pq.size() && pq.top()[1] < i[0])
                pq.pop();
            
            ans[i[1]] = pq.size() ? pq.top()[0] : -1;
        }
        
        return ans;
    }
};

// Solution 1 (sort + binarySearch) O(nlogn + qlogq)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        set<array<int, 2>> s;
        int qn = queries.size(), in = intervals.size();
        
        for(int i = 0; i < qn; i++)
            s.insert({queries[i], i});
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            int dista = a[1]-a[0]+1;
            int distb = b[1]-b[0]+1;
            
            return dista < distb || (dista == distb && a[0] < b[0]);
        });
        
        vector<int> ans(qn, -1);
        for(int i = 0; i < in && s.size(); i++) {
            int r = intervals[i][1], l = intervals[i][0];
            int len = r-l+1;
            
            if(r < (*s.begin())[0] || l > (*prev(s.end()))[0])
                continue;
            
            auto ind = s.lower_bound({l, 0});
            
            while(ind != s.end() && (*ind)[0] <= r) {
                auto newind = next(ind);
                ans[(*ind)[1]] = len;
                s.erase(ind);
                ind = newind;
            }
        }
        
        return ans;
    }
};