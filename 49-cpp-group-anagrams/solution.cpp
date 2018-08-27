#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

// BEGIN UPLOAD ZONE
#include <unordered_map>
class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for (auto s : strs)
        {
            string key(s);
            sort(key.begin(), key.end());
            auto group = map.find(key);
            if (group != map.end())
            {
                group->second.push_back(s);
            }
            else
            {
                map.insert({key, {s}});
            }
        }
        result.resize(map.size());
        transform(map.begin(), map.end(), result.begin(), [](pair<string, vector<string>> i) -> vector<string> {
            return move(i.second);
        });
        return result;
    }
};
// END UPLOAD ZONE

int main()
{
    vector<string> input = {"hos", "boo", "nay", "deb", "wow", "bop", "bob", "brr", "hey", "rye", "eve", "elf", "pup", "bum", "iva", "lyx", "yap", "ugh", "hem", "rod", "aha", "nam", "gap", "yea", "doc", "pen", "job", "dis", "max", "oho", "jed", "lye", "ram", "pup", "qua", "ugh", "mir", "nap", "deb", "hog", "let", "gym", "bye", "lon", "aft", "eel", "sol", "jab"};
    auto result = Solution().groupAnagrams(input);
    for (auto &g : result)
    {
        for (string &s : g)
        {
            cout << s << ' ';
        }
        cout << endl;
    }
}