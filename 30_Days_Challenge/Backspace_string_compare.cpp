// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> mystack1;
        stack<char> mystack2;

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] != '#')
            {
                mystack1.push(S[i]);
            }
            else if (mystack1.size() != 0)
                mystack1.pop();
        }

        for (int i = 0; i < T.length(); i++)
        {
            if (T[i] != '#')
            {
                mystack2.push(T[i]);
            }
            else if (mystack2.size() != 0)
                mystack2.pop();
        }

        bool ans = true;

        if (mystack1.size() != mystack2.size())
        {
            ans = false;
        }
        else
            while (mystack1.size() != 0 && mystack2.size() != 0)
            {
                if (mystack1.top() == mystack2.top())
                {
                    mystack1.pop();
                    mystack2.pop();
                }
                else
                {
                    ans = false;
                    break;
                }
            }
        return ans;
    }
};