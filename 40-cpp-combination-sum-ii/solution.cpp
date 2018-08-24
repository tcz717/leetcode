#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;

// BEGIN UPLOAD ZONE
using namespace std::placeholders;
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        int sum;
        vector<int> trace;
        vector<vector<int>> result;
        function<int(int)> at = bind(static_cast<int &(vector<int>::*)(const size_t)>(&vector<int>::operator[]), &candidates, _1);

        sort(candidates.begin(), candidates.end());

        trace.push_back(0);
        sum = candidates.front();

        while (!trace.empty())
        {
            auto n = make_pair(next(candidates.begin(), trace.back() + 1), candidates.end());
            if (sum < target && n.first != candidates.end())
            {
                trace.push_back(distance(candidates.begin(), n.first));
                sum += *n.first;
                continue;
            }
            else if (sum == target)
            {
                vector<int> com(trace.size());
                transform(trace.begin(), trace.end(), com.begin(), at);
                result.push_back(move(com));
            }
            sum -= candidates[trace.back()];
            trace.pop_back();
            while (!trace.empty())
            {
                int &top = trace.back();
                sum -= candidates[top];
                n = mismatch(
                    next(candidates.begin(), top + 1), candidates.end(),
                    next(candidates.begin(), top));
                if (n.first == candidates.end())
                {
                    trace.pop_back();
                }
                else
                {
                    top = distance(candidates.begin(), n.first);
                    sum += *n.first;
                    break;
                }
            }
        }

        return result;
    }
};
// END UPLOAD ZONE
int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    auto result = Solution().combinationSum2(candidates, target);
    for (auto l : result)
    {
        for (int num : l)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
}