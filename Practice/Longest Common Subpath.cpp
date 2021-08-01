/*
https://leetcode.com/problems/longest-common-subpath/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <array>
#include <unordered_set>
using namespace std;

// rolling hash with double hash
static int xx = [](){ios_base::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    #define ll long long
    vector<ll> powers1, powers2;
    ll p1, p2;
    #define MOD 1000000009
    
    ll poww(ll x, ll y) {
        ll ans = 1;
        while(y) {
            if(y&1)
                ans = (ans * x) % MOD;
            y >>= 1;
            x = (x * x) % MOD;
        }
        
        return ans;
    }
    
    ll modinv(ll val) {
        return poww(val, MOD-2);
    }
    
    bool possible(int len, vector<vector<int>>& paths) {
        if(len == 0) return true;
        set<array<ll, 2>> s;
        int m = paths.size(), ind = 0;
        for(auto& path: paths) {
            int sz = path.size();
            set<array<ll, 2>> thiss;
            ll hash1[sz], hash2[sz];
            
            hash1[0] = path[0] + 1;
            hash2[0] = path[0] + 1;
            
            for(int j = 1; j < sz; j++) {
                hash1[j] = (hash1[j-1] + powers1[j] * (path[j] + 1ll)) % MOD;
                hash2[j] = (hash2[j-1] + powers2[j] * (path[j] + 1ll)) % MOD;
            }
            
            ll currhash1 = (hash1[len-1]) % MOD;
            ll currhash2 = (hash2[len-1]) % MOD;
            
            array<ll, 2> pp = {currhash1, currhash2};
            if(ind == 0 || s.count(pp))
                thiss.insert(pp);

            for(int j = len; j < sz; j++) {
                currhash1 = (hash1[j]-hash1[j-len] + MOD) % MOD;
                currhash1 = (currhash1 * modinv(powers1[j-len+1])) % MOD;
                
                currhash2 = (hash2[j]-hash2[j-len] + MOD) % MOD;
                currhash2 = (currhash2 * modinv(powers2[j-len+1])) % MOD;
                
                pp = {currhash1, currhash2};
                
                if(ind == 0 || s.count(pp))
                    thiss.insert(pp);   
            }
           
            ind = 1;
            s = thiss;
            if(s.size() == 0) return false;
        }
        
        return true;
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int l = 0, r = INT_MAX, mm = 0;
        for(auto& i: paths) {
            if(i.size() < r) r = i.size();
            if(i.size() > mm) mm = i.size();
        }
        
        powers1.resize(mm+1);
        powers2.resize(mm+1);
        p1 = 104729, p2 = 100007;
        powers1[0] = 1, powers2[0] = 1;
        for(int i = 1; i <= mm; i++) {
            powers1[i] = (powers1[i-1] * p1) % MOD;
            powers2[i] = (powers2[i-1] * p2) % MOD;
        }
        
        int ans = 0;
        while(l <= r) {
            int m = l + (r-l)/2;
            
            // cout << "m: " << m << endl;
            if(possible(m, paths))
                ans = m, l = m+1;
            else
                r = m-1;
        }
        
        return ans;
    }
};

// using suffix array  (TODO)
class Solution {
public:
    
    void countingsort(vector<int>& p, vector<int>& c) {
        int total = p.size();
        
        vector<int> count(total), ans(total), pos(total);
        
        for(int i = 0; i < total; i++)
            count[c[i]]++;
        
        pos[0] = 0;
        for(int i = 1; i < total; i++)
            pos[i] = pos[i-1] + count[i-1];
        
        for(int i = 0; i < total; i++) {
            int k = c[p[i]];
            ans[pos[k]++] = p[i]; 
        }
        
        p = ans;
    }
    
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int total = 0, m = paths.size();
        for(auto& i: paths) total += i.size();
        total += m;
        
        // cout << "total: " << total << endl;
        
        vector<int> comb(total), pathid(total);
        int ind = 0, concat = -1, id = 0;
        for(auto& i: paths) {
            for(int& j: i)
                pathid[ind] = id, comb[ind++] = j;
            pathid[ind] = id++;
            comb[ind++] = concat--;
        }
        
        // cout << "COMB: ";
        // for(int& i: comb)
        //     cout << i << " ";
        // cout << endl;
        
        vector<int> p(total), c(total);
        
        {
            vector<array<int, 2>> v(total);
            for(int i = 0; i < total; i++)
                v[i] = {comb[i], i};
            
            sort(v.begin(), v.end());
            
            for(int i = 0; i < total; i++)
                p[i] = v[i][1];
            
            c[p[0]] = 0;
            
            for(int i = 1; i < total; i++) {
                if(v[i][0] == v[i-1][0])
                    c[p[i]] = c[p[i-1]];
                else
                    c[p[i]] = c[p[i-1]] + 1;
            }
        }
        
        int k = 0;
        while((1 << k) < total) {
            for(int i = 0; i < total; i++)
                p[i] = (p[i] - (1 << k) + total) % total;
            
            countingsort(p, c);
            
            vector<int> newc(total);
            newc[p[0]] = 0;
            for(int i = 1; i < total; i++) {
                array<int, 2> curr = {c[p[i]], c[(p[i] + (1 << k)) % total]};
                array<int, 2> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % total]};
                
                if(curr == prev)
                    newc[p[i]] = newc[p[i-1]];
                else
                    newc[p[i]] = newc[p[i-1]] + 1;  
            }
            
            c = newc;
            k++;
        }
        
//         cout << "P: ";
//         for(int& i: p)
//             cout << i << " ";
//         cout << endl;
        
        vector<int> LCP(total);
        k = 0;
        for(int i = 0; i < total; i++) {
            int ind = c[i];
            if(ind == 0) continue;
            int indd = p[ind-1];
            while(i + k < total && indd + k < total && comb[i+k] == comb[indd + k])
                k++;
            LCP[ind] = k;
            k = max(k-1, 0);
        }
        
        // cout << "LCP: ";
        // for(int i = 0; i < total; i++)
        //     cout << LCP[i] << " ";
        // cout << endl;
        
        int ans = 0, i = 0;
        while(i < total) {
            
        }
        
        return 0;
    }
};