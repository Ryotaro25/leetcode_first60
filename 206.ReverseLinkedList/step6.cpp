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
      return nullptr;
    }

    stack<ListNode*> nodes;
    ListNode* node = head;
    while (node) {
      nodes.push(node);
      node = node->next;
    }

    ListNode new_head;
    node = &new_head;
    while (!nodes.empty()) {
      node->next = nodes.top();
      node = node->next;
      nodes.pop();
    }
    node->next = nullptr;
    return new_head.next;
  }
};
