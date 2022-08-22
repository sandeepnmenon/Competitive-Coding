
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *next, *temp, *prev = nullptr;
        if (head == nullptr or head->next == nullptr)
            return head;

        while (head->next != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head->next = prev;

        return head;
    }
};

void printListNode(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null" << endl;
}

int main()
{
    Solution sol;
    ListNode *list1, *prev;
    list1 = new ListNode(1);
    prev = list1;
    for (int i = 2; i <= 5; ++i)
    {
        prev->next = new ListNode(i);
        prev = prev->next;
    }
    printListNode(list1);

    ListNode *reversed = sol.reverseList(list1);
    printListNode(reversed);

    return 0;
}