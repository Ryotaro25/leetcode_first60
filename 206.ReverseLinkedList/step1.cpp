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

        ListNode* node = head;
        stack<int> vals;
        while (node) {
            vals.push(node->val);
            node = node->next;
        }

        ListNode* reverse_node = new ListNode();
        node = reverse_node;
        while (!vals.empty()) {
            node->next =  new ListNode(vals.top());
            vals.pop();
            node = node->next;
        }

        return reverse_node->next;
    }
};