/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  
If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T 
(possibly 0, and the characters are chosen anywhere from T) results in the string S.)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/* SOlution 2 */
class Solution
{
public:
    string shortestCommonSupersequence(string &a, string &b)
    {
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        string ans;
        int i = n, j = m;
        while ((i > 0) && (j > 0))
        {
            if (a[i - 1] == b[j - 1])
            {
                ans.push_back(a[i - 1]);
                i--, j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    ans.push_back(a[i - 1]), i--;
                else
                    ans.push_back(b[j - 1]), j--;
            }
        }

        while (i > 0)
        {
            ans.push_back(a[i - 1]);
            i--;
        }

        while (j > 0)
        {
            ans.push_back(b[j - 1]);
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/* Solution 1 */
class Solution
{
public:
    int n, m;
    string lcs(string &a, string &b)
    {
        if (a.size() == 0 || b.size() == 0)
            return "";

        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + string(1, a[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
        return dp[n][m];
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        if (str1.size() == 0 || str2.size() == 0)
            return str1.size() == 0 ? str2 : str1;

        n = str1.size(), m = str2.size();

        //first find the LCS (longest common subsequence)
        string lcsval = lcs(str1, str2);
        // cout << "lcs: " << lcsval << endl;

        //then form the supersequence from above info
        string ans;
        int i = 0, j = 0, k = 0;
        while (i < lcsval.size())
        {
            while (j < str1.size() && str1[j] != lcsval[i])
                ans.push_back(str1[j++]);
            while (k < str2.size() && str2[k] != lcsval[i])
                ans.push_back(str2[k++]);
            ans.push_back(lcsval[i++]);
            j++, k++;
        }

        return ans + str1.substr(j) + str2.substr(k);
    }
};
