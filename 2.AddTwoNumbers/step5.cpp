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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
          return NULL;
        }
        int sum = 0;
        if (list1) {
          sum += list1->val;
          list1 = list1->next;
        }
        if (list2) {
          sum += list2->val;
          list2 = list2->next;
        }
        ListNode* node = new ListNode(sum % 10);
        node->next = addTwoNumbers(list1, list2);
        if (sum >= 10) {
          auto carry_node = make_unique<ListNode>(1);
          node->next = addTwoNumbers(node->next, carry_node.get());
        }
        return node;
    }
};