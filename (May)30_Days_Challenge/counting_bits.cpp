// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//Solution 3 (fastest)
class Solution {
public:
    vector<int> countBits(int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int> output(num + 1);
        output[0] = 0;
        for(int i = 1; i <= num; i++)
        {
            output[i] = output[i&(i-1)] + 1;
        }
        
        return output;
    }
};

//Solution 2 
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> output(num + 1);
        output[0] = 0;
        for(int i = 1; i <= num; i++)
        {
            output[i] = output[i/2] + i%2;
        }
        
        return output;
    }
};


//Solution 1
class Solution {
public:
    int addone(vector<int>& v)
    {
        int carry = 1;
        int i = v.size()-1;
        
        while(carry && i >= 0)
        {
            if(v[i] == 0) 
            { 
                carry = 0;
                v[i] = 1;
            }
            else
            {
                v[i] = 0;
                carry = 1;
            }
            i--;
        }
        
        if(carry)
        {
            v.push_back(0);
            for(int k = v.size()-1; k >= 1; k--)
            {
                v[k] = v[k-1];
            }
            v[0] = 1;
            return 1;
        }
        
        int count = 0;
        for(int m = 0; m < v.size(); m++)
        {
            if(v[m] == 1) count++;
        }
        
        return count;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if(num == 0) return ans;
        ans.push_back(1);
        if(num == 1) return ans;
        
        vector<int> v;
        v.push_back(1);
        int i = 1;
        while(i < num)
        {
            int a = addone(v);
            ans.push_back(a);
            i++;
        }
        
        return ans;
    }
};