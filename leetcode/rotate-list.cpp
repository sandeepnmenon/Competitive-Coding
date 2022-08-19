#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 or head == nullptr)
            return head;
        int length = 0;
        ListNode *tail, *thead = head;
        getLengthAndTail(head, length, tail);

        k = k % length;
        if (k == 0)
            return head;

        for (int i = 0; i < length - k - 1; ++i)
        {
            thead = thead->next;
        }
        tail->next = head;
        head = thead->next;
        thead->next = nullptr;

        return head;
    }

    void getLengthAndTail(ListNode *head, int &n, ListNode *&tail)
    {
        n = 1;
        while (head->next != nullptr)
        {
            head = head->next;
            n++;
        }
        tail = head;
    }
};

void printListNode(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    Solution s;
    // Create new linked list
    ListNode *head, *prev, *tail;
    head = new ListNode(1);
    prev = head;
    for (int i = 2; i <= 5; ++i)
    {
        prev->next = new ListNode(i);
        prev = prev->next;
    }
    printListNode(head);
    int k = 2;
    ListNode *rotated_head = s.rotateRight(head, k);
    printListNode(rotated_head);
}