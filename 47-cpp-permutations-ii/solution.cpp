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
    bool nextPermutation(vector<int> &nums)
    {
        for (auto i = nums.rbegin(); i != nums.rend(); ++i)
        {
            if (next(i) == nums.rend())
            {
                return false;
            }
            if (*i > *next(i))
            {
                auto j = upper_bound(nums.rbegin(), i, *next(i));
                iter_swap(next(i), j);
                sort(prev(i.base()), nums.end());
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        result.push_back(nums);
        while (nextPermutation(nums))
        {
            result.push_back(nums);
        }

        return result;
    }
};
// END UPLOAD ZONE
int main()
{
    vector<int> input = {1, 1, 2};
    auto ans = Solution().permuteUnique(input);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}