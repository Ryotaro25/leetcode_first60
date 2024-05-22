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

#include <map>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        std::map<int, int> valsCnt;
        ListNode* node = head;
        while (node) {
          if (valsCnt[node->val] == 0) {
            valsCnt[node->val] = 1;
          } else {
            valsCnt[node->val] += 1;
          }
          node = node->next;
        }

        ListNode* newNode = new ListNode();
        ListNode* nodePointer = newNode;
        for (auto i = valsCnt.begin(); i != valsCnt.end(); i++) {
          if (i->second == 1) {
            ListNode* temp = new ListNode(i->first);
            nodePointer->next = temp;
            nodePointer = nodePointer->next;
          }
        }
        return newNode->next;
    }
};