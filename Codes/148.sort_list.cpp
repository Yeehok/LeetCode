/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        vector<int> arr;

        ListNode *p = head;
        while (p != NULL) {
            arr.emplace_back(p->val);
            p = p->next;
        }

        sort(arr.begin(), arr.end());

        p = head;
        for (const auto i : arr) {
            p->val = i;
            p = p->next;
        }
        return head;
    }
};
