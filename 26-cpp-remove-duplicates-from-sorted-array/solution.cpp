#include <vector>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int delnums = 0;
        if (nums.empty())
            return nums.size();
        for (auto i = nums.begin(); i != nums.end() - delnums; ++i)
        {
            auto next = i + 1 + delnums;
            while (*i == *next && next != nums.end())
            {
                ++delnums;
                ++next;
            }
            if (next == nums.end())
                break;
            iter_swap(i + 1, next);
        }
        return nums.size() - delnums;
    }
};
// END UPLOAD ZONE