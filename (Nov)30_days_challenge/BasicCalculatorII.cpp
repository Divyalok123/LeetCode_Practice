/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3542/
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/* Solution 3 (O(1) space)*/
class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        long sum = 0, num = 0, prev = 0;
        char lastop = '+';

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
                continue;

            else if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');

            else
            {

                switch (lastop)
                {
                case '+':
                    sum += prev;
                    prev = num;
                    break;
                case '-':
                    sum += prev;
                    prev = -num;
                    break;
                case '/':
                    prev /= num;
                    break;
                case '*':
                    prev *= num;
                    break;
                }

                num = 0;
                lastop = s[i];
            }
        }

        if (lastop == '+')
            sum += (prev + num);
        else if (lastop == '-')
            sum += (prev - num);
        else if (lastop == '*')
            sum += (prev * num);
        else
            sum += (prev / num);

        return (int)sum;
    }
};

/* Solution 3 (Using stack) */
class Solution
{
public:
    int calculate(string str)
    {
        int n = str.size();
        if (n == 0)
            return 0;

        stack<long> s;
        long num = 0, top;
        char last = '+';

        for (int i = 0; i < n; i++)
        {
            if (str[i] == ' ')
                continue;

            else if (isdigit(str[i]))
                num = num * 10 + (str[i] - '0');

            else
            {

                switch (last)
                {
                case '+':
                    s.push(num);
                    break;
                case '-':
                    s.push(-num);
                    break;
                case '*':
                    top = s.top();
                    s.pop();
                    s.push(top * num);
                    break;
                case '/':
                    top = s.top();
                    s.pop();
                    s.push(top / num);
                    break;
                }

                last = str[i];
                num = 0;
            }
        }

        if (last == '+')
            s.push(num);
        else if (last == '-')
            s.push(-num);
        else
        {
            top = s.top();
            s.pop();

            if (last == '*')
                s.push(top * num);
            else
                s.push(top / num);
        }

        num = 0;
        while (s.size())
        {
            num += s.top();
            s.pop();
        }

        return num;
    }
};

/* Solution 2 (Time improved sol 1) */
class Solution
{
public:
    int calc(int a, int b, char c)
    {
        if (c == '+')
            return a + b;
        if (c == '-')
            return a - b;
        if (c == '*')
            return a * b;
        return a / b;
    }

    int calculate(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> v(n / 2 + 1);
        vector<char> op(n / 2 + 1);
        int i = 0, ans = 0, num = 0, l = 0, m = 0;
        bool check = 0;
        while (i < n)
        {
            if (s[i] == ' ')
                i++;
            else if (!isdigit(s[i]))
            {
                if (s[i] == '*' || s[i] == '/')
                    check = 1;
                op[m++] = s[i++];
            }
            else
            {
                num = 0;
                while (i < n && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');

                if (check)
                {
                    check = 0;
                    num = calc(v[l - 1], num, op[m - 1]);
                    m--, l--;
                }

                v[l++] = num;
            }
        }

        int a, b;
        char c;
        while (m > 0)
        {
            c = op[m - 1], m--;
            a = v[l - 1], l--;
            b = v[l - 1], l--;
            if (m > 0 && op[m - 1] == '-')
            {
                b *= -1;
                op[m - 1] = '+';
            }
            v[l++] = calc(b, a, c);
        }

        return v[0];
    }
};

/* Solution 1 */
class Solution
{
public:
    int calc(int a, int b, char c)
    {
        if (c == '+')
            return a + b;
        if (c == '-')
            return a - b;
        if (c == '*')
            return a * b;
        return a / b;
    }

    int calculate(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> v;
        vector<char> op;
        int i = 0, ans = 0, num = 0;
        bool check = 0;
        while (i < n)
        {
            if (s[i] == ' ')
                i++;
            else if (!isdigit(s[i]))
            {
                if (s[i] == '*' || s[i] == '/')
                    check = 1;
                op.push_back(s[i++]);
            }
            else
            {
                num = 0;
                while (i < n && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');

                if (check)
                {
                    check = 0;
                    num = calc(v.back(), num, op.back());
                    op.pop_back();
                    v.pop_back();
                }

                v.push_back(num);
            }
        }

        int a, b;
        char c;
        while (op.size())
        {
            c = op.back();
            op.pop_back();
            a = v.back();
            v.pop_back();
            b = v.back();
            v.pop_back();
            if (op.size() && op.back() == '-')
            {
                b *= -1;
                op[op.size() - 1] = '+';
            }
            v.push_back(calc(b, a, c));
        }

        return v[0];
    }
};