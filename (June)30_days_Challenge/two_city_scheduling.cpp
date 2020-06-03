// There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].
// Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size = costs.size();
        nth_element(begin(costs), begin(costs)+size/2, end(costs), [](vector<int>& a, vector<int>& b) { return a[1]-a[0] > b[1]-b[0];});
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            if(i < (size/2)) sum += costs[i][0];
            else sum += costs[i][1];
        }
        return sum;
    }
};