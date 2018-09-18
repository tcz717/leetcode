#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cassert>
using namespace std;

struct ListNode {
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        size_t lena = 0;
        size_t lenb = 0;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != nullptr)
        {
            pa = pa->next;
            ++lena;
        }
        while (pb != nullptr)
        {
            pb = pb->next;
            ++lenb;
        }
        if (lenb > lena)
        {
            swap(lena, lenb);
            swap(headA, headB);
        }
        pa = headA;
        pb = headB;
        for (size_t i = lenb; i < lena; ++i)
            pa = pa->next;
        while (pa != pb)
        {
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};
// END UPLOAD ZONE