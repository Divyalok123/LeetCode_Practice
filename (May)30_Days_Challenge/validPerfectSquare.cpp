// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i =1; (long long int)i*i <= num; i++)
        {
            if(num%i == 0 && num/i == i)
                return true;
        }
        
        return false;
    }
};