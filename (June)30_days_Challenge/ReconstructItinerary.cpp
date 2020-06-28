// Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
// Note:
// If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
// All airports are represented by three capital letters (IATA code).
// You may assume all tickets form at least one valid itinerary.
// One must use all the tickets once and only once.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mapp;
    int n;
    void helper(string s, vector<string> &output)
    {
        while (!mapp[s].empty())
        {
            string x = mapp[s].top();
            mapp[s].pop();
            helper(x, output);
        }
        output.push_back(s);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            mapp[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> output;
        helper("JFK", output);
        reverse(output.begin(), output.end());
        mapp.clear();
        return output;
    }
};