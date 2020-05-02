// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//Using unordered_map
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> mapper;
        for(int i = 0; i < J.size(); i++){
            mapper[J[i]] = 1;
        }
        
        int count = 0;
        for(int i = 0; i < S.size(); i++)
            
        {
            if(mapper[S[i]])
            {
                count++;
            }
        }
        
        return count;
    }
};

//Using unordered_set
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> myset;
        for(int i = 0; i < J.size(); i++){
            myset.insert(J[i]);
        }
        
        int count = 0;
        for(int i = 0; i < S.size(); i++)
            
        {
            if(myset.count(S[i]))
            {
                count++;
            }
        }
        
        return count;
    }
};
