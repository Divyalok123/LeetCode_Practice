/*
https://leetcode.com/problems/heaters/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// different way - O(nlogn + NlogN)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int abss(int v) {
        return v < 0 ? -v : v;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        
        int closestHeater = 0, j = 0, N = heaters.size();
        for(int& house: houses) {
            int curr = INT_MAX;
            
            while(j < N) {
                int val = abss(heaters[j]-house);
                
                if(val > curr) {
                    j--;
                    break;
                }
                
                curr = val;
                
                if(j + 1 >= N) 
                    break;
                
                j++;
            }
            
            closestHeater = max(closestHeater, curr);
        }
        
        return closestHeater;   
    }
};

// better sort + binary search - O(NlogN + nlogN)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int ans = INT_MIN;
        for(int& house: houses) {
            auto itr = lower_bound(heaters.begin(), heaters.end(), house);
            
            int thisval = INT_MAX;
            if(itr != heaters.end())
                thisval = (*itr - house);
            
            if(itr != heaters.begin()) {
                itr = prev(itr);
                thisval = min(thisval, (house - *itr));
            }
            
            ans = max(ans, thisval);
        }
        
        return ans;   
    }
};

// sort + binary search - O(nlogn  + NlogN + Nlog(n)log(max(back))) 
class Solution {
public:
    
    bool check(vector<int>& houses, vector<int>& heaters, int m) {
        int n = houses.size(), nn = heaters.size();
        
        auto prevv = houses.begin();
        for(int i = 0; i < nn && prevv != houses.end(); i++) {
            if(heaters[i] - *prevv > m) return false; 
            prevv = upper_bound(houses.begin(), houses.end(), heaters[i] + m);
        }
            
        return prevv == houses.end();
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int l = 0, r = max(heaters.back(), houses.back()) + 1, ans;
        
        while(l <= r) {
            int m = l + (r-l)/2;
            // cout << "m: " << m << endl;
            if(check(houses, heaters, m))  {
                // cout << "done" << endl;
                ans = m, r = m-1;
            } else
                l = m+1;
        }
        
        return ans;
    }
};