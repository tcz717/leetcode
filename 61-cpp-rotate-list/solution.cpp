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
    ListNode *rotateRight(ListNode *head, int k)
    {
        size_t n = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            node = node->next;
            ++n;
        }
        if (n == 0)
            return nullptr;
        k %= n;
        if (k == 0)
        {
            return head;
        }
        node = head;
        for (int i = 0; i < n - k - 1; ++i)
        {
            node = node->next;
        }
        ListNode *ans = node->next;
        node->next = nullptr;
        node = ans;
        while (node->next != nullptr)
        {
            node = node->next;
        }
        node->next = head;
        return ans;
    }
};
// END UPLOAD ZONE