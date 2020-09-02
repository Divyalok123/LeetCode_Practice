/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/553/week-5-august-29th-august-31st/3441/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pancakeSort(vector<int> &arr)
{
    vector<int> ans;
    int i, j, a, b;
    for (i = 0; i < arr.size(); i++)
    {
        int maxind = -1;
        for (j = 0; j < arr.size() - i; j++)
        {
            if (arr[j] == arr.size() - i)
            {
                maxind = j;
                break;
            }
        }

        if (maxind != arr.size() - i - 1)
        {
            a = 0;
            b = maxind;
            while (a < b)
            {
                swap(arr[a], arr[b]);
                a++, b--;
            }
            ans.push_back(maxind + 1);

            a = 0;
            b = arr[0] - 1;
            ans.push_back(arr[0]);
            while (a < b)
            {
                swap(arr[a], arr[b]);
                a++, b--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    v = pancakeSort(v);
    for (auto a : v)
        cout << a << " ";
    cout << endl;
    return 0;
}