/*
https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
*/

#include <iostream>
#include <vector>
#include <array>
using namespace std;

// solution 3 explanation with improvements
// source: https://stackoverflow.com/questions/67797849/maximum-xor-with-an-element-from-array-leetcode#67799018
namespace Solution
{

// as EXACTLY two values, std::pair is more appropriate
// we are not modifying queries, so should be accepted as const
std::vector<int> maximizeXor
(
    std::vector<int>& nums, std::vector<std::pair<int, int>>const& queries
)
{
    const int q = queries.size();
    std::vector<int> ans(q, -1);
    sort(nums.begin(), nums.end());
    // remove duplicates:
    // -> less numbers to iterate over
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (int i = 0; i < q; ++i)
    {
        int const x = queries[i].first, m = queries[i].second;
        // we have a sorted array, remember?
        // if first value is larger than the query maximum, then there are no
        // corresponding numbers – and as the vector is initialised to -1 
        // anyway, the appropriate value is there already so we can simply skip
        if (m < nums[0])
        {
            continue;
        }

        // using iterators pointing at the appropriate indices
        auto end = upper_bound(nums.begin(), nums.end(), m);
        auto start = nums.begin();

        int /*k = 0,*/ cur = 0;

        // intention is to check each bit of x

        // modifying the loop!
        //for (int bit = 30; bit >= 0; bit--)
        int const MaxBit = 1 << sizeof(int) * CHAR_BIT - 2;
        for (int bit = MaxBit; start != prev(end); bit >>= 1)
        {
            // OK; fixing an issue and adding some tricks to handle the loop
            // a bit cleverer...

            // sizeof(int) * CHAR_BIT: int is NOT guaranteed to have exactly 
            // 32 bits! if you want to be on the safe side, either calculate 
            // as above or use int32_t instead

            // changed abort condition:
            // I modified the algorithm slightly such that we can break early
            // unique'ing the vector allows us to drop the original
            // condition bit >= 0 entirely, this will be explained later

            // I store the bit-MASK in bit now, now we do not have to 
            // calculate it again and again (1 << bit)

            if (x & bit)
            {
                // so x has a 1-bit at bit index 'bit'

                // in the range yet to be considered we have two groups of
                // numbers:
                // 1. those having a 0-bit at bit-index 'bit'
                // 2. those having a 1-bit

                // if we compare single bits, we get:
                // x   = *1***
                // num = *0*** XOR: *1***
                // num = *1*** XOR: *0***

                // IF now there are numbers with a zero bit at all, then one 
                // of these will produce the maximum, whereas those with a 
                // 1-bit cannot asnumbers are sorted, we can just check very
                // first value of the range:


                // any number having a 1-bit at the same bit index will produce 
                // a zero-bit – thus these numbers CANNOT produce the maximum

                if (!(*start & bit))
                {
                    // bits differ, remember?
                    // thus the XOR will have a one-bit we store right now
                    // actually, we do NOT need that, we can handle that cleverer
                    //k |= 1 << bit;
                    // instead, I handle this with the NEW loop condition

                    // fine – there ARE numbers with zero-bits, so remove all
                    // numbers with 1-bit from range; as they all are at the end
                    // of, we simply move this one towards front:
                    end = lower_bound(start, end, cur | bit);
                    // cur contains those bits of the number producing the 
                    // maximum that have been evaluated so far, it is a 
                    // lower bound for – we do NOT modify it, but we can
                    // calculate a new upper bound from!
                }
                else
                {
                    // well, there is no such number with a 0-bit
                    // we cannot move end or start position
                    cur |= bit;
                }
            }
            else
            {
                // analogously:
                // x   = *0***
                // num = *0*** XOR: *0***
                // num = *1*** XOR: *1***

                // so all members having a 1-bit are of interest  – IF there 
                // are – and we can skip those numbers with 0-bit at the
                // beginning

                // if there are, then they are at the very end
                // 'end' iterator points to one past, so we need predecessor
                if (/*start < end &&*/ *prev(end) & bit)
                {
                    // first condition is handled in the loop now

                    // as above: we can handle that cleverer
                    //k |= 1 << bit;

                    // now current mask NEEDS the one-bit
                    cur |= bit;
                    start = lower_bound(start, end, cur);
                }
            }
            // with unchanged loop it was not possible to break early as k still
            // needed to be calculated
            //ans[i] = k;

            // with or without early break, we can always:
            ans[i] = *start ^ x;
            // with every iteration, we extend the bit mask 'cur' the numbers 
            // have to match with by one bit (either the 0 gets confirmed
            // or replaced by a 1). 
            // After 31 iterations (sign bit is ignored as we only have 
            // positive integers), *all* bits are defined (if we had omitted 
            // the early breaks we could have calculated
            // ans[i] = cur ^ x; as well...).

            // so all numbers that yet might have remained in the valid range
            // must match this pattern, i. e. be equal. However as unique-ing, 
            // there is exactly one single value left...
        }
    }
    return ans;
}
} // namespace Solution


