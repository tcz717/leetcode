#include <vector>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        if (left == right)
            return target == nums[0] ? 0 : -1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            int l = nums[left], m = nums[mid], r = nums[right];
            if (l == target)
                return left;
            else if (m == target)
                return mid;
            else if (r == target)
                return right;
            else if (l < m)
                if (target > l && target < m)
                    right = mid - 1;
                else
                    left = mid + 1;
            else if (target > m && target < r)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};