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
        ListNode* node = head;
        std::map<int, int> valsCnt;
        while (node) {
          valsCnt[node->val] += 1;
          node = node->next;
        }

        ListNode* newNode = new ListNode();
        ListNode* current = newNode;
        for (auto i : valsCnt) {
          if (i.second == 1) {
            ListNode* temp = new ListNode(i.first);
            current->next = temp;
            current = current->next;
          }
        }
        return newNode->next;
    }
};