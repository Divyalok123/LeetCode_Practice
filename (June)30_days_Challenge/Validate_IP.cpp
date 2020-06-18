// Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
// IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;
// Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.
// IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).
// However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.
// Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.
// Note: You may assume there is no extra space or special characters in the input string.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

//------------------------------------------------- solution 2 -------------------------------------------------------
class Solution
{
public:
    string validIPAddress(string IP)
    {
        return isIP4(IP) ? "IPv4" : (isIP6(IP) ? "IPv6" : "Neither");
    }

private:
    bool isIP4(string IP)
    {
        if (count(IP.begin(), IP.end(), '.') != 3)
            return false;

        vector<string> v = toVector(IP, '.');
        if (v.size() != 4)
            return false;

        for (string s : v)
        {
            if (s.empty() || s.size() > 3 || (s[0] == '0' && s.size() > 1))
                return false;

            for (char c : s)
                if (!isdigit(c))
                    return false;
            if (s.compare("256") >= 0)
                return false;
        }
        return true;
    }

    bool isIP6(string IP)
    {
        if (count(IP.begin(), IP.end(), ':') != 7)
            return false;

        vector<string> v = toVector(IP, ':');
        if (v.size() != 8)
            return false;

        for (string s : v)
        {
            if (s.empty() || s.size() > 4)
                return false;

            for (char c : s)
            {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F'))
                    return false;
            }
        }
        return true;
    }

    vector<string> toVector(string IP, char c)
    {
        vector<string> output;
        stringstream str(IP);
        string s;

        while (getline(str, s, c))
            output.push_back(s);

        return output;
    }
};

//----------------------------------------------- solution 1 ------------------------------------------------------
class Solution
{
public:
    string validIPAddress(string IP)
    {
        string four = "IPv4", six = "IPv6", ne = "Neither";
        int size = IP.size();
        int x;
        for (int i = 0; i < size; i++)
        {
            if (IP[i] == ':')
            {
                x = 1;
                break;
            }

            if (IP[i] == '.')
            {
                x = 0;
                break;
            }
        }

        int count = 0;
        int count2 = 0;
        int i = 0;
        if (x == 0)
        {
            if (IP[0] == '0')
                return ne;
            string s = "";
            while (i < size)
            {
                if (IP[i] == '.')
                {
                    count2++;
                    if (i == size - 1)
                        return ne;
                    if (s.compare("256") >= 0)
                        return ne;
                    if (count == 0 || count > 3)
                        return ne;
                    if (IP[i + 1] == '0' && IP[i + 2] != '.')
                    {
                        return ne;
                    }
                    count = 0;
                    i++;
                    s = "";
                }
                else
                {
                    if (!isdigit(IP[i]))
                        return ne;
                    s.push_back(IP[i]);
                    count++;
                    i++;
                }
            }
            if (count == 0 || count > 3 || count2 != 3)
                return ne;
            return four;
        }

        else
        {
            while (i < size)
            {
                if (IP[i] == ':')
                {
                    count2++;
                    if (i == size - 1)
                        return ne;
                    if (count == 0 || count > 4)
                        return ne;
                    count = 0;
                    i++;
                }
                else
                {
                    if (!isdigit(IP[i]) && (!isalpha(IP[i]) || toupper(IP[i]) > 'F'))
                        return ne;
                    count++;
                    i++;
                }
            }
            if (count > 4 || count == 0 || count2 != 7)
                return ne;
            return six;
        }
    }
};