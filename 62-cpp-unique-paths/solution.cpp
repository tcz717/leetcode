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
    int uniquePaths(int m, int n)
    {
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> f(m, vector<int>(n, 0));
        fill(f.front().begin(), f.front().end(), 1);
        for (auto &r : f)
            r.front() = 1;
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f.back().back();
    }
};
// END UPLOAD ZONE