// https://leetcode.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a -> val > b -> val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)>pq(cmp);
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            head -> next = new ListNode(x -> val);
            head = head -> next;
            if (x -> next) {
                pq.push(x -> next);
            }
        }

        return dummy -> next;
    }
};