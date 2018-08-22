#include <vector>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

string integerVectorToString(vector<int> list, int length);

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        auto end = nums.end();
        if (nums.empty())
            return nums.size();
        for (auto i = nums.begin(); distance(i, end) >= 0; ++i)
        {
            while (*i == val && i != end)
            {
                iter_swap(i, --end);
            }
        }
        return distance(nums.begin(), end);
    }
};
// END UPLOAD ZONE