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
  ListNode* deleteDuplicates(ListNode* head) {
    auto node = head;
    map<int, int> vals_to_cnt;
    while (node) {
      vals_to_cnt[node->val]++;
      node = node->next;
    }

    ListNode new_head;
    node = &new_head;
    for (auto [val, cnt] : vals_to_cnt) {
      if (cnt == 1) {
        node->next = new ListNode(val);
        node = node->next;
      }
    }

    return new_head.next;
  }
};
