#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    string countAndSay(int n)
    {
        string last("1");
        string current;
        last.reserve(2 * n);
        current.reserve(2 * n);

        for (int i = 1; i < n; ++i)
        {
            current.clear();
            char c = 0;
            int len = 0;
            for (auto s = last.begin(); s != last.end(); s++)
            {
                if (*s == c)
                    len++;
                else if (len == 0)
                {
                    c = *s;
                    len = 1;
                }
                else
                {
                    current.append(to_string(len));
                    current.push_back(c);
                    c = *s;
                    len = 1;
                }
            }
            current.append(to_string(len));
            current.push_back(c);
            swap(current,last);
        }
        return last;
    }
};
// END UPLOAD ZONE