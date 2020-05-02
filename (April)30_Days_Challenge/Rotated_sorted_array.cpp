// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            int leftElement = nums.at(start);
            int rightElement = nums.at(end);
            int midElement = nums.at(mid);
            if(midElement == target) return mid;
            
            else if(midElement > rightElement)
            {
                if(target < midElement && target >= leftElement)
                {
                    end = mid - 1;
                }
                else start = mid + 1;
            }
            
            else if(midElement < leftElement)
            {
                if(target > midElement && target <= rightElement)
                    start = mid + 1;
                else end = mid - 1;
            }
            
            else
            {
                if(target < midElement)
                {
                    end = mid - 1;
                }
                else start = mid + 1;
            }
        }
        
        return -1;
    }
};

int main()
{
    int n; 
    cin >> n;

    // int* arr = new int[n];
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int target;
    cin >> target;

    Solution S;
    cout << S.search(v, target);
    return 0;
}