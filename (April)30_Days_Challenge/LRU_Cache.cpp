// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

// The cache is initialized with a positive capacity.

// Follow up:
// Could you do both operations in O(1) time complexity?

//Not O(1)
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

//Better Solution 
class LRUCache {
    list<int> mylist;
    unordered_map<int, pair<int, list<int>::iterator>> mymap;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        
        auto it = mymap.find(key);
        if(it == mymap.end()) return -1;
        
        mylist.erase(it->second.second);
        mylist.push_front(key);
        it->second.second = mylist.begin();
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = mymap.find(key);
        if(it != mymap.end())
        {
            mylist.erase(it->second.second);
            mylist.push_front(key);
            // it->second.second = mylist.begin();
            // it->second.first = value;
            mymap[key] = {value, mylist.begin()};
        }
        
        else
        {
            if(mymap.size() == size)
            {
                mymap.erase(mylist.back());
                mylist.pop_back();
            }
            
            mylist.push_front(key);
            mymap[key] = {value, mylist.begin()};

        }

        
    }
};

//First Solution
class LRUCache {
    list<int> mylist;
    unordered_map<int, int> mymap;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mymap[key])
        {
            mylist.remove(key);
            mylist.push_back(key);
            return mymap[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mymap[key])
        {
                mylist.remove(key);
                mylist.push_back(key);
                mymap[key] = value;         
        }
        else
        {
            if(mylist.size() == size)
            {
                mymap.erase(mylist.front());
                mylist.pop_front();
                mylist.push_back(key);
                mymap[key] = value;
            }
            else
            {
                mylist.push_back(key);
                mymap[key] = value;
            }
        }
        
    }
};
