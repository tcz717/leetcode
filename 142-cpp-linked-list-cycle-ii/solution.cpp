#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// BEGIN UPLOAD ZONE
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *one = head;
        ListNode *two = head;
        while (true)
        {
            if (one == nullptr || two == nullptr || two->next == nullptr)
                return nullptr;
            one = one->next;
            two = two->next->next;
            if (one == two)
                break;
        }
        one = head;
        while (one != two)
            one = one->next, two = two->next;
        return one;
    }
};
// END UPLOAD ZONE