/*
https://leetcode.com/problems/sort-an-array/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;

/* heap sort */
class Solution
{
public:
    //downheapify
    void heapify(vector<int> &nums, int i, int n)
    {
        if (i >= n)
            return;

        int leftchild = 2 * i + 1;
        int rightchild = 2 * i + 2;

        int toswap = i;
        if (leftchild < n && nums[leftchild] > nums[toswap])
            toswap = leftchild;

        if (rightchild < n && nums[rightchild] > nums[toswap])
            toswap = rightchild;

        if (toswap != i)
        {
            swap(nums[i], nums[toswap]);
            heapify(nums, toswap, n);
        }
    }

    void heapsort(vector<int> &nums, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(nums, i, n);
        }

        for (int i = n - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums;

        //heap sort
        heapsort(nums, nums.size());
        return nums;
    }
};

/* quick sort */
class Solution
{
public:
    int findpivot(vector<int> &nums, int i, int j)
    {

        int randd = rand() % (j - i + 1) + i;
        swap(nums[j], nums[randd]);
        int piv = nums[j];

        int s = i, f = i;
        while (f < j)
        {
            if (nums[f] <= piv)
                swap(nums[s++], nums[f]);
            f++;
        }
        swap(nums[j], nums[s]);
        return s;
    }

    void quicksort(vector<int> &nums, int i, int j)
    {
        srand(time(0));
        while (i < j)
        { //optimize
            int pivot = findpivot(nums, i, j);
            quicksort(nums, i, pivot - 1);
            // quicksort(nums, pivot+1, j);
            i = pivot + 1;
        }
    }

    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums;

        //quick sort
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

/* counting sort */
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums;

        //counting sort
        int minval = *min_element(nums.begin(), nums.end());
        int maxval = *max_element(nums.begin(), nums.end());

        vector<int> buckets(maxval - minval + 2);

        for (int i = 0; i < nums.size(); i++)
            buckets[nums[i] - minval]++;

        int j = 0;
        for (int i = 0; i < maxval - minval + 2; i++)
            if (buckets[i] > 0)
                while (buckets[i]-- > 0)
                    nums[j++] = i + minval;

        return nums;
    }
};

/* Merge sort */
class Solution
{
public:
    void merge(vector<int> &nums, int i, int m, int j)
    {
        if (m + 1 > j)
            return;

        vector<int> v(j - i + 1);
        int vind = 0;
        int l = i;
        int k = m + 1;
        while ((l <= m) && (k <= j))
        {
            if (nums[l] <= nums[k])
            {
                v[vind++] = nums[l++];
            }
            else
            {
                v[vind++] = nums[k++];
            }
        }

        while (l <= m)
            v[vind++] = nums[l++];

        while (k <= j)
            v[vind++] = nums[k++];

        for (k = i; k <= j; k++)
            nums[k] = v[k - i];
    }

    void mergesort(vector<int> &nums, int i, int j)
    {
        if (i >= j)
            return;
        int m = (i + j) / 2;
        mergesort(nums, i, m);
        mergesort(nums, m + 1, j);
        merge(nums, i, m, j);

        // for(auto& a: nums)
        //     cout << a << " ";
        // cout << endl;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums;
        //merge sort
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};