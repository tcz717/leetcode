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
    void rotate(vector<vector<int>> &matrix)
    {
        size_t n = matrix.size();
        for (size_t row = 0; row < n / 2; row++)
        {
            size_t left = row;
            size_t right = n - row - 1;
            for (size_t col = left; col < right; col++)
            {
                swap(matrix[row][col], matrix[col][n - row - 1]);
                swap(matrix[n - col - 1][row], matrix[row][col]);
                swap(matrix[n - row - 1][n - col - 1], matrix[n - col - 1][row]);
                // swap(matrix[col][n - row - 1], matrix[n - row - 1][n - col - 1]);
            }
        }
    }
};
// END UPLOAD ZONE

int main()
{
    vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution().rotate(input);
    for (auto r : input)
    {
        for (int c : r)
        {
            cout << c << ' ';
        }
        cout << endl;
    }
}