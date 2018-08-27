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
    bool canJump(vector<int> &nums)
    {
        size_t maxReach = 0;
        size_t cur = 0;
        while (cur <= maxReach && cur < nums.size())
        {
            maxReach = max(maxReach, cur + nums[cur]);
            ++cur;
        }
        return maxReach >= nums.size() - 1;
    }
};
// END UPLOAD ZONE