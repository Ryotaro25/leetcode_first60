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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }

        ListNode* node = head;
        stack<int> nodes;
        while (node) {
            nodes.push(node->val);
            node = node->next;
        }

        ListNode reverse_node = ListNode();
        node = &reverse_node;
        while (!nodes.empty()) {
            node->next =  new ListNode(nodes.top());
            nodes.pop();
            node = node->next;
        }

        return reverse_node.next;
    }
};