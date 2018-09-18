#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <stack>
using namespace std;

// BEGIN UPLOAD ZONE
class MinStack
{
  private:
    stack<int> s;
    stack<int> mins;

  public:
    /** initialize your data structure here. */
    MinStack() : s(), mins()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (!mins.empty() && mins.top() < x)
        {
            mins.push(mins.top());
        }
        else
        {
            mins.push(x);
        }
    }

    void pop()
    {
        s.pop();
        mins.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return mins.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
// END UPLOAD ZONE