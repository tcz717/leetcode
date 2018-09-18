#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <utility>

pair<size_t, size_t> &getfather(vector<vector<pair<size_t, size_t>>> &father, const pair<size_t, size_t> &obj)
{
    auto &f = father[obj.first][obj.second];
    if (f == obj)
    {
        return f;
    }
    father[obj.first][obj.second] = getfather(father, f);
    return f;
}

void combine(vector<vector<pair<size_t, size_t>>> &father, const pair<size_t, size_t> &from, const pair<size_t, size_t> &to)
{
    auto &f = getfather(father, from);
    father[f.first][f.second] = getfather(father, to);
}

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        if (grid.empty() || grid.front().empty())
            return 0;
        size_t height = grid.size();
        size_t weight = grid.front().size();
        vector<vector<pair<size_t, size_t>>> father(height, vector<pair<size_t, size_t>>(weight));
        vector<vector<bool>> visited(height, vector<bool>(weight, false));

        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < weight; ++j)
            {
                if (grid[i][j] == '0')
                    continue;
                father[i][j] = make_pair(i, j);
                if (i != 0 && grid[i - 1][j] == '1')
                    combine(father, make_pair(i, j), make_pair(i - 1, j));
                if (j != 0 && grid[i][j - 1] == '1')
                    combine(father, make_pair(i, j), make_pair(i, j - 1));
            }
        }
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < weight; ++j)
            {
                if (grid[i][j] == '0')
                    continue;
                auto &f = getfather(father, make_pair(i, j));
                if (!visited[f.first][f.second])
                {
                    visited[f.first][f.second] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
// END UPLOAD ZONE

int main(int argc, char const *argv[])
{
    vector<vector<char>> input = {{1, 1, 1, 1, 0},
                                  {1, 1, 0, 1, 0},
                                  {1, 1, 0, 0, 0},
                                  {0, 0, 0, 0, 0}};
    cout << Solution().numIslands(input) << endl;
    return 0;
}
