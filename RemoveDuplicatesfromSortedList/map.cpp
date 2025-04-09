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
      if (!head) {
        return nullptr;
      }

      map<int, ListNode*> vals_to_nodes;
      ListNode* node = head;
      while (node) {
        vals_to_nodes[node->val] = node;
        node = node->next;
      }

      ListNode dummy_head;
      ListNode* dummy = &dummy_head;
      for (auto [val, node] : vals_to_nodes) {
        dummy->next = node;
        dummy = dummy->next;
      }
      return dummy_head.next;
    }
  };
