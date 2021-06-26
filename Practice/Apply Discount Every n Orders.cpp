/*
https://leetcode.com/problems/apply-discount-every-n-orders/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cashier {
    int n;
    double discount;
    int count;
    int pricebyid[201];
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->count = 0;
        this->discount = (discount*1.0)/100;
        
        int sz = products.size();
        for(int i = 0; i < sz; i++)
            pricebyid[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double sum = 0;
        for(int i = 0; i < product.size(); i++) {
            double val = pricebyid[product[i]];
            sum += val * amount[i];
        }
        
        if(count == n) {
            sum -= (sum * discount);
            count = 0;
        }
        
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */