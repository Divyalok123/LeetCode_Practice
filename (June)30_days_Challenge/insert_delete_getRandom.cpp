// Design a data structure that supports all following operations in average O(1) time.
// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

//solution 2 (using vector and maps)


//solution 1 (using set/map) (not O(1) worst case)
class RandomizedSet {
    // unordered_set<int> s;
    unordered_map<int, int> mymap;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mymap[val] == 0)
        {
            mymap[val] = 1;
            // s.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        // if(mymap[val] != 0)
        // {
        //     mymap[val] = 0;
        //     // s.erase(val);
        //     return true;
        // }
        // return false;

        if(mymap.find(val) != mymap.end())
        {
            mymap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        // int size = rand()%(s.size());
        // auto itr = s.begin();
        // for(int i = 0; i <size; i++)
        //     itr++;
        // return *itr;
        auto itr = mymap.begin();
        advance(itr, rand()%mymap.size());
        return itr->first;
    }
};