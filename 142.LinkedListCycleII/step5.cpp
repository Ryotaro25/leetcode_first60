/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    set<ListNode*> visited_nodes;
    ListNode* node = head;

    while (node) {
      if (visited_nodes.contains(node)) {
        return node;
      }
      visited_nodes.insert(node);
      node = node->next;
    }

    return nullptr;
  }
};
