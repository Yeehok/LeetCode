class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        ListNode prehead(0);
        prehead.next = head;
        ListNode *p = &prehead;
        int n = 0;
        while (p->next != nullptr) {
            p = p->next;
            ++n;
        }
        p->next = head;
        k %= n;
        p = &prehead;

        for (int i = 0; i < n - k; ++i) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;

        return head;
    }
};
