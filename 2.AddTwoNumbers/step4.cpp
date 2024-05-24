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
        ListNode* traverse = dummy_node;
        int carry = 0;

        if (list1->next == nullptr && list2->next == nullptr) {
            traverse->next = new ListNode(0);
        }

        while (list1->next || list2->next) {
            int sum = list1->val + list2->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            
            traverse->next = new ListNode(digit);
            traverse = traverse->next;

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
 
        int sum = list1->val + list2->val + carry;
        bool has_carry = false;
        if (sum >= 10) {
            carry /= 10;
            sum %= 10;
            has_carry = true;
        }
        traverse->next = new ListNode(sum);
        traverse = traverse->next;
        if (has_carry) {
            traverse->next = new ListNode(1);
        }

        return dummy_node->next;
    }
};