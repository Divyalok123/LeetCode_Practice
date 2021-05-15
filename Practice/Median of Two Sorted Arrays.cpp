/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//binary search (required solution) O(log(min(n, m)))
class Solution {
public:
    double med(vector<int>& v, int n) {
        return (n&1) ? v[n/2] : (v[n/2] + 1.0*v[n/2-1])/2;
    }
    
    double binary(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m, av = (m+n+1)/2;
        while(l <= r) {
            int mid = (l + r)/2;
            int smid = av - mid; 

            if(mid > 0 && nums1[mid-1] > nums2[smid])
                r = mid-1;
            else if(mid < m && nums2[smid-1] > nums1[mid])
                l = mid+1;
            else {
                int left = -1, right = -1;
                if(mid == 0) left = nums2[smid-1];
                else if(smid == 0) left = nums1[mid-1];
                else left = max(nums1[mid-1], nums2[smid-1]);
                
                if((m+n)&1) 
                    return left;
                
                if(mid == m) right = nums2[smid];
                else if(smid == n) right = nums1[mid];
                else right = min(nums1[mid], nums2[smid]);
                return (left + right)*1.0/2;
            }
        }
        
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();

        if(n == 0)
            return med(nums1, m);
        
        if(m == 0)
            return med(nums2, n);
            
        return n >= m ? binary(nums1, nums2) : binary(nums2, nums1); 
    }
};

//improving the naive sol (Merge instead of sort)
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    double med(vector<int>& v, int n) {
        return (n&1) ? v[n/2] : (v[n/2] + 1.0*v[n/2-1])/2;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if(n == 0)
            return med(nums2, m);
        
        if(m == 0)
            return med(nums1, n);
        
        vector<int> newv(n+m);
        int i = 0, j = 0, k = 0;
        while(i < n || j < m) {
            if(i == n)
                newv[k++] = nums2[j++];
            else if (j == m)
                newv[k++] = nums1[i++];
            else if(nums1[i] < nums2[j]) 
                newv[k++] = nums1[i++];
            else
                newv[k++] = nums2[j++];
        }
        
        return med(newv, n+m);    
    }
};

//naive brute force solution
class Solution {
public:
    double med(vector<int>& v, int n) {
        return (n&1) ? v[n/2] : (v[n/2] + 1.0*v[n/2-1])/2;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        if(n == 0)
            return med(nums2, m);
        
        if(m == 0)
            return med(nums1, n);
        
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        
        int nn = n+m;
        return med(nums1, nn);    
    }
};