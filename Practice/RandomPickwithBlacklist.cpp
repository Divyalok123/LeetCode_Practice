/*
https://leetcode.com/problems/random-pick-with-blacklist/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
using namespace std;

class Solution {
    int NN;
    mt19937 mtr;
    uniform_int_distribution<> uid;
    unordered_map<int, int> umap;
public:
    Solution(int N, vector<int>& blacklist) {
        for(auto& a: blacklist) {
            umap[a] = -1;
        }
        
        NN = N-blacklist.size();
        N--;
        std::random_device rd;
        mtr = mt19937(rd());
        uid = uniform_int_distribution<>(0, NN-1);
        for(auto& a: blacklist) {
            if(a < NN) {
                while(umap.find(N) != umap.end())
                    N--;
                umap[a] = N;
                N--;
            }
        }
    }
    
    int pick() {
        int pic = uid(mtr);
        if(umap.find(pic) != umap.end())
            return umap[pic];
        return pic;
    }
};
