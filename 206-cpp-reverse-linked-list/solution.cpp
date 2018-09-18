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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *last = nullptr;
        while (head != nullptr)
        {
            auto next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }
};
// END UPLOAD ZONE