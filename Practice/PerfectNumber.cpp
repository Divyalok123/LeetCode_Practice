/*
https://leetcode.com/problems/perfect-number/
*/

#include <iostream>
using namespace std;

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;

        if (num % 2)
            return false;

        int sum = 1;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                if (i != (num / i))
                    sum += i + (num / i);
                else
                    sum += i;
            }
        }
        cout << "Sum: " << sum << endl;
        return sum == num;
    }
};
