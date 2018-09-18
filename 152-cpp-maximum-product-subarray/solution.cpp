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
    int maxProduct(vector<int> &nums)
    {
        int ans = nums[0];
        if (nums.size() < 1)
            return 0;
        int maxp = nums[0];
        int minp = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                swap(maxp, minp);
            maxp = max(nums[i], maxp * nums[i]);
            minp = min(nums[i], minp * nums[i]);

            ans = max(ans, maxp);
        }
        return ans;
    }
};
// END UPLOAD ZONE