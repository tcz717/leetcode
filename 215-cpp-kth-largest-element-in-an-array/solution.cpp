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
    int findKthLargest(vector<int> &nums, int k)
    {
        auto b = nums.begin(), e = nums.end();
        if (nums.empty())
            return 0;
        while (b != e)
        {
            auto first = b;
            int mid = *(b + (e - b) / 2);
            while (*first >= mid && first != e)
                ++first;
            if (first == e)
            {
                iter_swap(e - 1, b + (e - b) / 2);
                --e;
                continue;
            }
            for (auto i = first + 1; i != e; ++i)
            {
                if (*i >= mid)
                {
                    iter_swap(i, first);
                    ++first;
                }
            }
            if (first - nums.begin() > k - 1)
                e = first;
            else
                b = first;
        }
        return nums[k - 1];
    }
};
// END UPLOAD ZONE