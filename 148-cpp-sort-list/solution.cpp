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
  private:
    pair<ListNode *, ListNode *> _sortList(ListNode *head, ListNode *tail)
    {
        ListNode *mid = head, *right = head;
        if (head == tail || head->next == tail)
            return make_pair(head, head);
        while (mid->next != tail && mid->val <= mid->next->val)
            mid = mid->next;
        while (right != tail && right->next != tail)
        {
            ListNode *t = right->next;
            if (t->val < mid->val)
            {
                right->next = t->next;
                t->next = head;
                head = t;
            }
            else
                right = right->next;
        }
        auto r = _sortList(mid->next, tail);
        auto l = _sortList(head, mid);
        mid->next = r.first;
        return make_pair(l.first, r.second);
    }

  public:
    ListNode *sortList(ListNode *head)
    {
        return _sortList(head, nullptr).first;
    }
};
// END UPLOAD ZONE