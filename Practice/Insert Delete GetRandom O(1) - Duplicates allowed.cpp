/*
https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
using namespace std;

//using unordered_map of vector
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class RandomizedCollection {
    unordered_map<int, vector<int>> ums;
    vector<array<int, 2>> v;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() { srand(0); }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int ans = (ums.find(val) == ums.end());
        auto& ref = ums[val];
        ref.push_back(v.size());
        v.push_back({val, (int)ref.size()-1});
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto ind = ums.find(val);
        int ans = (ind != ums.end());
        
        if(ans) {
            auto atlast = v.back();
            auto& mapofatind = ums[val];
            auto& mapofatlast = ums[atlast[0]];
            
            mapofatlast[atlast[1]] = mapofatind.back();
            v[mapofatind.back()] = atlast;
            mapofatind.pop_back();
            
            if(mapofatind.size() == 0)
                ums.erase(val);
            
            v.pop_back();
        }
        
        return ans;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // cout << "here" << endl;
        int ans = v[rand()%v.size()][0];
        // cout << "ends" << endl;
        return ans;
    }
};

//using unordered_map of unordered_set
class RandomizedCollection {
    unordered_map<int, unordered_set<int>> ums;
    vector<int> v;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int ans = (ums.find(val) == ums.end());
        v.push_back(val);
        ums[val].insert(v.size()-1);
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto ind = ums.find(val);
        int ans = (ind != ums.end());
        
        if(ans) {
            auto vind = ind->second.begin();
            int valueatvind = *(vind);
            
            ind->second.erase(valueatvind);
            int valueatlast = v.back();
            int lastind = v.size()-1;
            auto& sindset = ums[valueatlast];

            sindset.insert(valueatvind);
            v[valueatvind] = valueatlast;  
            
            sindset.erase(lastind);
            if(ind->second.size() == 0)
                ums.erase(ind);
            
            v.pop_back();
        }
        
        return ans;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};