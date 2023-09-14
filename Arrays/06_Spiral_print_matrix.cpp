// https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>
using namespace std;

void approachI(vector<vector<int>> &v)
{
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int dir = 0, x = 0, y = 0;
    int m = v.size(), n = v[0].size();
    vector<vector<bool>> printed(m, vector<bool>(n, false));

    for (int i = 0; i < m * n; i++)
    {

        if (printed[x][y] == false)
        {
            cout << v[x][y] << " ";
            printed[x][y] = true;
        }

        int newX = x + dr[dir];
        int newY = y + dc[dir];

        if (newX >= 0 && newX <= m - 1 && newY >= 0 && newY <= n - 1 &&
            !printed[newX][newY])
        {
            x = newX;
            y = newY;
        }
        else
        {
            dir = (dir + 1) % 4;
            x += dr[dir];
            y += dc[dir];
        }
    }
}

vector<int> ApproachII(vector<vector<int>> &matrix)
{

    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int count = 0;

    int startingRow = 0, endingCol = n - 1, endingRow = m - 1, startingCol = 0;

    while (count < m * n)
    {
        for (int i = startingCol; i <= endingCol && count < m * n; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;

        for (int i = startingRow; i <= endingRow && count < m * n; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;

        for (int i = endingCol; i >= startingCol && count < m * n; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;

        for (int i = endingRow; i >= startingRow && count < m * n; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main()
{

    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    return 0;
}