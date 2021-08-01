/*
https://leetcode.com/contest/weekly-contest-252/problems/minimum-garden-perimeter-to-collect-enough-apples/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    #define ll long long
    long long minimumPerimeter(long long neededApples) {
        ll total = 12;
        ll perim = 8;
        ll ind = 2;
        ll cnt = 1;
        while(total < neededApples) {
            total += ind * 4ll + ind * 4ll * 2ll + 8 * (cnt * (cnt + 1))/2 + ind * cnt * 8;
            ind++;
            cnt++;
            perim += 8ll;
        }
        
        return perim;
    }
};