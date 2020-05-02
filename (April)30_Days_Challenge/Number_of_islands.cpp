/* 
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:    
    bool isFine(vector<vector<char>>& grid, bool** visited, int i, int j, int n, int m)
    {
        cout << "Checkpoint z" << endl;
        return ((i < n) && (i >= 0) && (j < m) && (j >= 0) && (grid[i][j] == '1' && !visited[i][j]));
    }
    
    void DFS(vector<vector<char>>& grid, bool** visited, int i, int j, int n, int m)
    {
        visited[i][j] = true;
        int list1[] = {1, 0, 0, -1};
        int list2[] = {0, -1, 1, 0};
        
        for(int l = 0; l < 4; l++)
        {
            if(isFine(grid, visited, i+list1[l], j+list2[l], n, m))
            {
                cout << "Checkpoint y" << endl;
                DFS(grid, visited, i+list1[l], j+list2[l], n, m);
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        cout << "Checkpoint 2" << endl;

        bool** visited = new bool*[n];
        for(int i = 0; i < n; i++)
        {
            visited[i] = new bool[m];
        }
        
        cout << "Checkpoint 3" << endl;

        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    cout << "Checkpoint x" << endl;
                    DFS(grid, visited, i, j, n, m);
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            delete[] visited[i];
        }
        delete[] visited;
        cout << "Last Checkpoint" << endl;
        return count;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> vect(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            vect[i].push_back(x);
        }

    }

    cout << "Checkpoint 1" << endl;

    Solution S;

    cout << S.numIslands(vect) << endl;
}