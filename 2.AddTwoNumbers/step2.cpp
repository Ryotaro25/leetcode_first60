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
        auto current_node = &dummy_node;
        int carry_up = 0;

        while (l1 || l2 || carry_up != 0) {
            int li1_digit, li2_digit;
            if (l1) {
                li1_digit = l1->val;
            } else {
                li1_digit = 0;
            }

            if (l2) {
                li2_digit = l2->val;
            } else {
                li2_digit = 0;
            }

            int temp = li1_digit + li2_digit + carry_up;
            int digit = temp % 10;
            carry_up = temp / 10;

            current_node->next = new ListNode(digit);
            current_node = current_node->next;
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