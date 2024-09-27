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
  ListNode* addTwoNumbers(ListNode* first_node, ListNode* second_node) {
    ListNode new_head;
    ListNode* node = &new_head;

    int carry = 0;
    int digit = 0;
    while (first_node || second_node || carry) {
      int sum = carry;
      if (first_node) {
        sum += first_node->val;
        first_node = first_node->next;
      }
      if (second_node) {
        sum += second_node->val;
        second_node = second_node->next;
      }

      carry = sum / 10;
      digit = sum % 10;

      node->next = new ListNode(digit);
      node = node->next;
    }

    return new_head.next;
  }
};
