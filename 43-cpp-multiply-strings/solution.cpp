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
    string multiply(string num1, string num2)
    {
        size_t len = 1;
        string ans(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.size() > num2.size())
            swap(num1, num2);

        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                size_t d = i + j;
                int n = (num1[i] - '0') * (num2[j] - '0') + ans[d] - '0';
                if (n == 0)
                    continue;
                while (n > 9)
                {
                    ans[d++] = n % 10 + '0';
                    n = n / 10 + ans[d] - '0';
                }
                ans[d] = n + '0';
                len = max(len, d + 1);
            }
        }
        ans.resize(len);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// END UPLOAD ZONE