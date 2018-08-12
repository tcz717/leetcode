#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int dp[1000][1000];

    string longestPalindrome(string s) {
        int max_i = 0, max_t = 0;
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int j = 0; j < s.size() - 1; ++j) {
            if (s[j] == s[j + 1]) {
                dp[j][j + 1] = 1;
                if (max_t == 0) {
                    max_t=1;
                    max_i=j;
                }
            }
        }
        for (int t = 2; t < s.size(); ++t) {
            for (int i = 0; i < s.size() - t; ++i) {
                if (dp[i + 1][i + t - 1] == 1 && s[i] == s[i + t]) {
                    dp[i][i + t] = 1;
                    if (max_i > i || t > max_t) {
                        max_i = i;
                        max_t = t;
                    }
                }
            }
        }
        return s.substr(max_i, max_t + 1);
    }
};

int main() {
    Solution *solution = new Solution;
    cout << solution->longestPalindrome(string("cbbd"));
}