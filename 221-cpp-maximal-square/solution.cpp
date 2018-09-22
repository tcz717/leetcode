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
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int ans = 0;
        if (matrix.empty() || matrix.front().empty())
        {
            return 0;
        }
        size_t height = matrix.size(), weight = matrix.front().size();
        vector<vector<int>> f(height, vector<int>(weight, 0));

        for (size_t i = 0; i < weight; i++)
        {
            f[0][i] = matrix[0][i] - '0';
            ans = max(ans, f[0][i]);
        }

        for (size_t j = 1; j < height; j++)
        {
            f[j][0] = matrix[j][0] - '0';
            ans = max(ans, f[j][0]);
            for (size_t i = 1; i < weight; i++)
            {
                if (matrix[j][i] == '0')
                    f[j][i] = 0;
                else
                {
                    int s = min({f[j - 1][i - 1], f[j - 1][i], f[j][i - 1]}) + 1;
                    f[j][i] = s;
                    ans = max(ans, s * s);
                }
            }
        }
        return ans;
    }
};
// END UPLOAD ZONE

int main(int argc, char const *argv[])
{
    // vector<vector<char>> input = {
    //     {1, 0, 1, 0, 0},
    //     {1, 0, 1, 1, 1},
    //     {1, 1, 1, 1, 1},
    //     {1, 0, 0, 1, 0}};
    // vector<vector<char>> input = {
    //     {'1', '1', '0', '1'},
    //     {'1', '1', '0', '1'},
    //     {'1', '1', '1', '1'}};
    vector<vector<char>> input = {
        {'0', '0', '0', '0'},
        {'1', '0', '0', '0'},
        {'0', '0', '0', '0'}};
    cout << Solution().maximalSquare(input) << endl;
    return 0;
}
