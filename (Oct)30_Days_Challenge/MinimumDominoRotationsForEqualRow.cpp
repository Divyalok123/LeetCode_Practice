/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3500/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ff first
#define ss second
#define MAX INT_MAX
#define pii pair<int, pair<int,int>>

/* Solution 2 */
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a = A[0], b = B[0], l = 1, m = 0, n = 0, o = 1;
        for(int i = 1; i < A.size(); i++) {
            if(A[i] != a && B[i] != a) a = 0;
            if(A[i] != b && B[i] != b) b = 0;
            if((a==0) && (b==0)) 
                return -1;
            l += (a == A[i]);
            m += (b == A[i]);
            n += (a == B[i]);
            o += (b == B[i]);
        }
        return min(A.size()-max(l, m), A.size()-max(n, o));
    }
};

/* Solution 1 */
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<pii> mm(7, {0, {0, 0}});
        pii m;
        int minval = MAX;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] != B[i])
                mm[A[i]].ss.ff++, mm[B[i]].ss.ss++;
            else 
                mm[A[i]].ff++;
        }
        
        for(int i = 1; i < 7; i++) {
            m = mm[i];
            if((m.ff + m.ss.ff + m.ss.ss) >= n)
                minval = min(minval, min(m.ss.ff, m.ss.ss));
        }
        
        return minval == MAX ? -1 : minval;
    }
};