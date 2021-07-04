#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


#define MOD 1000000007
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>> buyorders;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> sellorders;
        
        for(auto& i: orders) {
            int price = i[0], amount = i[1], type = i[2];
            if(type == 0) { //buy
                
                while(amount && sellorders.size() && sellorders.top().first <= price) {
                    if(sellorders.top().second > amount) {
                        int newamount = sellorders.top().second-amount;
                        int val = sellorders.top().first;
                        sellorders.pop();
                        sellorders.push({val, newamount});
                        amount = 0;
                    } else if(sellorders.top().second == amount) {
                        sellorders.pop();
                        amount = 0;
                    } else {
                        amount -= sellorders.top().second;
                        sellorders.pop();
                    }
                }
                
                if(amount) {
                    buyorders.push({price, amount});
                }
                
            } else { //sell
                while(amount && buyorders.size() && buyorders.top().first >= price) {
                    if(buyorders.top().second > amount) {
                        int newamount = buyorders.top().second-amount;
                        int val = buyorders.top().first;
                        buyorders.pop();
                        buyorders.push({val, newamount});
                        amount = 0;
                    } else if(buyorders.top().second == amount) {
                        buyorders.pop();
                        amount = 0;
                    } else {
                        amount -= buyorders.top().second;
                        buyorders.pop();
                    }
                }
                
                if(amount) {
                    sellorders.push({price, amount});
                }
            }
        }
        
        int ans = 0;
        while(buyorders.size()) {
            ans = (ans + buyorders.top().second)%MOD;
            buyorders.pop();
        }
        
        while(sellorders.size()) {
            ans = (ans + sellorders.top().second)%MOD;
            sellorders.pop();
        }
        
        return ans;
    }
};