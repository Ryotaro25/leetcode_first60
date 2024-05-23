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
        ListNode* dummy_node = new ListNode();
        ListNode* current_node = dummy_node;
        int carry = 0;

        if (list1->next == nullptr && list2->next == nullptr) {
            current_node->next = new ListNode(0);
        }

        while (list1->next || list2->next) {
            int number = list1->val + list2->val + carry;
            carry = number / 10;
            int digit = number % 10;
            
            current_node->next = new ListNode(digit);
            current_node = current_node->next;

            if (list1->next) {
                list1 = list1->next;
            } else {
                list1->val = 0;
            }
            if (list2->next) {
                list2 = list2->next; 
            } else {
                list2->val = 0;
            }
        }
 
        int number = list1->val + list2->val + carry;
        bool has_carry = false;
        if (number >= 10) {
            carry /= 10;
            number %= 10;
            has_carry = true;
        }
        current_node->next = new ListNode(number);
        current_node = current_node->next;
        if (has_carry) {
            current_node->next = new ListNode(1);
        }

        return dummy_node->next;
    }
};