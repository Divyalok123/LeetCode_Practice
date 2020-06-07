// Suppose you have a random list of people standing in a queue.
// Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
// Write an algorithm to reconstruct the queue.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//solution 2
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        vector<vector<int>> v;
        
        for(int i = 0; i < size; i++)
        {
            v.insert(v.begin()+people[i][1], {people[i][0], people[i][1]});
        }
        
        return v;
    }
};

//solution 1
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        int size = people.size();
        sort(people.begin(), people.end());

        vector<vector<int>> v(size, vector<int>(2, -1));

        for (int i = 0; i < size; i++)
        {
            int count = people[i][1];
            for (int j = 0; j < size; j++)
            {
                if (count == 0 && v[j][0] == -1)
                {
                    v[j][0] = people[i][0];
                    v[j][1] = people[i][1];
                    break;
                }
                else if (v[j][0] == -1 || v[j][0] >= people[i][0])
                    count -= 1;
            }
        }

        return v;
    }
};