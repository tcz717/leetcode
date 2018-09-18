#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <list>
#include <limits>
#include <climits>

class Solution
{
    bool hasLoop = false;
    void dfs(vector<list<int>> &adj, vector<pair<int, int>> &record, int target, int &timestamp)
    {
        record[target].first = timestamp++;
        for (auto d : adj[target])
        {
            if (record[d].first > timestamp)
                dfs(adj, record, d, timestamp);
            else if (record[d].second > timestamp)
                hasLoop = true;
        }
        record[target].second = timestamp++;
    }

  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<list<int>> adj(numCourses);
        vector<pair<int, int>> record(numCourses, make_pair(INT_MAX, INT_MAX));
        int timestamp = 0;
        for (auto &p : prerequisites)
        {
            adj[p.first].push_back(p.second);
        }
        for (int s = 0; s < numCourses; s++)
        {
            if (record[s].first == INT_MAX)
                dfs(adj, record, s, timestamp);
            if (hasLoop)
                break;
        }
        return !hasLoop;
    }
};
// END UPLOAD ZONE
main(int argc, char const *argv[])
{
    vector<pair<int, int>> input = {{0, 1},
                                    {1, 0}};
    cout << Solution().canFinish(2, input) << endl;
    return 0;
}
