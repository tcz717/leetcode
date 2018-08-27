#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <climits>
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> sums;
        sums.reserve(nums.size());
        int sum = 0;
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums.front();
        for (int n : nums)
        {
            sum += n;
            sums.push_back(sum);
        }
        int ans = sums.front();
        int minsum = min(0, sums.front());
        for (auto s = next(sums.begin()); s != sums.end(); ++s)
        {
            ans = max(ans, *s - minsum);
            minsum = min(minsum, *s);
        }
        return ans;
    }
};
// END UPLOAD ZONE