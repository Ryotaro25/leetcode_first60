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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
          return l2;
        } else if (l2 == NULL) {
          return l1;
        }
        int temp = l1->val + l2->val;
        ListNode* node = new ListNode(temp % 10);
        node->next = addTwoNumbers(l1->next, l2->next);
        if (temp >= 10) {
          node->next = addTwoNumbers(node->next, new ListNode(1));
        }

        return node;
    }
};