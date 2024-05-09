/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <map>

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode* node = head;
      std::map<ListNode*, bool> nodeMap; 

      while (node) {
        if (nodeMap[node]) {
          return true;
        }

        nodeMap[node] = true;
        node = node->next;
      }

      return false;
    }
};