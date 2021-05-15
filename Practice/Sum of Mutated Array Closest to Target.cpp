/*
https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//sort O(nlogn)
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0, minval = INT_MAX, maxval = INT_MIN;
        for(int& i: arr) {
            sum += i;
            if(i > maxval)
                maxval = i;
            if(i < minval)
                minval = i;
        }
        
        int n = arr.size();
        if(target < minval*n) {
            float val = 1.0*target/n;
            int val1 = ceil(val);
            int val2 = floor(val);
            
            return abs(val1*n-target) < abs(val2*n-target) ? val1: val2;
            
        } else if(target >= sum) {
            return maxval;
        }
        
        //find the best number
        sort(arr.begin(), arr.end());
        int thissum = 0;
        for(int& i: arr) {
            if(target <= (i*(n) + thissum))
                return round((target-thissum-0.00001)/n);
            
            thissum += i;
            n--;
        }
        
        return arr.back();
    }
};

//binary search O(n) + O(nlog(MAX))
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0, minval = INT_MAX, maxval = INT_MIN;
        for(int& i: arr) {
            sum += i;
            if(i > maxval)
                maxval = i;
            if(i < minval)
                minval = i;
        }
        
        int n = arr.size();
        if(target < minval*n) {
            float val = 1.0*target/n;
            int val1 = ceil(val);
            int val2 = floor(val);
            
            return abs(val1*n-target) < abs(val2*n-target) ? val1: val2;
            
        } else if(target >= sum) {
            return maxval;
        }
        
        //find the best number
        
        int l = minval, r = maxval;
        
        while(l < r) {
            int m = (l + r)/2;
            int thissum = 0;
            for(int& i: arr)
                thissum += i < m ? i : m;
            
            if(thissum == target)
                return m;
            else if(thissum > target)
                r = m;
            else
                l = m+1;
        }
        
        int val1 = 0, val2 = 0;
        for(int& i: arr) 
            val1 += i < l ? i : l;

        for(int& i: arr)
            val2 += i < l-1 ? i : l-1;
        
        if(abs(val1-target) < abs(val2-target))
            return l;
        return l-1;
    }
};

//naive O(nlogn) + O(MAX)
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum = 0, minval = INT_MAX, maxval = INT_MIN;
        for(int& i: arr) {
            sum += i;
            if(i > maxval)
                maxval = i;
            if(i < minval)
                minval = i;
        }
        
        int n = arr.size();
        if(target < minval*n) {
            float val = 1.0*target/n;
            int val1 = ceil(val);
            int val2 = floor(val);
            
            return abs(val1*n-target) < abs(val2*n-target) ? val1: val2;
            
        } else if(target >= sum) {
            return maxval;
        }
        
        sort(arr.begin(), arr.end());
        int val = arr[0], count = n, ans = -1, diff = INT_MAX, thissum = 0;
        for(int i = 0; i < n; ) {
            if(val == arr[i]) {
                count--;
                thissum += arr[i];
                i++;
            } else if(val > arr[i]) {
                while(i < n && arr[i] < val)
                    thissum += arr[i], count--, i++;
            }
            
            int newval = abs(target-(thissum + count*val));
            if(newval < diff) {
                diff = newval;
                ans = val;
            }
            val++;
        }
        
        return ans;
    }
};
