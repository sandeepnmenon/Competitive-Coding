#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp_head = head, *ans_head = head;
        while (n--)
        {
            temp_head = temp_head->next;
            if (temp_head == NULL)
            {
                temp_head = head;
                head = head->next;
                delete temp_head;

                return head;
            }
        }
        while (temp_head->next != NULL)
        {
            temp_head = temp_head->next;
            head = head->next;
        }

        temp_head = head->next;
        head->next = head->next->next;
        delete temp_head;

        return ans_head;
    }
};
