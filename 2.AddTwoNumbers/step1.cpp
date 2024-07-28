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
        ListNode* node1 = l1;
        ListNode* node2 = l2;

        ListNode* dummy_node = new ListNode();
        ListNode* current_node = dummy_node;
        int carry_up = 0;

        if (node1->next == nullptr && node2->next == nullptr) {
            current_node->next = new ListNode(0);
        }

        while (node1->next || node2->next) {
            int temp = node1->val + node2->val + carry_up;
            if (temp > 9) {
                carry_up = 1;
                temp -= 10;
            } else {
                carry_up = 0;
            }
            current_node->next = new ListNode(temp);
            current_node = current_node->next;

            if (node1->next) {
                node1 = node1->next;
            } else {
                node1->val = 0;
            }
            if (node2->next) {
                node2 = node2->next; 
            } else {
                node2->val = 0;
            }
            
        }
 
        int temp = node1->val + node2->val + carry_up;
        bool isCarry = false;
        if (temp > 9) {
            carry_up = 1;
            temp -= 10;
            isCarry = true;
        } else {
            carry_up = 0;
        }
        current_node->next = new ListNode(temp);
        current_node = current_node->next;
        if (isCarry) {
            current_node->next = new ListNode(1);
        }

        return dummy_node->next;
    }
};