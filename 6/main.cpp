#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = s;
        if (numRows == 1)
            return result;
//        int k = 0;
//        for (int i = 0; i < numRows; ++i) {
//            for (int j = 0; j < s.size(); ++j) {
//                if (j % (2 * numRows - 2) == i ||
//                    j % (2 * numRows - 2) == 2 * numRows - 2 - i)
//                    result[k++] = s[j];
//            }
//        }
        int gNum = (s.size() + 2 * numRows - 3) / (2 * numRows - 2);
        for (int i = 0; i < s.size(); ++i) {
            int gi = i % (2 * numRows - 2);
            int g = i / (2 * numRows - 2);
            cout<<s[i]<<' '<<g<<' '<<gi<<endl;
            int numCols;
            if(gi==0)
                numCols=gNum;
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.convert(string("PAYPALISHIRING"), 3);
    return 0;
}