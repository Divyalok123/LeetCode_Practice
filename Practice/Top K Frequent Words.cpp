/*
https://leetcode.com/problems/top-k-frequent-words/
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <string>
using namespace std;

// using hashmap and trie - O(n)
class Solution {
public:
    
    class TrieNode {
    public: 
        TrieNode* children[26];
        string str;
        
        TrieNode() {
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }       
    };
    
    void addWord(TrieNode* root, const string& word) {
        TrieNode* temp = root;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            int j = word[i]-'a';
            
            if(!temp->children[j])
                temp->children[j] = new TrieNode();
            
            temp = temp->children[j];
        }
        
        temp->str = word;
    }
    
    void getWords(TrieNode* root, vector<string>& ans) {
        if(!root) return;
        
        if(root->str.size())
            ans.push_back(root->str);
        
        for(int i = 0; i < 26; i++)
            if(root->children[i])
                getWords(root->children[i], ans);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(string& i: words) um[i]++;
        
        int maxele = -1;
        for(auto& i: um) if(i.second > maxele) maxele = i.second;
        
        TrieNode* buckets[maxele+1];
        fill_n(buckets, sizeof buckets/sizeof *buckets, nullptr);
        
        for(auto& i: um) {
            int f = i.second;
            const string& word = i.first;
            
            if(!buckets[f]) buckets[f] = new TrieNode();
            
            addWord(buckets[f], word);
        }
        
        vector<string> ans;
        ans.reserve(k);
        
        for(int i = maxele; i > 0; i--) {
            if(buckets[i]) {
                vector<string> vec;
                getWords(buckets[i], vec);
                
                if(vec.size() + ans.size() < k)
                    ans.insert(ans.end(), vec.begin(), vec.end());
                else {
                    int j = 0;
                    while(ans.size() < k)
                        ans.push_back(vec[j++]);
                    break;
                }
            }
        }
        
        return ans;
    }
};

// using hashmap and minheap - O(nlogk)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(string& i: words) um[i]++;
        
        using pis = pair<int, string>;
        vector<pis> vec;
        vec.reserve(um.size());
        
        vector<string> ans;
        ans.reserve(k);
        
        for(auto& i: um)
            vec.push_back({i.second, i.first});
        
        int n = vec.size();
        
        class comp {
            public:
                bool operator()(pair<int, string>& a, pair<int, string>& b) {
                    return a.first > b.first || a.first == b.first && a.second < b.second;
                }
        };
        
        priority_queue<pis, vector<pis>, comp> pq;
        for(int i = 0; i < k; i++)
            pq.push(vec[i]);

        for(int i = k; i < n; i++) {
            auto& t = pq.top();
            auto& v = vec[i];
            if(t.first < v.first || (t.first == v.first && t.second > v.second))
            {
                pq.pop();
                pq.push(vec[i]);
            }
        }

        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// using hashmap and maxheap - O(nlogk)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(string& i: words) um[i]++;
        
        using pis = pair<int, string>;
        vector<pis> vec;
        vec.reserve(um.size());
        vector<string> ans(k);
        
        for(auto& i: um)
            vec.push_back({i.second, i.first});
        
        auto comp = [](pis& a, pis& b) {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        };
        
        nth_element(vec.begin(), vec.begin() + k, vec.end(), comp);
        sort(vec.begin(), vec.begin() + k, comp);
        
        for(int i = 0; i < k; i++)
            ans[i] = vec[i].second;
        
        return ans;
    }
};

// using hashmap, quickselect, sort - O(nlogk)
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for(string& i: words) um[i]++;
        
        using pis = pair<int, string>;
        vector<pis> vec;
        vec.reserve(um.size());
        vector<string> ans(k);
        
        for(auto& i: um)
            vec.push_back({i.second, i.first});
        
        auto comp = [](pis& a, pis& b) {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        };
        
        nth_element(vec.begin(), vec.begin() + k, vec.end(), comp);
        sort(vec.begin(), vec.begin() + k, comp);
        
        for(int i = 0; i < k; i++)
            ans[i] = vec[i].second;
        
        return ans;
    }
};