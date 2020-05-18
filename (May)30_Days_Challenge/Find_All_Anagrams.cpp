// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

//Second Method(Passed)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> parr(26);
        vector<int> sarr(26);
        
        vector<int> output;
        
        int plength = p.length();
        int slength = s.length();
        
        if(s.length() < p.length())
        {
            return output;
        }
        
        for(int i = 0; i < plength; i++)
        {
            parr[p[i]-'a']++;
            sarr[s[i]-'a']++;
        }
        
        if(parr == sarr) //We can compare vectors directly unlike arrays
        {
            output.push_back(0);
        }
        
        for(int i = plength; i < slength; i++)
        {
            sarr[s[i]-'a']++;
            sarr[s[i-plength]-'a']--;
            
            if(parr == sarr)
            {
                output.push_back(i-plength+1);
            }
        }
        
        return output;
    }
};

//First Method(34/36 cases passed, 2 TLE)
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int plength = p.length();
        int slength = s.length();

        unordered_map<char, int> pmap;
        for (int i = 0; i < plength; i++)
        {
            pmap[p[i]]++;
        }

        vector<int> output;
        for (int i = 0; i < slength - plength + 1; i++)
        {
            bool flag = true;
            unordered_set<char> store;
            unordered_map<char, int> smap;
            for (int j = i; j < i + plength; j++)
            {
                smap[s[j]]++;
                store.insert(s[j]);
            }

            for (auto iter = store.begin(); iter != store.end(); iter++)
            {
                if (smap[*iter] != pmap[*iter])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                output.push_back(i);
            }
        }

        return output;
    }
};