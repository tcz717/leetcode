#include <vector>
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
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        int steps = haystack.size() - needle.size();
        if (steps < 0)
            return -1;
        auto end = haystack.end() - needle.size() + 1;

        for (auto subs = haystack.begin(); subs != end; ++subs)
        {
            int i = 0;
            while (i < needle.size() && subs[i] == needle[i])
                ++i;
            if (i == needle.size())
                return distance(haystack.begin(), subs);
        }

        return -1;
    }
};
// END UPLOAD ZONE