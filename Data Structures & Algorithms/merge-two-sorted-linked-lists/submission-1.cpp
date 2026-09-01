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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode start;
        ListNode* current = &start;

        while (list1 && list2)
        {
            ListNode*& min = list1->val < list2->val ? list1 : list2;
            current->next = min;
            min = min->next;

            current = current->next;
        }

        current->next = list1 ? list1 : list2;

        return start.next;
    }
};
