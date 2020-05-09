// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) { // c -> coordinates
        
        if(c.size() == 2)
        {
            return true;
        }
        
        int x = c[1][0] - c[0][0];
        int y = c[1][1] - c[0][1];
    
        for(int i = 2; i < c.size(); i++)
        {
            vector<int> v = c[i];
            if(x*(v[1] - c[0][1]) != y*(v[0] - c[0][0]))
                return false;
        }
        
        return true;
    }
    
};