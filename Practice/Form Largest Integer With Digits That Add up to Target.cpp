/*
https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// bottom-up dp
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> cache(target + 1, -1);
        vector<int> trace(target + 1);
        cache[0] = 0;
        for(int i = 1; i <= target; i++) {
            for(int j = 9; j >= 1; j--) {
                int c = cost[j-1];
                if(c <= i && cache[i-c] != -1 && cache[i] < cache[i-c] + 1) {
                    cache[i] = cache[i-c] + 1;
                    trace[i] = j;
                }
            }
        }
        
//         cout << "cache" << endl;
//         for(int& i: cache)
//             cout << i << " ";
//         cout << endl;
        
//         cout << "trace" << endl;
//         for(int& i: trace)
//             cout << i << " ";
//         cout << endl;
        
        if(cache[target] == -1) return "0";
        
        int ans = cache[target];
        string fans(ans, '-');
        int i = 0;
        // cout << "here" << endl;
        while(i < ans && target > 0) {
            fans[i++] = '0' + trace[target];
            target -= cost[trace[target]-1];
        }
        // cout << "ends" << endl;
        return fans;
    }
};

//improving to O(target) time using a trace array to store which character we used at every point
class Solution {
public:
    vector<int> cache;
    vector<int> trace;
    int dfs(vector<int>& cost, int currsum, int target) {
        if(currsum == target)
            return 0;
        
        if(cache[currsum] != -2)
            return cache[currsum];
        
        int ans = -1;
        for(int i = 8; i >= 0; i--) {
            if(currsum + cost[i] <= target) {
                int thiss = dfs(cost, currsum + cost[i], target);
                if(thiss != -1 && thiss + 1 > ans) {
                    ans = thiss + 1;
                    trace[currsum] = i + 1;
                }
            }
        }
        
        return cache[currsum] = ans;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        cache.resize(target + 1, -2);
        trace.resize(target + 1);
        int ans = dfs(cost, 0, target);
        if(ans == -1) return "0";
        string fans(ans, '-');
        int i = 0, sum = 0;
        while(sum < target) {
            fans[i++] = '0' + trace[sum];
            sum += cost[trace[sum]-1];
        }
        
        return fans;
    }
};

// naive top down dp - O(target * target) 
class Solution {
public:
    vector<string> cache;
    string dfs(vector<int>& cost, int currsum, int target) {
        if(currsum == target)
            return "";
        
        if(cache[currsum] != "-")
            return cache[currsum];
        
        string ans = "0";
        for(int i = 8; i >= 0; i--) {
            if(currsum + cost[i] <= target) {
                string c = to_string(i + 1);
                string thiss = dfs(cost, currsum + cost[i], target);
                if(thiss == "0") continue;
                thiss = c + thiss;
                if(ans == "0" || thiss.size() > ans.size())
                    ans = thiss;
            }
        }
        
        return cache[currsum] = ans;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        cache.resize(target+1, "-");
        string ans = dfs(cost, 0, target);
        return ans;
    }
};