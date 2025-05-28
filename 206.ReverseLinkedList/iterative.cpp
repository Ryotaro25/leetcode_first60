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
    ListNode* reverseList(ListNode* head) {
        ListNode* next_node;
        ListNode* previous_node = nullptr;

        while (head) {
            next_node = head->next;
            head->next = previous_node;
            previous_node = head;
            head = next_node;
        }
        return previous_node;
    }
};