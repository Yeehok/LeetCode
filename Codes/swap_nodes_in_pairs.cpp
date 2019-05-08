class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *pre_head = new ListNode(0);
        pre_head->next = head;

        ListNode *p = pre_head;
        ListNode *q = pre_head;
        while (p != nullptr
        && p->next != nullptr
        && p->next->next != nullptr) {
            q = p->next;

            p->next = q->next;
            q->next = p->next->next;
            p->next->next = q;

            p = p->next->next;
        }

        return pre_head->next;
    }
};
