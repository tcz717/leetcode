#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lower = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        int upper = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target));

        if (lower == nums.size() || nums[lower] != target)
            return {-1, -1};
        return {lower, upper - 1};
    }
};
// END UPLOAD ZONE