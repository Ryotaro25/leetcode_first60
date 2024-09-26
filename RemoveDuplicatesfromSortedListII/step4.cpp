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
        std::map<int, int> val_to_count;
        auto node = head;
        while (node) {
            ++val_to_count[node->val];
            node = node->next;
        }

        ListNode dummy_head;
        node = &dummy_head;
        for (auto [val, count] : val_to_count) {
            if (count == 1) {
                node->next = new ListNode(val);
                node = node->next;
            }
        }

        return dummy_head.next;
    }
};
