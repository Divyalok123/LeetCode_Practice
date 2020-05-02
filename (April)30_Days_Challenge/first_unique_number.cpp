// You have a queue of integers, you need to retrieve the first unique integer in the queue.

// Implement the FirstUnique class:

// FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
// int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
// void add(int value) insert value to the queue.


#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class FirstUnique {
    queue<int> q;
    unordered_map<int, int> mapper;
    
public:
    FirstUnique(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            add(nums[i]);   
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && mapper[q.front()] >= 2)
        {
            q.pop();
        }
        if(q.empty()) return -1;
        else return q.front();
    }
    
    void add(int value) {
        mapper[value]++;
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */