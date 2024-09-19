/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_set>
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodeSet;
        ListNode* node = head;

        while (node) {
            if(nodeSet.contains(node)) {
                return node;
            }
            nodeSet.insert(node);
            node = node->next;
        }

        return nullptr;
    }
};