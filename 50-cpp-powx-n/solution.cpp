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
    double myPow(double x, int n)
    {
        bool sign = n >= 0;
        uint32_t un = sign ? n : -static_cast<int64_t>(n);
        double ans = 1;
        if (x == 0)
            return 0;
        if (!sign)
            x = 1 / x;

        for (int i = 0; i < 32; i++, x *= x)
        {
            if ((1 << i) & un)
                ans *= x;
        }
        return ans;
    }
};
// END UPLOAD ZONE

int main()
{
    cout << Solution().myPow(2, -2147483648) << endl;
}