class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode *p = pre_head;
        ListNode *q = pre_head;

        int jump_times = 0;
        while (true) {
            if (p->next == nullptr) {
                p = q->next;
                if (p == nullptr) {
                    q->next = nullptr;
                } else {
                    q->next = p->next;
                    delete p;
                    p = nullptr;
                }
                break;
            }
            p = p->next;
            if (jump_times >= n) {
                q = q->next;
            }
            ++jump_times;
        }

        return pre_head->next;
    }
};
