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

      int num_nodes = 1;
      map<int, ListNode*> index_to_node;
      ListNode* node = head;
      while (node) {
        index_to_node[num_nodes] = node;
        num_nodes++;
        node = node->next;
      }

      ListNode dummy_head;
      node = &dummy_head;

      int index = 1;
      while (index < left) {
        node->next = index_to_node[index];
        index++;
        node = node->next;
      }

      index = right;
      while (index >= left) {
        node->next = index_to_node[index];
        index--;
        node = node->next;
      }

      index = right + 1;
      while (index < num_nodes) {
        node->next = index_to_node[index];
        index++;
        node = node->next;
      }
      node->next = nullptr;

      return dummy_head.next;
    }
  };
