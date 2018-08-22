#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// BEGIN UPLOAD ZONE
class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode *cur = head;
        head = head->next;
        while (cur != NULL && cur->next != NULL)
        {
            ListNode *next = cur->next->next;
            cur->next->next = cur;
            cur->next = next != NULL && next->next != NULL ? next->next : next;
            cur = next;
        }

        return head;
    }
};
// END UPLOAD ZONE