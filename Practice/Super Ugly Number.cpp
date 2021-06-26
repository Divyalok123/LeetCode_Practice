/*
https://leetcode.com/problems/super-ugly-number/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// priority_queue - O(n * sz)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz = primes.size();
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        
        int uglies[n], ind[sz], uglies_last_prime[n];
        memset(ind, 0, sizeof ind);
        
        uglies[0] = 1;
        for(int i = 0; i < sz; i++)
            minheap.emplace(primes[i], i);
        
        for(int i = 1; i < n; i++) {
            auto [ref, k] = minheap.top();
            uglies[i] = ref;
            minheap.pop();            
            uglies_last_prime[i] = k;
            while(uglies_last_prime[++ind[k]] > k);
            minheap.emplace(uglies[ind[k]] * primes[k], k);
        }
        
        return uglies[n-1];
    }
};

// faster solution - O(n * sz)
class Solution {
public:
    int nthSuperUglyNumber(int n, const vector<int>& primes) {
        if(n == 1) return 1;
        int sz = primes.size();
        int ind[sz], val[sz];
        memset(ind, 0, sizeof ind);
        fill_n(val, sizeof val/sizeof *val, 1);
        
        int uglies[n];
        int nextugly = 1;
        for(int i = 0; i < n; i++) {
            uglies[i] = nextugly;
            nextugly = INT_MAX;
            for(int j = 0; j < sz; j++) {
                if(val[j] == uglies[i]) val[j] = primes[j] * uglies[ind[j]++];
                if(nextugly > val[j]) nextugly = val[j];
            }
        }
        
        return uglies[n-1];
    }
};

// naive pointers solution - O(n*sz)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        int sz = primes.size();
        int ind[sz];
        memset(ind, 0, sizeof ind);
        
        int uglies[n];
        uglies[0] = 1;
        
        for(int i = 1; i < n; i++) {
            
            int minval = INT_MAX;
            for(int j = 0; j < sz; j++)
                if(primes[j]*uglies[ind[j]] < minval)
                    minval = primes[j]*uglies[ind[j]];
            
            for(int j = 0; j < sz; j++)
                if(primes[j]*uglies[ind[j]] == minval)
                    ind[j]++;

            uglies[i] = minval;
        }
        
        return uglies[n-1];
    }
};