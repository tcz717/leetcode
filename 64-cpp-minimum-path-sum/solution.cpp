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
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid.front().empty())
            return 0;
        int m = grid.size();
        int n = grid.front().size();
        vector<int> f(n + 1, INT32_MAX);
        f[1] = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                f[j] = grid[i][j - 1] + min(f[j], f[j - 1]);
            }
        }
        return f.back();
    }
};
// END UPLOAD ZONE
int main()
{
    vector<vector<int>> input = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution().minPathSum(input) << endl;
}