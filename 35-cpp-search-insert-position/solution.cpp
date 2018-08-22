#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};
// END UPLOAD ZONE