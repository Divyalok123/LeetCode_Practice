/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3540/
*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    //morse code box
    string box[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> us;
        string s;
        for (string &word : words)
        {
            s = "";
            for (char &c : word)
                s += box[c - 'a'];
            us.insert(s);
        }
        return us.size();
    }
};