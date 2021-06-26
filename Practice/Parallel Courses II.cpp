/*
https://leetcode.com/problems/parallel-courses-ii/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<map<vector<int>, int>> cache;
    int K, N, nK;
    vector<long long> facts;
    
    void genfacts(int n) {
        facts.push_back(1);
        for(int i = 1; i <= n; i++)
            facts.push_back(facts.back() * i);
    }
    
    void gencombinations(vector<vector<int>>& combinations, vector<int>& store, vector<int>& combination, int& combind, int count, int storeind) {
        
        if(count == nK) {
            // cout << "combind: " << combind << endl;
            combinations[combind++] = combination;
            return;
        } 
        
        if(storeind == store.size())
            return;
        
        //leave
        gencombinations(combinations, store, combination, combind, count, storeind+1);
        
        //take
        combination[count] = store[storeind];
        gencombinations(combinations, store, combination, combind, count+1, storeind+1);
    }
    
    int dfs(vector<vector<int>>& graph, vector<int>& degree, int MASK) {
        
        if(MASK == 0)
            return 0;
        
        if(cache[MASK][degree])
            return cache[MASK][degree];
        
        vector<int> store;
        for(int i = 1; i <= N; i++) {
            if(degree[i] == 0 && (MASK & (1 << (i-1))))
                store.push_back(i);
        }
        
        int ndegrees = store.size();

        if(K >= ndegrees) {
            int nmask = MASK;
            vector<int> newdegree = degree;
            for(int& i: store) {
                nmask ^= (1 << (i-1));
                for(int& nex: graph[i])
                    newdegree[nex]--;
            }

            return cache[MASK][degree] = 1 + dfs(graph, newdegree, nmask);
        } 

        nK = min(ndegrees, K);
        int noofcombinations = facts[ndegrees]/(facts[nK] * facts[ndegrees-nK]);
        vector<vector<int>> combinations(noofcombinations, vector<int>(ndegrees));
        vector<int> combination(nK);
        int combind = 0;
        gencombinations(combinations, store, combination, combind, 0, 0);

        int ans = INT_MAX;
        for(auto& comb: combinations) {
            int nmask = MASK;
            vector<int> newdegree = degree;
            for(int& i: comb) {
                nmask ^= (1 << (i-1));
                for(int& nex: graph[i])
                    newdegree[nex]--;
            }

            ans = min(ans, 1 + dfs(graph, newdegree, nmask));
        }
        
        return cache[MASK][degree] = ans;
    }
    
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        
        vector<int> degree(n+1);
        vector<vector<int>> graph(n+1);
        K = k, N = n;
        cache.resize(1 << (n+1));

        genfacts(n);
        for(auto& i: relations) 
        {
            int u = i[0], v = i[1];
            graph[u].push_back(v);
            degree[v]++;
        }

        return dfs(graph, degree, (1 << n) - 1);    
    }
};