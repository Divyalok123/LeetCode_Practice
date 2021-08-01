/*
https://leetcode.com/problems/distant-barcodes/
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <array>
#include <unordered_map>
using namespace std;

// no need to use sort either - O(n) (only the number with most count is needed to be placed first)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        int counts[10001], maxc = 0, maxv = 0, maxx = 0;
        memset(counts, 0, sizeof(counts));
        
        for(int& i: barcodes) {
            counts[i]++;
            if(counts[i] > maxc) {
                maxv = i;
                maxc = counts[i];
            }
            
            if(maxx < i)
                maxx = i;
        }
        
        int ind = 0;
        vector<int> ans(n);
        for(int i = 0; i <= maxx; i++) {
            int num = i == 0 ? maxv : i;
            // cout << "num: " << num << " count: " << counts[num] << endl;
            while(counts[num]-- > 0) {
                // cout << "ind: " << ind << endl;
                ans[ind] = num;
                ind += 2;
                if(ind >= n)
                    ind = 1;
            }
        }
        
        return ans;
    }
};

// dont need to use set - O(nlogn) (as we will iterate the ans array only twice)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        int counts[10001], maxx = INT_MIN;
        memset(counts, 0, sizeof(counts));
        
        for(int& i: barcodes) {
            counts[i]++;
            if(i > maxx) maxx = i;
        }
        
        vector<array<int, 2>> store;
        for(int i = 1; i <= maxx; i++)
            if(counts[i] != 0)  
                store.push_back({counts[i], i});
        
        sort(store.begin(), store.end(), greater<array<int, 2>>());
        int ind = 0;
        vector<int> ans(n);
        for(auto& i: store) {
            int count = i[0], num = i[1];
            while(count--) {
                ans[ind] = num;
                ind += 2;
                if(ind >= n) ind = 1;
            }
        }        
        
        return ans;
    }
};

// naive solution using sort + set - O(nlogn)
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        int counts[10001], maxx = INT_MIN;
        memset(counts, 0, sizeof(counts));
        
        for(int& i: barcodes) {
            counts[i]++;
            if(i > maxx) maxx = i;
        }
        
        vector<array<int, 2>> store;
        for(int i = 1; i <= maxx; i++)
            if(counts[i] != 0)  
                store.push_back({counts[i], i});
        
        sort(store.begin(), store.end(), greater<array<int, 2>>());
        set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(i);
        
        vector<int> ans(n);
        auto itr = s.begin();
        for(auto& i: store) {
            int count = i[0], num = i[1];
            while(count--) {
                ans[*itr] = num; 
                auto newitr = next(itr);
                if(*newitr == *itr + 1)
                    newitr = next(newitr);
                s.erase(itr);
                itr = newitr;
                if(itr == s.end())
                    itr = s.begin();
            }
        }        
        
        return ans;
    }
};