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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        std::size_t length{};
        {
            ListNode* node = head;
            while (node)
            {
                ++length;
                node = node->next;
            }
        }

        if (length < n)
            return nullptr;

        if (length == n)
            return head->next;

        std::size_t removeAt{length - n};
        ListNode* node = head;
        for (std::size_t i{}; i < length && node; ++i)
        {
            if (i == removeAt - 1)
            {
                node->next = node->next->next;
                break;
            }

            node = node->next;
        }

        return head;
    }
};
