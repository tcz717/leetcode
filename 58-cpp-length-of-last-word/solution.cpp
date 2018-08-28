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
    int lengthOfLastWord(string s)
    {
        int length = 0;
        int ans = 0;
        for (char c : s)
        {
            if (c == ' ')
            {
                if (length == 0)
                    continue;
                swap(ans, length);
                length = 0;
            }
            else
            {
                ++length;
            }
        }
        return length == 0 ? ans : length;
    }
};
// END UPLOAD ZONE