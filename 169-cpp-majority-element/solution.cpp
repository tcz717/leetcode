#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <unordered_map>
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int maxcount = 0;
        int ans = 0;
        unordered_map<int, int> map;
        for (int n : nums)
        {
            if (map.find(n) != map.end())
            {
                ++map[n];
            }
            else
            {
                map[n] = 1;
            }
            if (map[n] > maxcount)
            {
                maxcount = map[n];
                ans = n;
            }
        }
        return ans;
    }
};
// END UPLOAD ZONE