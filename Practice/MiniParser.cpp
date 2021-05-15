/*
https://leetcode.com/problems/mini-parser/
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '[') {
            NestedInteger ans;
            int v = stoi(s);
            ans.setInteger(v);
            return ans;
        }

        stack<NestedInteger> st;
        
        string news;
        int n = s.size(), i = n-1;
        while(i >= 0) {
            // cout << "i: " << i << endl;
            if(s[i] == ',') {
                if(news.size()) {
                    reverse(news.begin(), news.end());
                    NestedInteger ans((int)stoi(news));
                    st.push(ans);
                }
                news = "";
            } else if(s[i] == ']') {
                news = "";
                NestedInteger ans(INT_MAX);
                st.push(ans);
            } else if(s[i] == '[') {
                if(news.size()) {
                    reverse(news.begin(), news.end());
                    NestedInteger ans((int)stoi(news));
                    st.push(ans);
                    news = "";
                }
                
                NestedInteger ans;        
                while(st.size() && st.top().getInteger() != INT_MAX) {
                    ans.add(st.top());
                    st.pop();
                }
            
                st.pop();
                st.push(ans);
            } else 
                news.push_back(s[i]);
            
            i--;
        }
        
        return st.top();
    }
};