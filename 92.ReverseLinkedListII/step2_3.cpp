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

      // leftの位置のnode
      ListNode* reversed = node->next;

      for (int i = left; i < right; i++) {
        // reversedの次を取り出し、reversedの次に、次の次のnodeを繋げることで
        // 取り出したnodeを一時的にリストから外す
        ListNode* next_node = reversed->next;
        reversed->next = next_node->next;
        // 初回はnode->nextはleftの先頭にいる
        next_node->next = node->next;
        node->next = next_node;
      }
      return dummy_head.next;
    }
};
