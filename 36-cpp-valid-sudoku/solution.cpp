#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        uint16_t line = 0;
        for (int i = 0; i < 9; i++)
        {
            line = 0;
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                uint16_t bit = 1 << (board[i][j] - '0');
                if (line & bit)
                    return false;
                line |= bit;
            }
        }
        for (int j = 0; j < 9; j++)
        {
            line = 0;
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.')
                    continue;
                uint16_t bit = 1 << (board[i][j] - '0');
                if (line & bit)
                    return false;
                line |= bit;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            line = 0;
            int r = i / 3;
            int c = i % 3;
            for (int j = 0; j < 9; j++)
            {
                char num = board[r * 3 + j / 3][c * 3 + j % 3];
                if (num == '.')
                    continue;
                uint16_t bit = 1 << (num - '0');
                if (line & bit)
                    return false;
                line |= bit;
            }
        }
        return true;
    }
};
// END UPLOAD ZONE