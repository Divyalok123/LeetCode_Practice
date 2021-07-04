#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if(n == maxSum) return 1;
        long long ans = 0;
        
        maxSum -= n;
        
        long long left = 0, right = maxSum;
        
        while(left <= right) {
            long long mid = (left + right)/2;
            // cout << "mid: " << mid;
            long long m = mid-1;
            // cout << " m: " << m;
            long long val1 = (m)*(m+1)/2ll - (index >= m ? 0 : (m-index)*(m-index+1)/2);
            long long diff = n-index-1;
            long long val2 = (m)*(m+1)/2 - (diff >= m ? 0 : (m-diff)*(m-diff+1)/2);
            // cout << " val1: " << val1 << " val2: " << val2 << endl;
            if(val1 + val2 <= (maxSum-mid)) {
                ans = max(ans, mid);
                if(val1 + val2 == maxSum) break;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        return (int)(ans+1);
    }
};
