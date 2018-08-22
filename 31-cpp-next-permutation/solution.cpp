#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        for (auto i = nums.rbegin(); i != nums.rend(); ++i)
        {
            if (next(i) == nums.rend())
            {
                sort(nums.begin(), nums.end());
                return;
            }
            if (*i > *next(i))
            {
                auto j = upper_bound(nums.rbegin(), i, *next(i));
                iter_swap(next(i), j);
                sort(prev(i.base()), nums.end());
                return;
            }
        }
    }
};
// END UPLOAD ZONE