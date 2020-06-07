// You are given coins of different denominations and a total amount of money.
// Write a function to compute the number of combinations that make up that amount. 
// You may assume that you have infinite number of each kind of coin.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//dp
class Solution {

public:
    
    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> output(amount+1, vector<int>(size+1, 1));
        
        int a, b;
        
        for(int i = 1; i <= amount; i++)
        {
            output[i][0] = 0;
        }
        
        for(int i = 1; i <= amount; i++)
            for(int j = 1; j <= size; j++)
            {
                a = output[i][j-1];
                b = (coins[j-1] <= i) ? output[i - coins[j-1]][j] : 0;
                output[i][j] = a + b;
            }
        
        return output[amount][size];
    }
};


//memo
class Solution {

public:
    int memo(int amount, vector<int>& coins, vector<vector<int>>& output)
    {
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        
        if(amount > 0 && coins.size() <= 0) return 0;
        int size = coins.size();
        if(output[amount][size] != -1) return output[amount][size];
        int a = 0, b = 0;
        vector<int> v(coins.begin(), coins.end()-1);
        a = memo(amount, v, output);
        if(coins.back() <= amount) 
            b = memo(amount-coins.back(), coins, output);
        output[amount][size] = a + b;
        return a+b;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> output(amount+1, vector<int>(coins.size()+1, -1));
        return memo(amount, coins, output);
    }
};
