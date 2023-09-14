#include <iostream>
#include <vector>
using namespace std;

//  1 2 3 4
// 4 5 6 99
// 7 8 9 100

// my approach :
vector<int> approachI(vector<vector<int>> &m)
{
    int dir = 1, col = 0, row = 0;
    vector<int> ans;

    for (int i = 0; i < m.size() * m[0].size(); i++)
    {
        if (dir == 1)
        {
            if (col < m[0].size() - 1)
            {
                ans.push_back(m[row][col]);
                col++;
            }
            else
            {
                ans.push_back(m[row][col]);
                dir = -1;
                row++;
            }
        }
        else
        {
            if (col > 0)
            {
                ans.push_back(m[row][col]);
                col--;
            }
            else
            {
                ans.push_back(m[row][col]);
                row++;
                dir = 1;
            }
        }
    }

    return ans;
}

// code help approach :
vector<int> approachII(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < m; j++)
            {
                ans.push_back(matrix[j][i]);
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; j--)
            {
                ans.push_back(matrix[j][i]);
            }
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> m = {{1, 2, 3, 4}, {4, 5, 6, 99}, {7, 8, 9, 100}, {1, 1, 1, 1}};

    vector<int> ans = approachII(m);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// 1 2 3 4
// 4 5 6 99
// 7 8 9 100
// 1 1 1 1