/*
https://leetcode.com/explore/featured/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3544/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* Solution 2 */
class Solution {
public:
    
    int longestSubstring(string s, int k) {
        
        int count[26] = {0};
        bool check[26] = {0};
        int unic = 0;
        
        for(char& c: s) // counting number of unique characters
            if(!check[c-'a']) {
                unic++;
                check[c-'a'] = 1;
            }
        
        int ans = 0;
        for(int curr = 1; curr <= unic; curr++) 
        {
            
            memset(count, 0, sizeof(count));
            int i = 0, j = 0, c, numunic = 0, thiscount = 0; /* 
                                                                i->left, j->right, numunic -> current number of unique characters
                                                                thiscount -> current count of characters appearings at least k times 
                                                            */
            while(j < s.size()) {
                if(numunic <= curr) {
                    
                    c = s[j++]-'a';
                    if(count[c]++ == 0) numunic++;
                    if(count[c] == k) thiscount++;
                    
                } else {
                    
                    c = s[i++] - 'a';
                    if(count[c]-- == k) thiscount--;
                    if(count[c] == 0) numunic--;
                    
                }
                
                if(numunic == curr && numunic == thiscount) /*
                                                                if no. of unique characters is equal to curr and 
                                                                is equal to no. of chars appearing at least k times 
                                                                then update the ans.
                                                            */
                    ans = max(ans, j-i);
            }
        }
        
        return ans;        
    }
};


/* Solution 1 */
class Solution
{
public:
    int helper(string &s, int k, int l, int r)
    {
        if (r < l || r < k)
            return 0;

        int arr[26] = {0};

        for (int i = l; i < r; i++)
            arr[s[i] - 'a']++;

        for (int m = l; m < r; m++)
        {


            if (arr[s[m] - 'a'] < k)
            {

                int frst = helper(s, k, l, m);
                while (m < r && arr[s[m] - 'a'] < k)
                    m++;

                return max(frst, helper(s, k, m, r));
            }
        }

        return r - l;
    }

    int longestSubstring(string s, int k)
    {
        return helper(s, k, 0, s.size());
    }
};
