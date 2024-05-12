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
#include <set>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
          return head;
        }
        set<int> vals;
        ListNode* node = head->next;
        ListNode* prev = head;
        vals.insert(head->val);

        while (node != nullptr) {
          if (vals.contains(node->val)) {
            prev->next = node->next;
            node = node->next;
          } else {
            vals.insert(node->val);
            prev = node;
            node = node->next;
          }
        }
        return head;
    }
};