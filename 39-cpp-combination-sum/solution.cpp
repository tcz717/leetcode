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
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
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
            if (sum < target)
            {
                int i = trace.back();
                trace.push_back(i);
                sum += candidates[i];
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
                if ((1 + top) >= candidates.size())
                {
                    trace.pop_back();
                }
                else
                {
                    sum += candidates[++top];
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
    vector<int> candidates = {8, 7, 4, 3};
    int target = 11;
    auto result = Solution().combinationSum(candidates, target);
    for (auto l : result)
    {
        for (int num : l)
        {
            cout << num << ' ';
        }
        cout << endl;
    }
}