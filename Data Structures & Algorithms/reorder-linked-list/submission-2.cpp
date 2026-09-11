/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode* mid = nullptr;
        {
            ListNode* fast = head;
            ListNode* slow = head;
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            mid = slow;
        }

        ListNode* reorderedHead = mid->next;
        mid->next = nullptr;
        {
            ListNode* next = reorderedHead->next;
            ListNode* curr = reorderedHead;
            reorderedHead->next = nullptr;
            while (next)
            {
                curr = next;
                next = next->next;
                curr->next = reorderedHead;
                reorderedHead = curr;
            }
        }

        while (head && reorderedHead)
        {
            ListNode* headNext = head->next;
            ListNode* reorderedNext = reorderedHead->next;

            head->next = reorderedHead;
            reorderedHead->next = headNext;

            head = headNext;
            reorderedHead = reorderedNext;
        }
    }
};
