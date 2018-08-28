#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <list>
#include <deque>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// BEGIN UPLOAD ZONE
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> ans;
        ans.reserve(intervals.size());
        sort(intervals.begin(), intervals.end(), [](const struct Interval &a, const struct Interval &b) -> bool {
            return a.start < b.start;
        });
        for (auto &i : intervals)
        {
            if (ans.empty())
            {
                ans.push_back(i);
                continue;
            }
            auto &last = ans.back();
            if (i.start <= last.end)
            {
                last.end = max(i.end, last.end);
            }
            else
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// END UPLOAD ZONE
int main()
{
    vector<Interval> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<Interval> input = {{0, 4}, {1, 4}};
    auto res = Solution().merge(input);
    for (auto &i : res)
    {
        cout << i.start << ' ' << i.end << endl;
    }
}