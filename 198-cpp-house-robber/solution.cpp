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
    int rob(vector<int> &nums)
    {
        vector<int> f(nums.size() + 2, 0);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            f[i + 2] = max(f[i + 1], f[i] + nums[i]);
        }
        return f.back();
    }
};
// END UPLOAD ZONE