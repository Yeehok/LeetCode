class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto *real_head = new ListNode(0);
        real_head->next = head;

        ListNode *p;
        ListNode *q = real_head;
        ListNode *r;
        ListNode *ck_point;

        bool end = false;
        while (!end) {
            p = q;
            q = q->next;
            r = p;

            if (k <= 1) break;
            ck_point = p;
            for (int i = 0; i < k; ++i) {
                if (ck_point->next == nullptr) {
                    end = true;
                    break;
                }
                ck_point = ck_point->next;
            }

            for (int i = 1; i < k && !end; ++i) {
                if (q->next == nullptr) {
                    end = true;
                    break;
                }
                r = q->next;

                q->next = r->next;
                r->next = p->next;
                p->next = r;
            }
        }

        ListNode *ans = real_head->next;
        delete real_head;
        real_head = nullptr;
        return ans;
    }
};
