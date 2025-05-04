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

      ListNode dummy_head;
      dummy_head.next = head;
      ListNode* node = &dummy_head;

      // 探索中のnodeをleftの直前まで移動
      for (int i = 0; i < left - 1; i++) {
        node = node->next;
      }

      // leftからrightの間を逆順に繋ぐため直前のnodeを記録
      ListNode* prev_left = node;

      // 探索中のnodeをleftの位置へ移動
      node = node->next;
      stack<ListNode*> reversed_nodes;
      for (int i = left; i <= right; i++) {
        reversed_nodes.push(node);
        node = node->next;
      }

      // right + 1にあるnodeを記録
      ListNode* current_node = node;
      while (!reversed_nodes.empty()) {
        prev_left->next = reversed_nodes.top();
        prev_left = prev_left->next;
        reversed_nodes.pop();
      }

      prev_left->next = current_node;

      return dummy_head.next;
    }
};
