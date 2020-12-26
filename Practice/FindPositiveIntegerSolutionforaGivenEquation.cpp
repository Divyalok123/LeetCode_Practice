/*
https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class CustomFunction {
public:
    int f(int x, int y);
};

/* Solution 2 */
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int l, m, j = z, v;
        for(int i = 1; i <= z; i++) {
            if(customfunction.f(i, 1) > z) 
                break;
            l = 1;
            while(l <= j) {
                m = (l+j)/2;
                v = customfunction.f(i, m);   
                if(v == z) 
                {
                    ans.push_back({i, m});
                    break;
                }
                else if(v > z) j = m-1;
                else l = m+1;
            }
        }
        return ans;
    }
};

/* Solution 1 */
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int i = 1, j = z;
        while(i <= z && j >= 1) {
            int v = customfunction.f(i, j);
            if(v == z) ans.push_back({i++, j--});
            else if(v > z) j--;
            else i++;
        }
        return ans;
    }
};