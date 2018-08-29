#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <list>
class Solution
{
  public:
    string getPermutation(int n, int k)
    {
        int i;
        int factorial = 1;
        string ans;
        list<int> nums;
        ans.reserve(n);
        for (i = 1; i <= n; i++)
        {
            factorial *= i;
            nums.push_back(i);
        }
        i = n;
        --k;
        while (ans.size() < n)
        {
            factorial /= i--;
            auto num = next(nums.begin(), k / factorial);
            ans.push_back(*num + '0');
            nums.erase(num);
            k %= factorial;
        }
        return ans;
    }
};
// END UPLOAD ZONE