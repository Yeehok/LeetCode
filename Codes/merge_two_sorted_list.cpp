class Solution {
public:
    void InsertLToP(ListNode **l, ListNode **p) {
        (*p)->next = (*l);
        (*l) = (*l)->next;
        (*p) = (*p)->next;
        (*p)->next = nullptr;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        auto *ans = new ListNode(0);

        ListNode *p = ans;
        while (true) {
            if (l1 == nullptr && l2 == nullptr) break;

            if (l2 == nullptr) {
                InsertLToP(&l1, &p);
            }
            else if (l1 == nullptr) {
                InsertLToP(&l2, &p);
            }
            else if (l1->val <= l2->val) {
                InsertLToP(&l1, &p);
            }
            else if (l2->val <= l1->val) {
                InsertLToP(&l2, &p);
            }
        }

        return ans->next;
    }
};