// solution 3 (binary search) : O(nlogn + 32*qlogn) 
class Solution {
public:
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), 
            q = queries.size();
        
        vector<int> ans(q, -1);
        sort(nums.begin(), nums.end());
        
        int qi = 0;
        for(auto& i: queries) {
            int ele = i[0], lim = i[1];
            
            if(lim < nums.front()) {
                qi++;
                continue;
            }
            
            int lastind = upper_bound(nums.begin(), nums.end(), lim)-nums.begin();
            
            int ind = 0, curr = 0, currans = 0;
            for(int j = 30; j >= 0; j--) {
                int val = 1 << j;
                
                if(ele & val) {
                    curr |= val;
                    if((nums[ind] & val) == 0) {
                        currans |= val;
                        lastind = lower_bound(nums.begin() + ind, nums.begin() + lastind, curr)-nums.begin();
                        curr ^= val;
                    }
                } else {
                    if(ind < lastind && (nums[lastind-1] & val)) {
                        currans |= val;
                        curr |= val;
                        ind = lower_bound(nums.begin() + ind, nums.begin() + lastind, curr)-nums.begin();
                    }
                }
                
            }
            ans[qi++] = currans;
        }
        
        
        return ans;
    }
};


// solution 2 (trie + dfs) : O(31*n + q*(2 ^ 31)) worst case less likely to happen due to pruning
class Solution {
public:
    
    class trieNode {
    public:
        array<trieNode*, 2> children;
        
        trieNode() {
            for(int i = 0; i < 2; i++)
                children[i] = NULL;
        }
    };
    
    void insertNum(trieNode* tree, int n) {
        trieNode* temp = tree;
        for(int i = 30, bit = 1 << 30; i >= 0; i--, bit >>= 1) {
            int val = (n & bit) > 0;
            if(temp->children[val] == NULL)
                temp->children[val] = new trieNode();
            temp = temp->children[val];
        }
    }
    
    int query(trieNode* tree, int ele, int lim, int sum, int bitnum) {
        if(sum > lim) return -1;
        if(bitnum == -1) return  0;
        
        int val = (ele >> bitnum) & 1;
        
        if(tree->children[1-val]) {
            int ans = query(tree->children[1-val], ele, lim, sum | (!val << bitnum), bitnum-1);
            if(ans != -1)
                return ans | (1 << bitnum);
        }
        
        if(tree->children[val]) {
            int ans = query(tree->children[val], ele, lim, sum | (val << bitnum), bitnum-1);
            if(ans != -1)
                return ans;
        }
        
        return -1;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), 
            q = queries.size();
        
        vector<int> ans(q, -1);
        trieNode* ourTree = new trieNode();
        
        for(int& i: nums)
            insertNum(ourTree, i);
        
        int j = 0;
        for(auto& i: queries)
            ans[j++] = query(ourTree, i[0], i[1], 0, 30);
        
        return ans;
    }
};

// solution 1 (trie + sort) : O(nlogn + qlogn + 31*(n + q))
class Solution {
public:
    
    class trieNode {
    public:
        array<trieNode*, 2> children;
        
        trieNode() {
            for(int i = 0; i < 2; i++)
                children[i] = NULL;
        }
    };
    
    void insertNum(int n, trieNode* tree) {
        trieNode* temp = tree;
        for(int i = 30, bit = 1 << 30; i >= 0; i--, bit >>= 1) {
            int val = (n & bit) > 0;
            if(temp->children[val] == NULL)
                temp->children[val] = new trieNode();
            temp = temp->children[val];
        }
    }
    
    int query(trieNode* tree, int ele) {
        int ans = 0;
        trieNode* temp = tree;
        
        for(int i = 30, bit = 1 << 30; i >= 0; i--, bit >>= 1) {
            int val = (ele & bit) > 0;
            if(temp->children[1-val]) {
                ans += bit;
                temp = temp->children[1-val];
            } else {
                temp = temp->children[val];
            }
        }

        return ans;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), 
            q = queries.size();
        
        vector<int> ans(q, -1);
        trieNode* ourTree = new trieNode();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < q; i++)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        
        int i = 0, j = 0;
        while(j < q) {
            int pre = i;
            while(i < n && nums[i] <= queries[j][1])
                insertNum(nums[i++], ourTree);
            
            if(i != 0) {
                int val = query(ourTree, queries[j][0]);
                ans[queries[j][2]] = val;
            }
            j++;
        }
        
        return ans;
    }
};