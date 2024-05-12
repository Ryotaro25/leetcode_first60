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
        set<int> nodeSet;
        ListNode* node = head->next;
        ListNode* prev = head;
        nodeSet.insert(head->val);
        
        while (node != nullptr) {
          if (nodeSet.contains(node->val)) {
            prev->next = node->next;
            node = node->next;
          } else {
            nodeSet.insert(node->val);
            prev = node;
            node = node->next;
          }
        }
        return head;
    }
};