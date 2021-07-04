#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <vector>
using namespace std;

/* upsolving */

// Solution 2 (Using stack)
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        
        vector<int> s;
        vector<double> ans(n, -1);
        
        for(int i = n-1; i >= 0; i--) {
            int dis = cars[i][0], speed = cars[i][1];
            while(s.size() && cars[s.back()][1] >= speed) s.pop_back();
            while(s.size()) {
                int t = s.back();
                int tdis = cars[t][0], tspeed = cars[t][1];
                
                if(ans[t] > 0 && 1.0*(tdis-dis)/(speed-tspeed) >= ans[t])
                    s.pop_back();
                else {
                    ans[i] = 1.0*(tdis-dis)/(speed-tspeed);
                    break;
                }
            }
            
            s.push_back(i);
        }
        
        return ans;
    }
};

// Improved solution 1 (Replacing set with vector for prev and next)
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<int> l(n), r(n);
        for(int i = 0; i < n; i++)
        {
            l[i] = i-1;
            r[i] = i+1;
        }
        
        using pdi = pair<double, int>;
        class cmp {
          public:
            bool operator()(pdi const& a, pdi const& b){
                return a.first > b.first;
            }
        };
        
        priority_queue<pdi, vector<pdi>, cmp> pq;
        
        for(int i = 0; i < n-1; i++) {
            if(cars[i][1] > cars[i+1][1]) {
                pq.push(make_pair(((double)cars[i+1][0]-cars[i][0])/((double)cars[i][1]-cars[i+1][1]), i));
            }
        } 
        
        vector<double> ans(n, -1);
        while(pq.size()) {
            pair<double, int> p = pq.top();
            pq.pop();
            
            double curr = p.first;
            int ind = p.second;
            if(ans[ind] != -1) continue;
            ans[ind] = curr;
            
            if(l[ind] == -1) continue; 
            
            int pre = l[ind];
            int nex = r[ind];
            
            l[nex] = pre;
            r[pre] = nex;
            
            if(cars[pre][1] > cars[nex][1])
                pq.push(make_pair(((double)cars[nex][0]-cars[pre][0])/((double)cars[pre][1]-cars[nex][1]), pre));
            
        }
        
        return ans;
    }
};

// Solution 1
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        set<int> s;
        for(int i = 0; i < n; i++) 
            s.insert(i);
        
        using pdi = pair<double, int>;
        class cmp {
          public:
            bool operator()(pdi const& a, pdi const& b){
                return a.first > b.first;
            }
        };
        
        priority_queue<pdi, vector<pdi>, cmp> pq;
        
        for(int i = 0; i < n-1; i++) {
            if(cars[i][1] > cars[i+1][1]) {
                pq.push(make_pair(((double)cars[i+1][0]-cars[i][0])/((double)cars[i][1]-cars[i+1][1]), i));
            }
        } 
        
        vector<double> ans(n, -1);
        while(pq.size()) {
            pair<double, int> p = pq.top();
            pq.pop();
            
            double curr = p.first;
            int ind = p.second;
            if(ans[ind] != -1) continue;
            ans[ind] = curr;
            
            auto itr = s.find(ind);
            if(itr == s.begin()) {
                s.erase(itr);
                continue;
            }
            
            int pre = *prev(itr);
            int nex = *next(itr);
            s.erase(itr);
            
            if(cars[pre][1] > cars[nex][1])
                pq.push(make_pair(((double)cars[nex][0]-cars[pre][0])/((double)cars[pre][1]-cars[nex][1]), pre));
            
        }
        
        return ans;
    }
};