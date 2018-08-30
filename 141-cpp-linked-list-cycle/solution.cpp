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
    bool hasCycle(ListNode *head)
    {
        ListNode *two = head;
        while (head != nullptr && two != nullptr)
        {
            head = head->next;
            two = two->next;
            if (two == nullptr)
                return false;
            two = two->next;
            if (head == two)
                return true;
        }
        return false;
    }
};
// END UPLOAD ZONE