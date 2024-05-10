/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> nodeSet;
        ListNode* node = head;

        while (node) {
          // findで見つけられない場合はendを返す(=サイクルなし)
          if (nodeSet.find(node) != nodeSet.end()) {
            return true;
          }
          nodeSet.insert(node);
          node = node->next;
        }
        return false;
    }
};