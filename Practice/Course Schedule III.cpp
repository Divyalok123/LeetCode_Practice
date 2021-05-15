/*
https://leetcode.com/problems/course-schedule-iii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int total = 0, n = courses.size(), count = 0;
        
        vector<array<int, 2>> cc(n);
        for(int i = 0; i < n; i++)
            cc[i] = {courses[i][1], courses[i][0]};
        
        sort(cc.begin(), cc.end());
        
        priority_queue<int> pq;
        for(auto& i: cc) {
            if(total + i[1] <= i[0]) {
                total += i[1];
                pq.push(i[1]);
                count++;
            } else if(pq.size() && pq.top() > i[1]) {
                if(total - pq.top() + i[1] <= i[0])
                {
                    total -= pq.top();
                    pq.pop();
                    pq.push(i[1]);
                    total += i[1];
                }
            }
        }
        return count;
    }
};