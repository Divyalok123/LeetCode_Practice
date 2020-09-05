#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    if(n == 1 || n == 2) { cout << v[0] << endl; return 0; }

    vector<int> dp(n, 0);

    
}