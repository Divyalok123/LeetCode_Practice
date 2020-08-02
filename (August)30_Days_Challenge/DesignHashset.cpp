/* https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/ */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



/* A very simple solution */
class MyHashSet {
    vector<bool> v;
public:
    MyHashSet() {
        v.resize(1000000);
    }
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;   
    }
    
    bool contains(int key) {
        return v[key];
    }
};