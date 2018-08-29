#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0)
            return {};
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0;
        int right = matrix.front().size();
        int top = 0;
        int bottom = matrix.size();
        int dir = 0;
        int x = 0;
        int y = 0;
        vector<int> ans;
        matrix.reserve(right * bottom);
        int i = 1;
        while (y >= left && y < right && x >= top && x < bottom)
        {
            matrix[x][y] = i++;
            switch (dir)
            {
            case 0:
                if (++y == right)
                {
                    --y;
                    ++x;
                    ++top;
                    ++dir;
                }
                break;
            case 1:
                if (++x == bottom)
                {
                    --x;
                    --y;
                    --right;
                    ++dir;
                }
                break;
            case 2:
                if (--y == left - 1)
                {
                    ++y;
                    --x;
                    --bottom;
                    ++dir;
                }
                break;
            case 3:
                if (--x == top - 1)
                {
                    ++x;
                    ++y;
                    ++left;
                    dir = 0;
                }
                break;
            }
        }
        return matrix;
    }
};
// END UPLOAD ZONE
int main()
{
    auto result = Solution().generateMatrix(4);
    for (auto &i : result)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
}