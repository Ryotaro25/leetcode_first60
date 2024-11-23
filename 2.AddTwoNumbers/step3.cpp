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
        ListNode dummy_node;
        auto node = &dummy_node;
        int carry_up = 0;

        while (l1 || l2 || carry_up == 1) {
            int l1_digit, l2_digit;
            if (l1) {
                l1_digit = l1->val;
            } else {
                l1_digit = 0;
            }
            if (l2) {
                l2_digit = l2->val;
            } else {
                l2_digit = 0;
            }

            int temp = l1_digit + l2_digit + carry_up;
            int digit = temp % 10;
            carry_up = temp / 10;

            node->next = new ListNode(digit);
            node = node->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        return dummy_node.next;
    }
};