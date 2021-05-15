/*
https://leetcode.com/problems/product-of-the-last-k-numbers/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class ProductOfNumbers {
    vector<int> v;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) 
            v = {};
        else
            v.push_back(num*(v.size() ? v.back() : 1));
    }
    
    int getProduct(int k) {
        int n = v.size();
        if(k > n)
            return 0;
        return v.back()/(n > k ? v[n-k-1] : 1);
    }
};
