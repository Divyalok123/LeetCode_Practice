/*
https://leetcode.com/explore/featured/card/february-leetcoding-challenge-2021/587/week-4-february-22nd-february-28th/3655/
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

// Solution 3 (Using stack)
class FreqStack {
    
    unordered_map<int, int> m;
    unordered_map<int, stack<int>> ms;
    // stack<int> arr[100001];
    int maxf;
    
public:
    
    FreqStack(): maxf(0) {}
    
    void push(int x) {
        int& v = m[x];
        v++;
        maxf = max(maxf, v);
        ms[v].push(x);
    }
    
    int pop() {
        auto& i = ms[maxf];
        int ans = i.top();
        i.pop();
        
        m[ans]--;
        if(i.size() == 0) maxf--;
        
        return ans;
    }
    
};


// Solution 2 (Replacing set and multiset with priority_queue -> Improved running time to a great extent)
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, priority_queue<pair<int, int>>> fset; 
    priority_queue<int> mm;
    int i;
    
public:
    
    FreqStack(): i(0) {}
    
    void push(int x) {
        int& val = freq[x];
        i++;
        val++;
        mm.push(val);
        fset[val].push(make_pair(i, x));
    }
    
    int pop() {
        int x = mm.top();
        mm.pop();
        auto& itr = fset[x];
        pair<int, int> p = itr.top();
        itr.pop();
        int ans = p.second;
        int ii = p.first;
        if(itr.size() == 0) 
            fset.erase(x);
        freq[ans]--;
        return ans;
    }
};

// Solution 1 (NlogN)
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, set<pair<int, int>>> fset; 
    multiset<int> mm;
    int i;
    
public:
    
    FreqStack(): i(0) {}
    
    void push(int x) {
        int& val = freq[x];
        i++;
        val++;
        mm.insert(val);
        fset[val].insert({i, x});
    }
    
    int pop() {
        int x = *mm.rbegin();
        auto iitr = mm.find(x);
        mm.erase(iitr);
        auto& itr = fset[x];
        int ans = itr.rbegin()->second;
        int ii = itr.rbegin()->first;
        itr.erase(make_pair(ii, ans));
        if(itr.size() == 0) 
            fset.erase(x);
        freq[ans]--;
        return ans;
    }
};