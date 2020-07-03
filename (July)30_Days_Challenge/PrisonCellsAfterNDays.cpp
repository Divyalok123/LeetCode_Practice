// There are 8 prison cells in a row, and each cell is either occupied or vacant.
// Each day, whether the cell is occupied or vacant changes according to the following rules:
// If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
// Otherwise, it becomes vacant.
// (Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)
// We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.
// Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

/* --- Solution 2 --- */
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {
        vector<int> prev, curr(8, 0);
        for (int i = 0; N-- > 0; cells = curr, i++)
        {
            for (int j = 1; j < 7; j++)
                curr[j] = cells[j - 1] == cells[j + 1];

            if (prev.size() == 0)
                prev = curr;
            else if (prev == curr)
                N %= i;
        }

        return cells;
    }
};

/* --- Solution 1 --- */
class Solution
{
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int N)
    {

        int prev = cells[0];
        for (int i = 1; i < 7; i++)
        {
            int tempprev = cells[i];
            if (prev == 1 == cells[i + 1])
                cells[i] = 1;
            else
                cells[i] = 0;
            prev = tempprev;
        }
        cells[0] = 0;
        cells[7] = 0;

        N--;
        N %= 14;
        for (int j = 0; j < N; j++)
        {
            int prev = cells[0];
            for (int i = 1; i < 7; i++)
            {
                int tempprev = cells[i];
                if (prev == 1 == cells[i + 1])
                    cells[i] = 1;
                else
                    cells[i] = 0;
                prev = tempprev;
            }
        }

        return cells;
    }
};