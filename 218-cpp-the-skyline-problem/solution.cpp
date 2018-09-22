#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <utility>
#include <list>
#include <set>
class Solution
{
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings)
    {
        multiset<int, greater<int>> highest = {0};
        multiset<pair<int, int>> downs;
        vector<pair<int, int>> ans;
        ans.reserve(buildings.size());

        for (auto &b : buildings)
        {
            auto down = downs.begin();
            for (; down != downs.end() && down->first <= b[0]; ++down)
            {
                highest.erase(highest.find(down->second));
                if (down->first == b[0])
                    continue;
                if (ans.back().second == down->second)
                    ans.push_back({down->first, *highest.begin()});
            }
            downs.erase(downs.begin(), down);
            highest.insert(b[2]);
            downs.insert(make_pair(b[1], b[2]));
            if (!ans.empty() && ans.back().first == b[0])
                ans.back() = {ans.back().first, max(ans.back().second, b[2])};
            else if (ans.empty() || *highest.begin() != ans.back().second)
                ans.push_back({b[0], *highest.begin()});
        }
        for (auto down = downs.begin(); down != downs.end(); ++down)
        {
            highest.erase(highest.find(down->second));
            if (ans.back().second != *highest.begin())
                ans.push_back({down->first, *highest.begin()});
        }

        return ans;
    }
};
// END UPLOAD ZONE
main(int argc, char const *argv[])
{
    // vector<vector<int>> input = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> input = {{0, 3, 3}, {1, 5, 3}, {2, 4, 3}, {3, 7, 3}};
    auto output = Solution().getSkyline(input);
    for (auto &p : output)
    {
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}
