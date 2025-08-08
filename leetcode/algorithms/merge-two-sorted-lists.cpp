
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *mlist = nullptr;
        if (list1 == nullptr and list2 == nullptr)
            mlist = list1;
        else if (list1 == nullptr)
            mlist = list2;
        else if (list2 == nullptr)
            mlist = list1;
        else
        {
            ListNode *mlistitr = mlist;
            while (list1 != nullptr and list2 != nullptr)
            {
                if (list2 == nullptr or list1->val <= list2->val)
                {
                    if (mlist != nullptr)
                    {
                        mlistitr->next = list1;
                        mlistitr = mlistitr->next;
                    }
                    else
                    {
                        mlist = list1;
                        mlistitr = mlist;
                    }
                    list1 = list1->next;
                }
                else
                {
                    if (mlist != nullptr)
                    {
                        mlistitr->next = list2;
                        mlistitr = mlistitr->next;
                    }
                    else
                    {
                        mlist = list2;
                        mlistitr = mlist;
                    }
                    list2 = list2->next;
                }
            }

            while (list1 != nullptr)
            {
                if (mlist != nullptr)
                {
                    mlistitr->next = list1;
                    mlistitr = mlistitr->next;
                }
                else
                {
                    mlist = list1;
                    mlistitr = mlist;
                }
                list1 = list1->next;
            }

            while (list2 != nullptr)
            {
                if (mlist != nullptr)
                {
                    mlistitr->next = list2;
                    mlistitr = mlistitr->next;
                }
                else
                {
                    mlist = list2;
                    mlistitr = mlist;
                }
                list2 = list2->next;
            }
        }

        return mlist;
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
    ListNode *list1, *list2, *prev;
    list1 = new ListNode(1);
    prev = list1;
    for (int i = 2; i <= 5; ++i)
    {
        prev->next = new ListNode(i);
        prev = prev->next;
    }
    printListNode(list1);

    list2 = new ListNode(1);
    prev = list2;
    for (int i = 2; i <= 10; i += 2)
    {
        prev->next = new ListNode(i);
        prev = prev->next;
    }
    printListNode(list2);

    ListNode *merged = sol.mergeTwoLists(list1, list2);
    printListNode(merged);

    return 0;
}