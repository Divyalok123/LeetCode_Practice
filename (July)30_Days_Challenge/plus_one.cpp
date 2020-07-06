// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        if (n == 0)
            return {1};

        int sum = digits[n - 1] + 1;
        digits[n - 1] = (sum) % 10;
        int carry = sum / 10;
        for (int i = n - 2; i >= 0; i--)
        {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;

            if (carry == 0)
                break;
        }

        if (carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};