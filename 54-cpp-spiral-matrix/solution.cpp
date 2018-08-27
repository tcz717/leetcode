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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix.front().empty())
            return {};
        int left = 0;
        int right = matrix.front().size();
        int top = 0;
        int bottom = matrix.size();
        int dir = 0;
        int x = 0;
        int y = 0;
        vector<int> ans;
        ans.reserve(right * bottom);
        while (y >= left && y < right && x >= top && x < bottom)
        {
            ans.push_back(matrix[x][y]);
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
        return ans;
    }
};
// END UPLOAD ZONE
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    auto result = Solution().spiralOrder(matrix);
    for (int i : result)
    {
        cout << i << ' ';
    }
    cout << endl;
}