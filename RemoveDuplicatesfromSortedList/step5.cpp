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
  ListNode* deleteDuplicates(ListNode* head) {
    set<int> unique_vals;
    ListNode* node = head;
    while (node) {
      unique_vals.insert(node->val);
      node = node->next;
    }

    ListNode* new_head = new ListNode();
    node = new_head;
    for (auto val : unique_vals) {
      node->next = new ListNode(val);
      node = node->next;
    }

    return new_head->next;;
  }
};
