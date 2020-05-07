// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//Way 1
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ransommap;
        unordered_map<char, int> magazinemap;

        for (int i = 0; i < ransomNote.size(); i++)
        {
            ransommap[ransomNote[i]]++;
        }

        for (int i = 0; i < magazine.size(); i++)
        {
            magazinemap[magazine[i]]++;
        }

        bool ans = true;
        for (auto i : ransommap)
        {
            if (magazinemap[i.first] < i.second)
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
};

//Way 2 (Better)
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magmap;
        for (int i = 0; i < magazine.size(); i++)
        {
            magmap[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            if (magmap[ransomNote[i]])
                magmap[ransomNote[i]]--;
            else
                return false;
        }

        return true;
    }
};