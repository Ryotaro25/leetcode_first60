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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (!head) {
        return nullptr;
      }

      int node_count = 1;
      map<int, ListNode*> index_to_node;
      auto node = head;
      while (node) {
        index_to_node[node_count] = node;
        node_count++;
        node = node->next;
      }

      ListNode dummy_head;
      node = &dummy_head;

      int current_index = 1;
      while (current_index < left) {
        node->next = index_to_node[current_index];
        current_index++;
        node = node->next;
      }

      current_index = right;
      while (current_index >= left) {
        node->next = index_to_node[current_index];
        current_index--;
        node = node->next;
      }

      current_index = right + 1;
      while (current_index < node_count) {
        node->next = index_to_node[current_index];
        current_index++;
        node = node->next;
      }
      node->next = nullptr;

      return dummy_head.next;
    }
  };
