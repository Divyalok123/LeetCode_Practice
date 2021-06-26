/*
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// priority_queue - O(n)
static int fio = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        
        for(int& i: nums) {
            if(maxpq.size() < 4) 
                maxpq.push(i);
            else if(maxpq.size() == 4 && maxpq.top() > i) {
                maxpq.pop();
                maxpq.push(i);
            } 
            
            if(minpq.size() < 4)
                minpq.push(i);
            else if(minpq.size() == 4 && minpq.top() < i) {
                minpq.pop(), minpq.push(i);
            }
        }
        
        int a = maxpq.top(); maxpq.pop();
        int b = maxpq.top(); maxpq.pop();
        int c = maxpq.top(); maxpq.pop();
        int d = maxpq.top(); maxpq.pop();
        
        int e = minpq.top(); minpq.pop();
        int f = minpq.top(); minpq.pop();
        int g = minpq.top(); minpq.pop();
        int h = minpq.top(); minpq.pop();
        
        return min({h-a, g-b, f-c, e-d});
    }
};

// naive sorting and checking - O(nlogn)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        
        int curr = min(nums.back()-nums[3], nums[n-4]-nums.front());   
        curr = min(curr, nums[n-3]-nums[1]);
        curr = min(curr, nums[n-2]-nums[2]);
        curr = min(curr, nums[n-1]-nums[3]);
        return curr;
    }
};