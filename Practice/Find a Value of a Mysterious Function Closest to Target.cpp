/*
https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// bit manipulation & sliding window - O(n) time and O(1) space
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    #define K 25
    
    void updateCount(int count[K], int ele, int val) {
        for(int i = K-1, MASK = (1 << (K-1)); i >= 0; i--, MASK >>= 1) {
            if(ele & MASK)
                count[i] += val;
        }
    }
    
    int getVal(int count[K], int numEle) {
        int ans = 0;
        if(numEle)
        for(int i = 0, MASK = 1; i < K; i++, MASK <<= 1)
            if(count[i] == numEle)
                ans |= MASK;
        
        return ans;
    }
    
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size(), ans = INT_MAX;
        int count[K] = {0};
        
        int l = 0, r = 0, thisval;
        while(r < n) {
            updateCount(count, arr[r], 1);
            thisval = getVal(count, r-l+1);
            ans = min(ans, abs(thisval-target));
            
            while(l <= r && thisval < target) {
                updateCount(count, arr[l], -1);
                thisval = getVal(count, r-l);
                ans = min(ans, abs(thisval-target));
                l++;
            }
            
            r++;
        }
        
        return ans;
    }
};

// Collecting all possible AND values -> O(nlog(max(arr)))
class Solution {
public:
    
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size(), ans = INT_MAX;
        
        unordered_set<int> store[n];
        store[n-1].insert(arr[n-1]);
        
        for(int i = n-2; i >= 0; i--) {
            store[i].insert(arr[i]);
            for(const auto& j: store[i+1])
                store[i].insert(arr[i]&j);
        }
        
        for(int i = 0; i < n; i++)
            for(const auto& j: store[i])
                if(abs(target-j) < ans)
                    ans = abs(target-j);
        return ans;
    }
};

// Sparse table - Build -> O(n), query -> O(1) - Overall -> O(nlogn)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    #define K 25
    vector<int> logg;
    vector<vector<int>> sparse;
    
    int query(int l, int r) {
        int j = logg[r-l+1];
        return sparse[l][j] & sparse[r - (1 << j) + 1][j];
    }
    
    int findmin(vector<int>& arr, int start, int end, int target) {
        int lenl = 1, lenr = end-start+1, ans = INT_MAX;
        
        while(lenl <= lenr) {
            int mid = (lenl + lenr)/2;
            
            int val = query(start, start+mid-1);
            
            ans = min(ans, abs(target-val));
            
            if(val == target)
                break;
            else if(val < target)
                lenr = mid-1;
            else
                lenl = mid+1;
        }
        
        return ans;
    }
    
    int closestToTarget(vector<int>& arr, int target) {
        int n = arr.size();
        logg.resize(n+1);
        sparse.resize(n, vector<int>(K+1));
        
        //computing logs
        logg[1] = 0;
        for(int i = 2; i <= n; i++)
            logg[i] = logg[i/2] + 1;
        
        //building sparse table
        for(int i = 0; i < n; i++)
            sparse[i][0] = arr[i];
        
        for(int j = 1; j <= K; j++) {
            for(int i = 0; i + (1 << j) <= n; i++)
                sparse[i][j] = sparse[i][j-1] & sparse[i + (1 << (j-1))][j-1];
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, findmin(arr, i, n-1, target));
            if(ans == 0) break;
        }
        
        return ans;
    }
};

// Segment Tree & Binary Search solution (barely passing) - Build, query => O(logn) - Overall -> O(nlognlogn)
class Solution {
public:
    int n, MAXN;
    vector<int> segTree;
    
    int query(int segind, int l, int r, int ql, int qr) {
        if(ql > qr)
            return (1 << 21)-1;
        
        if(ql == l && qr == r)
            return segTree[segind];
        
        int m = (l + r)/2;
        int left = query(2*segind+1, l, m, ql, min(qr, m));
        int right = query(2*segind+2, m+1, r, max(ql, m+1), qr);
        return left & right;
    }
    
    void buildTree(vector<int>& arr, int segind, int rangel, int ranger) {
        if(rangel > ranger)
            return;
        
        if(rangel == ranger) {
            segTree[segind] = arr[rangel];
            return;
        }
        
        int mid = rangel + (ranger-rangel)/2;
        buildTree(arr, 2*segind+1, rangel, mid);
        buildTree(arr, 2*segind+2, mid+1, ranger);
        
        segTree[segind] = segTree[segind*2 + 1] & segTree[segind*2 + 2];
    }
    
    int findmin(vector<int>& arr, int start, int end, int target) {
        int lenl = 1, lenr = end-start+1, ans = INT_MAX;
        
        while(lenl <= lenr) {
            int mid = (lenl + lenr)/2;
            
            int val = query(0, 0, end, start, start+mid-1);
            
            ans = min(ans, abs(target-val));
            
            if(val == target)
                break;
            else if(val < target)
                lenr = mid-1;
            else
                lenl = mid+1;
        }
        
        return ans;
    }
    
    int closestToTarget(vector<int>& arr, int target) {
        n = arr.size();
        MAXN = 4*(n+1);
        
        segTree.resize(MAXN+1);
        buildTree(arr, 0, 0, n-1);
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, findmin(arr, i, n-1, target));
            if(ans == 0) break;
        }
        
        return ans;
    }
};