// In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

// If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

// Example 4:

// Input: N = 3, trust = [[1,2],[2,3]]
// Output: -1
// Example 5:

// Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
// Output: 3

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int trusts[1005];
        int trusted[1005];
        
        memset(trusts, 0, sizeof(trusts));
        memset(trusted, 0, sizeof(trusted));
        
        for(int i = 0; i < trust.size(); i++)
        {
            trusts[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        
        for(int i = 1; i <= N; i++)
        {
            if(trusts[i] == 0 && trusted[i] == N-1)
            {
                return i;
            }
        }
        
        return -1;
    }
};