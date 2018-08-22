#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        int64_t result = 0;
        int64_t remain = dividend;
        int64_t divs = divisor;
        int sign = 0;
        if (dividend == 0)
            return 0;
        if (dividend < 0)
        {
            sign ^= 1;
            remain = -remain;
        }
        if (divisor < 0)
        {
            sign ^= 1;
            divs = -divs;
        }
        if (divs == 1)
            return sign == 0 ? min(remain, (int64_t)INT32_MAX) : -remain;

        for (int bit = 31; bit >= 0; --bit)
        {
            if (remain >= (divs << bit))
            {
                remain -= divs << bit;
                result += 1 << bit;
            }
        }

        return sign == 0 ? result : -result;
    }
};
// END UPLOAD ZONE