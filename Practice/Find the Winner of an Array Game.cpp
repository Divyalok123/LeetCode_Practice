/*
https://leetcode.com/problems/find-the-winner-of-an-array-game/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Improved O(1) space - Once the ele touches the max no one can beat it so no need to push the elements
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k >= n)
            return *max_element(arr.begin(), arr.end());
        
        int i = 1, count = 0, ele = arr[0];        
        while(i < n) {
            if(ele < arr[i]) {
                arr.push_back(ele);
                count = 0;
                ele = arr[i];
            }
            
            i++, count++;
            if(count == k)
                return ele;
        }
        
        return ele;
    }
};

// O(n) - Takes extra space (O(n))
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k >= n)
            return *max_element(arr.begin(), arr.end());
        
        int i = 1, count = 0, ele = arr[0];        
        while(1) {
            if(ele < arr[i]) {
                arr.push_back(ele);
                count = 1;
                ele = arr[i];
            } else {
                arr.push_back(arr[i]);
                count++;
            }      
            
            i++;
            if(count == k)
                return ele;
        }
        
        return -1;
    }
};