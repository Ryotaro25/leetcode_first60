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
#include <stack>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        stack<ListNode*> vals;
        while (head) {
            vals.push(head);
            head = head->next;
        }

        ListNode* reverse_node = new ListNode();
        ListNode* node = reverse_node;
        while (!vals.empty()) {
            node->next = vals.top();
            vals.pop();
            node = node->next;
        }
        node->next = nullptr;

        return reverse_node->next;
    }
};