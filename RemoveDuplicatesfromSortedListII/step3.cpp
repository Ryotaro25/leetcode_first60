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
            valsCnt[node->val] += 1;
            node = node->next;
        }

        ListNode* newNode = new ListNode();
        node = newNode;
        for (auto i : valsCnt) {
            if (i.second == 1) {
                ListNode* temp = new ListNode(i.first);
                node->next = temp;
                node = node->next;
            }
        }

        return newNode->next;
    }
};