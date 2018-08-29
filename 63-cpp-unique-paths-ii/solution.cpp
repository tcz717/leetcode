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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty() || obstacleGrid.front().empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid.front().size();
        vector<int> f(n + 1, 0);
        f[1] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                f[j] = obstacleGrid[i][j - 1] == 1 ? 0 : f[j] + f[j - 1];
            }
        }
        return f.back();
    }
};
// END UPLOAD ZONE

int main()
{
    vector<vector<int>> input = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << Solution().uniquePathsWithObstacles(input) << endl;
}