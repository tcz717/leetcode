#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        size_t si = 0;
        size_t pi = 0;
        char lastp = 0;
        while (si < s.size() && pi < p.size())
        {
            char c = s[si];
            switch (p[pi])
            {
            case '.':
                lastp = p[pi];
                si++;
                pi++;
                break;
            case '*':
                if ((lastp == c || lastp == '.')&&(s.size()))
                    si++;
                else
                    pi++;
                break;
            default:
                if (c != p[pi])
                {
                    if (pi < p.size() - 1 && p[pi + 1] == '*')
                    {
                        lastp = p[pi];
                        pi++;
                        break;
                    }
                    return false;
                }
                else
                {
                    lastp = p[pi];
                    si++;
                    pi++;
                }
                break;
            }
        }

        if (si != s.size())
            return false;

        if (pi == p.size() || (pi == p.size() - 1 && p[pi] == '*'))
            return true;

        return false;
    }
};

int main()
{
    Solution sl;
    string s("aaa");
    string p("a*a");
    cout << sl.isMatch(s, p) << endl;
    return 0;
}