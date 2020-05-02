// Given two strings text1 and text2, return the length of their longest common subsequence.

// A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

// If there is no common subsequence, return 0.

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
//     int helper(string text1, string text2, int** arr)
//     {
//         int len1 = text1.length();
//         int len2 = text2.length();
//         if(len1 == 0 || len2 == 0) return 0;
//         if(arr[len1][len2] != -1) return arr[len1][len2];
//         int ans;
//         if(text1[0] == text2[0]) 
//             ans = 1 + helper(text1.substr(1), text2.substr(1), arr);
//         else
//         {
//             // int x = helper(text1.substr(1), text2.substr(1), arr);
//             int y = helper(text1.substr(1), text2, arr);
//             int z = helper(text1, text2.substr(1), arr);
//             ans = max(y, z);
//         }
        
//         arr[len1][len2] = ans;
//         return ans;
//     }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        int** arr = new int*[len1+1];
        for(int i = 0; i <= len1; i++)
        {
            arr[i] = new int[len2 + 1];
            for(int j = 0; j <= len2; j++)
            {
                arr[i][j] = -1;
            }
        }
        
        for(int i = 0; i <= len1; i++)
        {
            arr[i][0] = 0;
        }
        
        for(int j = 0; j <= len2; j++)
        {
            arr[0][j] = 0;
        }
        
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                int ans;
                if(text1[i-1] == text2[j-1]) 
                {
                    arr[i][j] = 1 + arr[i-1][j-1];
                }
                else
                {
                    int x = arr[i-1][j-1];
                    int y = arr[i-1][j];
                    int z = arr[i][j-1];
                    arr[i][j] = max(x, max(y, z));
                }
            }
        }
        
        int ans = arr[len1][len2];
        for(int i = 0; i <= len1; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        return ans;
    }
};